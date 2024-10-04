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

3. brew install ncurses

## How to Run the Game Locally
1. Clone the repo

2. Compile the gsme with the ncurses library: `g++ snakegame.cpp -o snakegame -lncurses`

3. Run the game with `./snakegame`
