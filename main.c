#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include all header files for different features
#include "allheaders.h"

#define PASSWORD "faiza"  // 🔐 Lock screen password

// 🌐 Enable UTF-8 for emojis (Windows-specific)
void enable_utf8() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

// 🔐 Show lock screen with password check
int showLockScreen() {
    char input[50];

    printf("\033[1;36m");
printf("✦・゚★ Faiza's Calculator ★・゚✦\n");
printf("        [🔢 Powered by Logic & Style ✨]\n");
printf("\033[0m");


    printf("🔑 Enter password to continue: ");
    scanf("%s", input);

    if (strcmp(input, PASSWORD) == 0) {
        printf("\033[1;32m✅ Access granted!\033[0m\n");
        return 1;
    } else {
        printf("\033[1;31m❌ Incorrect password! Exiting...\033[0m\n");
        return 0;
    }
}

// 🧠 Main Function
int main() {
    enable_utf8();  // Enable emoji support

    if (!showLockScreen()) {
        return 1;  // Incorrect password
    }

    int choice;
    displayWelcome();  // Show welcome banner

    while (1) {
        showMainMenu();  // Display menu options
        choice = get_valid_int("🔸 Enter your choice: ");

        switch (choice) {
            case 1:
                arithmetic_menu();
                break;
            case 2:
                modules_menu();
                break;
            case 3:
                unit_converter_menu();
                break;
            case 4:
                academic_menu();
                break;
            case 5:
                logic_tools_menu();
                break;
            case 6:
                
                chatbotInterface();
                
                break;
            case 7:
                viewHistory();
                break;
            case 8:
                memory_menu();
                break;
            case 9:
               chatbotInterface ();  // ✅ NEW CHATBOT FEATURE
                break;
            case 0:
                printf("\n👋 Exiting... Thank you for using Faiza Calculator!\n");
                exit(0);
            default:
                printf("❌ Invalid option. Please try again.\n");
        }

        printf("\n🔁 Press Enter to return to the main menu...");
        getchar(); // Consume leftover newline
        getchar(); // Wait for Enter
        clearScreen(); // Clear terminal
    }

    return 0;
}
