# Snake Game in C++

This is a simple terminal-based Snake game written in C++ using the `ncurses` library. The objective of the game is to control the snake using the WASD keys to eat the fruit and grow. The game ends when the snake collides with itself.

### How to play:
Movement: Use the following keys to control the snake:
- W: Move up
- A: Move left
- S: Move down
- D: Move right
- Quit the game: Press X to quit.

### Requirements

- A C++ compiler (e.g., `g++`)
- `ncurses` library

### Installing ncurses on macOS

1. Install [Homebrew](https://brew.sh) (if not installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
2. install ncurses using homebrew
   ```bash
   brew install ncurses

## How to Run the Game Locally
1. Clone the repo

2. Compile the gsme with the ncurses library
   ```bash
   g++ snakegame.cpp -o snakegame -lncurses
4. Run the game
   ```bash
   ./snakegame
   
<img width="506" alt="Screenshot 2024-10-03 at 8 49 54 PM" src="https://github.com/user-attachments/assets/6138f494-e927-4ab3-9359-217c65004b98">

