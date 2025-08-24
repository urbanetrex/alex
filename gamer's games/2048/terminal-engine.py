# 2048 terminal engine
# It might feel sick to have 2048 on the humble terminal, but it is a fun challenge.

import os
import random
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

_errors1 = ["Enter a command:", "Invalid command. Please enter W, A, S, D, Q, or I for more info: ", "No tiles moved! Try a different direction: "]

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
    # ANSI background (bg) and foreground (fg) color codes
    colors = {
        0:     ('\033[48;5;250m', '\033[38;5;240m'),  # Light gray bg, dark text
        2:     ('\033[48;5;245m', '\033[38;5;15m'),   # Gray bg, **white text**
        4:     ('\033[48;5;131m', '\033[38;5;15m'),   # Maroon bg
        8:     ('\033[48;5;196m', '\033[38;5;15m'),   # Red
        16:    ('\033[48;5;202m', '\033[38;5;15m'),   # Orange
        32:    ('\033[48;5;226m', '\033[38;5;0m'),    # Yellow (black text)
        64:    ('\033[48;5;220m', '\033[38;5;0m'),    # Gold
        128:   ('\033[48;5;154m', '\033[38;5;0m'),    # Lime
        256:   ('\033[48;5;34m',  '\033[38;5;15m'),   # Green
        512:   ('\033[48;5;51m',  '\033[38;5;0m'),    # Cyan
        1024:  ('\033[48;5;33m',  '\033[38;5;15m'),   # Blue
        2048:  ('\033[48;5;129m', '\033[38;5;15m'),   # Purple
    }

    bg, fg = colors.get(num, ('\033[48;5;235m', '\033[38;5;15m'))  # fallback
    reset = '\033[0m'
    return f"{bg}{fg}[{str(num).rjust(4)}]{reset}"

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
        print("Entered", previous)
    if check_won():
        print("YOU WON!")

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
    error_code = 0
    pop_random()  # Start with a random number
    while True:
        display()
        command = input(_errors1[error_code]).strip().upper()
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
                error_code = 0
            else:
                error_code = 2

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("Game over! No more valid moves.")
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
                error_code = 0
            else:
                error_code = 2

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("Game over! No more valid moves.")
                break
        elif command == 'A':
            previous = 'A'
            before = copy.deepcopy(cells)
            for i in range(4):
                cells[i] = compress_and_merge(cells[i])
            
            if not boards_equal(before, cells):
                pop_random()
                error_code = 0
            else:
                error_code = 2

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("Game over! No more valid moves.")
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
                error_code = 0
            else:
                error_code = 2

            # Always check game over, even if no tiles moved
            if check_game_over():
                display()
                print("Game over! No more valid moves.")
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
            error_code = 0
            continue
        else:
            previous = command
            error_code = 1
            continue
        if check_won():
            display()
            break

if __name__ == "__main__":
    print()
    print("Welcome to 2048 in the terminal!")
    print("Use W (up), S (down), A (left), D (right) to move tiles.")
    print("Try to reach 2048!")
    print("Press Q to quit, I for instructions.")
    input("Press Enter to start...")
    while True:
        reset_game()
        main()
        print("Play again? (Y/N): ", end='')
        quit_choice = True
        while True:
            choice = input().strip().upper()
            if choice == 'N':
                print("Thanks for playing!")
                print()
                break
            elif choice == 'Y':
                quit_choice = False
                break
            else:
                print("Please enter Y or N: ", end='')
        if quit_choice:
            break