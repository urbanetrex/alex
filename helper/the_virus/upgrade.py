import tkinter as tk

root = tk.Tk()
root.overrideredirect(True)
root.geometry("260x355")
root.configure(bg='#ECECEC')

canvas = tk.Canvas(root, bg='#ECECEC', highlightthickness=0)
canvas.pack(fill='both', expand=True)

def create_rounded_rect(canvas, x1, y1, x2, y2, radius=10, **kwargs):
    points = [
        x1+radius, y1,
        x2-radius, y1,
        x2, y1,
        x2, y1+radius,
        x2, y2-radius,
        x2, y2,
        x2-radius, y2,
        x1+radius, y2,
        x1, y2,
        x1, y2-radius,
        x1, y1+radius,
        x1, y1
    ]
    return canvas.create_polygon(points, smooth=True, **kwargs)

def make_button(x, y, color, cmd, text):
    font = ("Helvetica", 12, "bold")
    padding_x = 15
    padding_y = 10
    
    # Size based on text
    text_width = len(text) * 8
    width = text_width + padding_x * 2
    height = 20
    
    # Create canvas for the button
    btn = tk.Canvas(root, width=width, height=height, bg='#ECECEC', highlightthickness=0)
    btn.place(x=x, y=y)
    
    # Draw rounded rectangle
    create_rounded_rect(btn, 0, 0, width, height, radius=15, fill=color, outline=color)
    
    # Add text
    btn.create_text(width/2, height/2, text=text, font=font, fill="white")
    
    # Bind click
    btn.bind("<Button-1>", lambda e: cmd())

# Example button actions
def close_app():
    root.destroy()

make_button(10, 10, '#0C80FF', close_app, 'Close')
make_button(110, 10, '#D0D0D0', lambda: print("Minimize"), 'Minimize')
make_button(230, 10, '#34c759', lambda: print("Zoom"), 'Zoom')

# Support for moving the window
def start_move(event):
    root.x = event.x
    root.y = event.y

def on_motion(event):
    root.geometry(f"+{event.x_root - root.x}+{event.y_root - root.y}")

canvas.bind("<ButtonPress-1>", start_move)
canvas.bind("<B1-Motion>", on_motion)

root.mainloop()
