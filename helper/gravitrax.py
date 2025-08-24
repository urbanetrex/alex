import time
import os

class Basic_Screen:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.buffer = []
        self.on_screen = []
        self.clear()

    def clear(self):
        """Fill the screen with spaces."""
        self.buffer = self.on_screen = [" "*self.width for _ in range(self.height)]

class Slideshow_Screen(Basic_Screen):
    def __init__(self, width, height):
        super().__init__(width, height)

    def render(self, style="appear", **args):
        """
        Print the screen buffer to the terminal.
        Args:
            style (str): The rendering style, either "appear" or "slide".
            **args: Additional arguments for slide rendering.
        """
        os.system('cls' if os.name == 'nt' else 'clear')

        if style == "appear":
            print("╔"+"═" * (self.width+2)+"╗")
            print("║ "+" " * self.width +" ║")
            for row in self.buffer:
                print("║ "+("".join(row))+" ║")
            print("║ "+" " * self.width +" ║")
            print("╚"+"═" * (self.width+2)+"╝")
            self.on_screen = self.buffer.copy()
        elif style == "slide":
            if "direction" in args:
                direction = args["direction"]
                speed = args.get("speed", 0.2)
                if direction == "up":
                    for i in range(self.height):
                    # Construct the screen view
                        visible = self.buffer[i:] + [" " * self.width] * i
                        os.system('cls' if os.name == 'nt' else 'clear')
                        print("╔"+"═" * (self.width+2)+"╗")
                        print("║ "+" " * self.width +" ║")
                        for row in visible:
                            print(f"║ {row} ║")
                        print("║ "+" " * self.width +" ║")
                        print("╚"+"═" * (self.width+2)+"╝")
                        time.sleep(speed)
                    self.on_screen = self.buffer.copy()



    def set_char(self, x, y, char):
        """Set a character at the specified position."""
        if 0 <= x < self.width and 0 <= y < self.height:
            row = list(self.buffer[y])
            row[x] = char
            self.buffer[y] = "".join(row)
        else:
            raise ValueError("Position out of bounds")

# example usage
if __name__ == "__main__":
    screen = Slideshow_Screen(20, 10)
    screen.set_char(5, 5, 'X')
    screen.render(style="appear")
    time.sleep(2)
    screen.render(style="slide", direction="up", speed=0.5)
    time.sleep(2)
    screen.clear()
    screen.render(style="appear")
    time.sleep(2)
    screen.set_char(10, 3, 'O')
    screen.render(style="appear")
    time.sleep(2)
    screen.render(style="slide", direction="up", speed=0.5)
    time.sleep(2)
    screen.clear()
    screen.render(style="appear")
    time.sleep(2)
    screen.set_char(15, 7, 'A')
    screen.render(style="appear")
    time.sleep(2)
    screen.render(style="slide", direction="up", speed=0.5)
    time.sleep(2)
    screen.clear()
    screen.render(style="appear")
    time.sleep(2)
    screen.set_char(0, 0, 'B')
    screen.render(style="appear")
    time.sleep(2)
    screen.render(style="slide", direction="up", speed=0.5)
    time.sleep(2)
    screen.clear()
    screen.render(style="appear")
    time.sleep(2)
    screen.set_char(19, 9, 'C')
    screen.render(style="appear")
    time.sleep(2)
    screen.render(style="slide", direction="up", speed=0.5)
    time.sleep(2)
    screen.clear()
    screen.render(style="appear")