import tkinter as tk
import random

# Set up the main window
# Window pixels: 64x64
root = tk.Tk()
root.title("Pixel Raiders -- Loading...")
root.geometry("600x400")
root.configure(bg="black")

main_sprite = [
    ["black", "black", "yellow", "black", "black"],
    ["black", "#FFB840", "orange", "#FFB840", "black"],
    ["yellow", "orange", "red", "orange", "yellow"],
    ["black", "#FFB840", "orange", "#FFB840", "black"],
    ["black", "0 1", "yellow", "0 1", "black"],
    ["black", "1 2", "black", "1 2", "black"],
    ["black", "2 3", "black", "2 3", "black"],
    ["black", "3 0", "black", "3 0", "black"],
]
def parse_color(cell_content, loop_num):
    if " " in cell_content:
        a, b = map(int, cell_content.split())
        return "gray" if loop_num in (a, b) else "black"
    return cell_content


click = False
def ask_before_exit():
    global click
    if click:
        return
    click = True
    exit_window = tk.Toplevel(root)
    exit_window.title("Confirm Exit")
    exit_window.geometry("400x200")
    exit_window.configure(bg="black")

    def on_closing():
        global click
        click = False
        exit_window.destroy()
    exit_window.protocol("WM_DELETE_WINDOW", on_closing)
    label = tk.Label(exit_window, text="Are you sure you want to QUIT?", font=("Tiny5", 16), fg="red", bg="black")
    label.pack(pady=10)
    additional_label = tk.Label(exit_window, text="Keep the fun going and press No now!", font=("Tiny5", 12), fg="green", bg="black")

    additional_label.pack()


    yes_button = tk.Button(exit_window, text="Yes", font=("Tiny5", 14), fg="red", bg="black", command=exit)
    yes_button.pack(side="left", padx=20)

    no_button = tk.Button(exit_window, text="No", font=("Tiny5", 14), fg="green", bg="black", command=on_closing)
    no_button.pack(side="right", padx=20)
root.protocol("WM_DELETE_WINDOW", ask_before_exit)


