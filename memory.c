// memory.c
#include <stdio.h>
 #include "allheaders.h"

 double memory_value = 0.0;

void memory_add(double value) {
    memory_value = value;
    printf("💾 Stored %.2lf in memory.\n", memory_value);
}

void memory_recall() {
    printf("📤 Recalled value from memory: %.2lf\n", memory_value);
}

void memory_add_value(double value) {
    memory_value += value;
    printf("🔼 Added %.2lf to memory. New value: %.2lf\n", value, memory_value);
}

void memory_subtract_value(double value) {
    memory_value -= value;
    printf("🔽 Subtracted %.2lf from memory. New value: %.2lf\n", value, memory_value);
}

void memory_clear() {
    memory_value = 0.0;
    printf("🧹 Memory cleared. Current value: %.2lf\n", memory_value);
}




void memory_menu() {
    int choice;
    double value;

    while (1) {
        printf("\n\033[1;34m📚 MEMORY MENU\n");
        printf("━━━━━━━━━━━━━━━━━━━\n");
        printf("1. 💾 Store Value\n");
        printf("2. 📤 Recall Memory\n");
        printf("3. 🔼 Add to Memory (M+)\n");
        printf("4. 🔽 Subtract from Memory (M-)\n");
        printf("5. 🧹 Clear Memory\n");
        printf("0. 🔙 Return to Main Menu\n\033[0m");

        choice = get_valid_int("🔸 Enter your choice: ");

        switch (choice) {
            case 1:
                printf("🔢 Enter value to store: ");
                scanf("%lf", &value);
                memory_add(value);
                break;
            case 2:
                memory_recall();
                break;
            case 3:
                printf("🔢 Enter value to add: ");
                scanf("%lf", &value);
                memory_add_value(value);
                break;
            case 4:
                printf("🔢 Enter value to subtract: ");
                scanf("%lf", &value);
                memory_subtract_value(value);
                break;
            case 5:
                memory_clear();
                break;
            case 0:
                return;
            default:
                printf("❌ Invalid option. Please try again.\n");
        }
    }
}
