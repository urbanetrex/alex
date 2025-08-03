import os
class Screen:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.buffer = []
        self.clear()

    def clear(self):
        """Fill the screen with spaces."""
        self.buffer = [[" " for _ in range(self.width)] for _ in range(self.height)]

    def render(self):
        """Print the screen buffer to the terminal."""
        os.system('cls' if os.name == 'nt' else 'clear')

        print("╔"+"═" * (self.width+2)+"╗")
        print("║"+" " * (self.width+2)+"║")
        for row in self.buffer:
            print("║ "+("".join(row))+" ║")
        print("║"+" " * (self.width+2)+"║")
        print("╚"+"═" * (self.width+2)+"╝")
        

screen = Screen(80, 24)
screen.render()