def gamestart(root):

    def modeselect():
        root.title("Pixel Raiders -- Please select a mode")

        for widget in root.winfo_children():
            widget.destroy()

        background = tk.Frame(root, bg="black")
        background.place(relwidth=1, relheight=1)
        home = tk.Button(background, text="HOME", font=("Tiny5", 20), fg="blue", bg="black", command=lambda: main(root))
        home.place(relx=0, rely=0)
        #make a mode selection screen
        label = tk.Label(background, text="SELECT MODE", font=("Tiny5", 36), fg="white", bg="black")
        label.place(relx=0.5, rely=0.2, anchor="center")
        dash = tk.Button(background, text="DASH MODE", font=("Tiny5", 48), fg="green", bg="black", command=dash_mode)
        dash.place(relx=0.5, rely=0.4, anchor="center")
        quest = tk.Button(background, text="QUEST MODE", font=("Tiny5", 48), fg="purple", bg="black", command=quest_mode)
        quest.place(relx=0.5, rely=0.6, anchor="center")

    def dash_mode():
        root.title("Pixel Raiders -- Play Dash Mode")
        for widget in root.winfo_children():
            widget.destroy()
        background = tk.Frame(root, bg="black")
        background.place(relwidth=1, relheight=1)
        click2 = False
        def ask_before_mode():
            #confirmation before leaving game to mode selector
            global click
            nonlocal click2
            if click or click2:
                return
            click2 = True
            exit_window = tk.Toplevel(root)
            exit_window.title("Confirm Exit")
            exit_window.geometry("400x200")
            exit_window.configure(bg="black")
            def on_closing():
                global click
                nonlocal click2
                click = False
                click2 = False
                exit_window.destroy()
            exit_window.protocol("WM_DELETE_WINDOW", on_closing)
            label = tk.Label(exit_window, text="Are you sure you want to exit the game?", font=("Tiny5", 16), fg="red", bg="black")
            label.pack(pady=10)
            additional_label = tk.Label(exit_window, text="Your progress will be lost!", font=("Tiny5", 12), fg="green", bg="black")
            additional_label.pack()
            yes_button = tk.Button(exit_window, text="Yes", font=("Tiny5", 14), fg="red", bg="black", command=modeselect)
            yes_button.pack(side="left", padx=20)
            no_button = tk.Button(exit_window, text="No", font=("Tiny5", 14), fg="green", bg="black", command=on_closing)
            no_button.pack(side="right", padx=20)
        home = tk.Button(background, text="MENU", font=("Tiny5", 20), fg="red", bg="black", command=ask_before_mode)
        home.place(relx=0, rely=0)
        time = tk.Label(background, text="TIME:", font=("Tiny5", 20), fg="white", bg="black")
        time.place(relx=0.2, rely=0, anchor="n")
        pausevar = False
        def pause_game():
            nonlocal pausevar
            if pausevar:
                pausevar = False
                pause.config(text="PAUSE")
                change_sprite()
            else:
                pausevar = True
                pause.config(text="RESUME")
        pause = tk.Button(background, text="PAUSE", font=("Tiny5", 20), fg="red", bg="black", command=pause_game)
        pause.place(relx=0.8, rely=0, anchor="n")
        # Initialize game variables
        obstacles = [[0 for _ in range(64)] for _ in range(59)]
        flame_x = 0.5
        flame_speed = 1000  # Initial speed in milliseconds
        countdown = 10  # Countdown for gap creation
        starting_plc = 0  # Starting position for the gap
        mode = 0  # Mode for gap movement, can be -1, 0, or 1
        click = False  # Global click variable to prevent multiple clicks
        # Initialize static obstacle and sprite containers
        obstacle_refs = [[None for _ in range(64)] for _ in range(59)]
        sprite_refs = [[None for _ in range(5)] for _ in range(8)]

        # Create obstacle grid once
        for i in range(59):
            for j in range(64):
                cell = tk.Frame(background, bg="black")
                cell.place(relx=j/64, rely=(i+1)/60, relwidth=0.015625, relheight=0.0166666666667)
                obstacle_refs[i][j] = cell

        # Create the main sprite grid once
        sprite_container = tk.Frame(background, bg="black")
        sprite_container.place(relx=flame_x, rely=0.75, relwidth=0.078125, relheight=0.125, anchor="center")
        for i in range(8):
            for j in range(5):
                cell = tk.Frame(sprite_container, bg="black")
                cell.place(relx=j/5, rely=i/8, relwidth=0.625, relheight=0.625)
                sprite_refs[i][j] = cell

        loop_num = 1

        def change_sprite():
            nonlocal loop_num, flame_x, flame_speed, pausevar, countdown, starting_plc

            # Update sprite colors
            for i, row in enumerate(main_sprite):
                for j, cell in enumerate(row):
                    color = parse_color(cell, loop_num)
                    sprite_refs[i][j].config(bg=color)

            loop_num = (loop_num + 1) % 4

            # Shift obstacles down
            for i in range(58, 0, -1):
                obstacles[i] = obstacles[i-1][:]

            if countdown == 0:
                gap_width = 9
                obstacles[0] = [1] * 64
                for i in range(starting_plc, starting_plc + gap_width):
                    if 0 <= i < 64:
                        obstacles[0][i] = 0

                mode = random.randint(-10, 10)
                starting_plc += mode
                if starting_plc < 0:
                    starting_plc = 0
                elif starting_plc > 64 - gap_width:
                    starting_plc = 64 - gap_width
                starting_plc = max(0, min(starting_plc, 64 - gap_width))
                countdown = 10
            else:
                countdown -= 1

            # Update obstacle display
            for i in range(59):
                for j in range(64):
                    color = "blue" if obstacles[i][j] == 1 else "black"
                    obstacle_refs[i][j].config(bg=color)

            if not pausevar:
                # Slowdown limiter
                flame_speed = max(250, flame_speed - 1)
                background.after(flame_speed, change_sprite)

        background.after(1001, change_sprite)

    def quest_mode():
        root.title("Pixel Raiders -- Play Quest Mode")
        for widget in root.winfo_children():
            widget.destroy()
        background = tk.Frame(root, bg="black")
        background.place(relwidth=1, relheight=1)
        click2 = False
        def ask_before_mode():
            #confirmation before leaving game to mode selector
            global click
            nonlocal click2
            if click or click2:
                return
            click2 = True
            exit_window = tk.Toplevel(root)
            exit_window.title("Confirm Exit")
            exit_window.geometry("400x200")
            exit_window.configure(bg="black")
            def on_closing():
                global click
                nonlocal click2
                click = False
                click2 = False
                exit_window.destroy()
            exit_window.protocol("WM_DELETE_WINDOW", on_closing)
            label = tk.Label(exit_window, text="Are you sure you want to exit the game?", font=("Tiny5", 16), fg="red", bg="black")
            label.pack(pady=10)
            additional_label = tk.Label(exit_window, text="Your progress will be lost!", font=("Tiny5", 12), fg="green", bg="black")
            additional_label.pack()
            yes_button = tk.Button(exit_window, text="Yes", font=("Tiny5", 14), fg="red", bg="black", command=modeselect)
            yes_button.pack(side="left", padx=20)
            no_button = tk.Button(exit_window, text="No", font=("Tiny5", 14), fg="green", bg="black", command=on_closing)
            no_button.pack(side="right", padx=20)
        home = tk.Button(background, text="MENU", font=("Tiny5", 20), fg="red", bg="black", command=ask_before_mode)
        home.place(relx=0, rely=0)
        time = tk.Label(background, text="TIME:", font=("Tiny5", 20), fg="white", bg="black")
        time.place(relx=0.2, rely=0, anchor="n")



        pause = tk.Button(background, text="PAUSE", font=("Tiny5", 20), fg="red", bg="black", command=lambda: None) # a placeholder
        pause.place(relx=0.8, rely=0, anchor="n")




    modeselect()

def main(root):
    root.title("Pixel Raiders -- Main Menu")

    for widget in root.winfo_children():
        widget.destroy()

    background = tk.Frame(root, bg="black")
    background.place(relwidth=1, relheight=1)

    label = tk.Label(background, text="PIXEL RAIDERS", font=("Tiny5", 36), fg="white", bg="black")
    label.place(relx=0.5, rely=0.2, anchor="center")

    play = tk.Button(background, text="PLAY!", font=("Tiny5", 48), fg="green", bg="black", command=lambda: gamestart(root))
    play.place(relx=0.5, rely=0.5, relwidth=0.25, relheight=0.18, anchor="center")


    quit = tk.Button(background, text="QUIT?", font=("Tiny5", 20), fg="red", bg="black", command=ask_before_exit)
    quit.place(relx=0, rely=0)

main(root)

# Start the game loop (GUI display)
root.mainloop()
