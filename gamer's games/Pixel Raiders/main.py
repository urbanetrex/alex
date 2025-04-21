import tkinter as tk

# Set up the main window
root = tk.Tk()
root.title("Pixel Raiders -- Loading...")
root.geometry("600x400")
root.configure(bg="black")

main_sprite = [
    ["black", "black", "yellow", "black", "black"],
    ["black", "#FFB840", "#FFA500", "#FFB840", "black"],
    ["yellow", "orange", "red", "orange", "yellow"],
    ["black", "#FFB840", "#FFA500", "#FFB840", "black"],
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
        pause = None
        pausevar = False
        flame_x = 0.5
        flame_speed = 1000
        def ask_before_mode():
            #confirmation before leaving game to mode selector
            global click
            nonlocal click2, pausevar
            pausevar = True
            pause.config(text="RESUME", fg="green")
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
        score = tk.Label(background, text="SCORE:", font=("Tiny5", 20), fg="white", bg="black")
        score.place(relx=0.5, rely=0, anchor="n")

        sprite_container = tk.Frame(background, bg="black")
        sprite_container.place(relx=0.5, rely=0.75, relwidth=0.078125, relheight=0.125, anchor="center")

        # Create the main sprite
        for i, row in enumerate(main_sprite):
            for j, cell in enumerate(row):
                color = parse_color(cell, 0)
                sprite = tk.Frame(sprite_container, bg=color)
                sprite.place(relx=j/5, rely=i/8, relwidth=0.625, relheight=0.625)

        def pause_game():
            nonlocal pausevar, pause

            pausevar = not pausevar
            if pausevar:
                pause.config(text="RESUME", fg="green")
            else:
                pause.config(text="PAUSE", fg="red")
                change_sprite()
            # Pause the game logic here
        pause = tk.Button(background, text="PAUSE", font=("Tiny5", 20), fg="red", bg="black", command=pause_game)
        pause.place(relx=0.8, rely=0, anchor="n")

        # Create the looped sprite
        loop_num = 1
        def change_sprite():
            nonlocal loop_num, sprite_container
            # Clear the previous sprite
            sprite_container.destroy()
            #wait a second before changing the sprite
            sprite_container = tk.Frame(background, bg="black")
            sprite_container.place(relx=0.5, rely=0.75, relwidth=0.078125, relheight=0.125, anchor="center")
            # Create the main sprite
            for i, row in enumerate(main_sprite):
                for j, cell in enumerate(row):
                    color = parse_color(cell, loop_num)
                    sprite = tk.Frame(sprite_container, bg=color)
                    sprite.place(relx=j/5, rely=i/8, relwidth=0.625, relheight=0.625)


            loop_num = (loop_num + 1) % 4  # Loop through 0 to 3

            if not pausevar:
                # Schedule the next sprite change
                nonlocal flame_speed
                sprite_container.after(flame_speed, change_sprite)  # Change sprite every second
                if flame_speed > 250:
                    flame_speed -= 1
        change_sprite()



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
