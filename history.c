

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "allheaders.h."

#define HISTORY_FILE "history.txt"
#define PASSWORD "faiza123" // optional password to view history

// Log history to file
void logHistory(const char* operation, double result) {
    FILE* file = fopen(HISTORY_FILE, "a");
    if (file == NULL) {
        printf("⚠️ Error opening history file.\n");
        return;
    }

    time_t now = time(NULL);
    char* timeStr = ctime(&now);
    timeStr[strcspn(timeStr, "\n")] = '\0'; // remove newline

    fprintf(file, "[%s] %s = %.2f\n", timeStr, operation, result);
    fclose(file);
}

// View history with password
void viewHistory() {
    char input[50];
    printf("🔒 Enter password to view history: ");
    scanf("%s", input);

    if (strcmp(input, PASSWORD) != 0) {
        printf("❌ Incorrect password!\n");
        return;
    }

    FILE* file = fopen(HISTORY_FILE, "r");
    if (file == NULL) {
        printf("📭 No history found yet.\n");
        return;
    }

    // Decorative header printed inline (no separate function)
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🕒         HISTORY LOG          🕒\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    printf("\n📜 --- Calculation History --- 📜\n\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
