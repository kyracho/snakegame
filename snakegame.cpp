#include <iostream>
#include <ncurses.h>  // ncurses for non-blocking input and screen handling
#include <unistd.h>   // For usleep()
#include <cstdlib>    // For rand()

using namespace std;

const int width = 20;  // Window width
const int height = 17;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
bool gameOver;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    clear();  // Clears the ncurses window
    for (int i = 0; i < width + 2; i++) printw("_");
    printw("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) printw("|");
            if (i == y && j == x)
                printw("O");  // Snake head
            else if (i == fruitY && j == fruitX)
                printw("F");  // Fruit
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printw("o");  // Snake body
                        print = true;
                    }
                }
                if (!print) printw(" ");
            }
            if (j == width - 1) printw("|");
        }
        printw("\n");
    }

    for (int i = 0; i < width + 2; i++) printw("-");
    printw("\n");
    printw("Score: %d\n", score);
    refresh();  // Refresh the ncurses screen with the new drawing
}

void Input() {
    int ch = getch();  // Capture non-blocking input with ncurses
    switch (ch) {
        case 'a': if (dir != RIGHT) dir = LEFT; break;
        case 'd': if (dir != LEFT) dir = RIGHT; break;
        case 'w': if (dir != DOWN) dir = UP; break;
        case 's': if (dir != UP) dir = DOWN; break;
        case 'x': gameOver = true; break;
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    // Snake wrapping around the screen
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // Check for collision with snake body
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    // Snake eats fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    char restart;
    initscr();  // Initialize ncurses
    cbreak();   // Disable line buffering
    noecho();   // Don't show user input
    curs_set(0);  // Hide the cursor
    keypad(stdscr, TRUE);  // Enable arrow keys input
    nodelay(stdscr, TRUE); // Non-blocking input
    do {
        Setup();
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            usleep(100000);  // Slow down the loop (100 ms)
        }
        printw("Game Over! Your score is: %d\n", score);
        printw("Do you want to restart the game? (y/n): ");
        refresh();
        restart = getch();
    } while (restart == 'y' || restart == 'Y');

    endwin();  // End ncurses mode
    return 0;
}
