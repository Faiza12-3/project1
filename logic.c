#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "allheaders.h"
// Color codes


#define SIZE 3
#define MAX_WRONG 3

// Function declarations
int get_valid_int(const char *prompt);
void logic_tools_menu();
void number_maze_game();
void reveal_path(int path[SIZE][SIZE]);

void logic_tools_menu() {
    printf(CYAN "\n🔐 LOGIC & SMART GAMES MENU\n" RESET);
    printf("1. Number Maze Puzzle 🧩\n");
    printf("0. Back to Main Menu\n");

    int choice = get_valid_int("🔸 Enter your choice: ");
    switch (choice) {
        case 1:
            number_maze_game();
            break;
        case 0:
            printf("🔙 Returning to Main Menu...\n");
            break;
        default:
            printf(RED "❌ Invalid choice. Try again.\n" RESET);
    }
}

// Number Maze Game
void number_maze_game() {
    srand(time(NULL));
    int path[SIZE][SIZE] = {0};
    int x = 0, y = 0;
    path[x][y] = 1;

    // Random path generation
    while (x != SIZE - 1 || y != SIZE - 1) {
        if ((rand() % 2 == 0 && x < SIZE - 1) || y == SIZE - 1)
            x++;
        else
            y++;
        path[x][y] = 1;
    }

    printf(CYAN "\n🧩 Number Maze Game: Reach (2,2) from (0,0)\n" RESET);
    printf("➡️  Only valid adjacent steps (down or right).\n");

    int cx = 0, cy = 0, wrong = 0;

    while (cx != SIZE - 1 || cy != SIZE - 1) {
        int nx = get_valid_int("➡️  Enter next X: ");
        int ny = get_valid_int("➡️  Enter next Y: ");

        // Validate input
        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) {
            printf(RED "❌ Invalid coordinates.\n" RESET);
            continue;
        }

        // Check correct path
        if (path[nx][ny] && ((nx == cx + 1 && ny == cy) || (ny == cy + 1 && nx == cx))) {
            cx = nx;
            cy = ny;
            printf(GREEN "✅ Correct move to (%d,%d)\n" RESET, cx, cy);
        } else {
            wrong++;
            printf(RED "🚫 Wrong move (%d/%d)\n" RESET, wrong, MAX_WRONG);
            if (wrong >= MAX_WRONG) {
                printf(RED "\n❌ You failed to complete the maze.\n" RESET);
                reveal_path(path);
                return;
            }
        }
    }

    printf(GREEN "\n🎉 You completed the Number Maze successfully!\n" RESET);
}

// Show correct path after failure
void reveal_path(int path[SIZE][SIZE]) {
    printf(CYAN "\n📜 The correct path was:\n" RESET);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (path[i][j])
                printf(GREEN " 1 " RESET);
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Validated integer input
int get_valid_int(const char *prompt) {
    int value;
    printf(CYAN "%s" RESET, prompt);
    while (scanf("%d", &value) != 1) {
        while (getchar() != '\n');
        printf(RED "❌ Invalid input! " RESET);
        printf(CYAN "%s" RESET, prompt);
    }
    while (getchar() != '\n');
    return value;
}
