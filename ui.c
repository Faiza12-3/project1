// ui.c


#include <stdio.h>
#include <stdlib.h>
#include "allheaders.h"

void displayWelcome() {
    clearScreen();
    setColor("\033[1;35m");  // Bright Magenta
    printf("\n");
    printf("                                                      \n");
    printf("Congratulations u have logged into Faiza Calculator🙄  \n");
    printf("                                                      \n");
    printf("n");
    resetColor();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showMainMenu() {
    setColor("\033[1;36m"); // Cyan
    printf("\n📋 MAIN MENU 📋\n");
    printf("1. ➕➖✖️➗ Core Math Operations\n");
    printf("2. 📊 Modules (Factorial, Prime, Quadratic)\n");
    printf("3. 🔁 Unit Converter\n");
    printf("4. 🎓 GPA / CGPA Calculator\n");
    printf("5. 🧠 Logic & Memory Tools\n");
    printf("6. 🤖 AI Features\n");
    printf("7. 🕒 View History\n");
    printf("8.📋 Memory/recall/add/sub from memory\n");
    printf("9. 🤖 AI Chatbot Assistant\n");

    printf("0. ❌ Exit\n");
    resetColor();
}

void setColor(const char* colorCode) {
    printf("%s", colorCode);
}

void resetColor() {
    printf("\033[0m");
}
