# 2048 terminal engine
# It might feel sick to have 2048 on the humble terminal, but it is a fun challenge.

import os
import random
import time
import copy

'''
display - rendering:

------- PLAY: 2048 -------
 [2048][ 512][ 64 ][  8 ]
 [ 32 ][  4 ][  2 ][  1 ]
 [ 16 ][ 128][ 256][1024]
 [    ][    ][    ][    ]
 ENTERED W
 ENTER A COMMAND: S
 
'''

def clear_screen():
    """Clear the terminal screen."""
    os.system('cls' if os.name == 'nt' else 'clear')


def boards_equal(b1, b2):
    return all(b1[i] == b2[i] for i in range(4))

cells = [[0,0,0,0],
         [0,0,0,0],
         [0,0,0,0],
         [0,0,0,0]]
previous = ' '

def check_won():
    """Check if the player has won."""
    global cells
    for row in cells:
        if 2048 in row:
            return True
    return False

def check_blanks():
    '''Output the places where they are blank.'''
    global cells
    blanks = []
    for i in range(4):
        for j in range(4):
            if cells[i][j] == 0:
                blanks.append((i, j))
    return blanks

def num_to_unit(num):
    if num == 0:
        return "[    ]"
    elif num < 10:
        return f"[  {num} ]"
    elif num < 100:
        return f"[ {num} ]"
    elif num < 1000:
        return f"[ {num}]"
    elif num < 10000:
        return f"[{num}]"
    else:
        return "[ ERR]"
    
def pop_random():
    """Pop a random number into a random blank cell, and return True if successful."""
    global cells
    blanks = check_blanks()
    if blanks:
        i, j = random.choice(blanks)
        cells[i][j] = 2 if random.random() < 0.9 else 4
        return True
    return False

def display():
    """Display the current state of the game."""
    global cells
    clear_screen()
    print("------- PLAY: 2048 -------")
    for row in cells:
        print(" ".join(num_to_unit(num) for num in row))
    if previous != ' ':
        print("ENTERED", previous)
    if check_won():
        print("YOU WON!")
    else:
        print("ENTER A COMMAND: ", end='')

def reset_game():
    """Reset the game to the initial state."""
    global cells, previous
    cells = [[0, 0, 0, 0] for _ in range(4)]
    previous = ' '
    pop_random()  # Start with a random number

def check_game_over():
    if check_blanks():
        return False  # There are still empty spaces
    for i in range(4):
        for j in range(4):
            if i < 3 and cells[i][j] == cells[i+1][j]:
                return False
            if j < 3 and cells[i][j] == cells[i][j+1]:
                return False
    return True

def compress_and_merge(line):
    """Compresses non-zero values and merges adjacent equal numbers."""
    line = [num for num in line if num != 0]
    for i in range(len(line) - 1):
        if line[i] == line[i + 1]:
            line[i] *= 2
            line[i + 1] = 0
    line = [num for num in line if num != 0]
    return line + [0] * (4 - len(line))


def main():
    """Main game loop."""
    global previous, cells
    pop_random()  # Start with a random number
    while True:
        display()
        command = input().strip().upper()
        if command == 'W':
            previous = 'W'
            before = copy.deepcopy(cells)

            column_based_cells = [[cells[j][i] for j in range(4)] for i in range(4)]
            for i in range(4):
                new_col = compress_and_merge(column_based_cells[i])
                for j in range(4):
                    column_based_cells[i][j] = new_col[j]
            cells = [[column_based_cells[j][i] for j in range(4)] for i in range(4)]

            if not boards_equal(before, cells):
                pop_random()
            else:
                print("No tiles moved!")

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("GAME OVER! No more valid moves.")
                break
        elif command == 'S':
            previous = 'S'
            before = copy.deepcopy(cells)
            column_based_cells = [[cells[j][i] for j in range(4)] for i in range(4)]
            for i in range(4):
                reversed_col = column_based_cells[i][::-1]
                new_col = compress_and_merge(reversed_col)
                column_based_cells[i] = new_col[::-1]
            cells = [[column_based_cells[j][i] for j in range(4)] for i in range(4)]

            if not boards_equal(before, cells):
                pop_random()
            else:
                print("No tiles moved!")

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("GAME OVER! No more valid moves.")
                break
        elif command == 'A':
            previous = 'A'
            before = copy.deepcopy(cells)
            for i in range(4):
                cells[i] = compress_and_merge(cells[i])
            
            if not boards_equal(before, cells):
                pop_random()
            else:
                print("No tiles moved!")

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("GAME OVER! No more valid moves.")
                break
        elif command == 'D':
            previous = 'D'
            before = copy.deepcopy(cells)
            for i in range(4):
                reversed_row = cells[i][::-1]
                new_row = compress_and_merge(reversed_row)
                cells[i] = new_row[::-1]

            if not boards_equal(before, cells):
                pop_random()
            else:
                print("No tiles moved!")

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("GAME OVER! No more valid moves.")
                break
        elif command == 'Q':
            print("Exiting the game.")
            break
        elif command == 'I':
            print("Instructions: Use W (up), S (down), A (left), D (right) to move tiles. Try to reach 2048!")
            print("Press Q to quit.")
            print("Pressing I will show this info again.")
            print("Press Enter to continue...")
            input()
            continue
        #else:
            #print("Invalid command. Please enter W, A, S, D, Q, or I for more info.")
            #time.sleep(5)
        if check_won():
            display()
            break

if __name__ == "__main__":
    reset_game()
    main()
    print("Thanks for playing 2048 in the terminal!")
    print("Press Enter to exit...")
    input()
    clear_screen()
    print("Goodbye!")
    time.sleep(3)
    clear_screen()
    exit(0)