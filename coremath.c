#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "allheaders.h"  // main all headers file included
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void arithmetic_menu() {
    int a = 0, b = 0, choice;
    double result;

    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🧮  ARITHMETIC OPERATIONS MENU  🧮\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    printf("\n🔢 Choose an operation:\n");
    printf("1️⃣  Add\n");
    printf("2️⃣  Subtract\n");
    printf("3️⃣  Multiply\n");
    printf("4️⃣  Divide\n");
    printf("5️⃣  Power (a^b)\n");
    printf("6️⃣  Square Root of a\n");
    printf("7️⃣  Sine(a in degrees)\n");
    printf("8️⃣  Cosine(a in degrees)\n");
    printf("9️⃣  Log(a)\n");
    printf("👉 Enter your choice: ");
    scanf("%d", &choice);

    // Inputs based on choice
    if (choice >= 1 && choice <= 5) {
        printf("Enter two numbers ✏️ : ");
        scanf("%d %d", &a, &b);
    } else if (choice >= 6 && choice <= 9) {
        printf("Enter one number ✏️ : ");
        scanf("%d", &a);
    }

    printf("\n📤 Result:\n");
    switch (choice) {
        case 1:
            printf("➕ Sum = %d\n", a + b);
            break;
        case 2:
            printf("➖ Difference = %d\n", a - b);
            break;
        case 3:
            printf("✖️ Product = %d\n", a * b);
            break;
        case 4:
            if (b != 0)
                printf("➗ Quotient = %.2f\n", (float)a / b);
            else
                printf("❌ Error: Division by zero!\n");
            break;
        case 5:
            result = pow(a, b);
            printf("🔺 Power (a^b) = %.2lf\n", result);
            break;
        case 6:
            if (a >= 0)
                printf("🟰 √%d = %.2lf\n", a, sqrt(a));
            else
                printf("❌ Error: Cannot take square root of a negative number!\n");
            break;
        case 7:
            printf("📐 sin(%d°) = %.4lf\n", a, sin(a * M_PI / 180));
            break;
        case 8:
            printf("📐 cos(%d°) = %.4lf\n", a, cos(a * M_PI / 180));
            break;
        case 9:
            if (a > 0)
                printf("📊 log(%d) = %.4lf\n", a, log(a));
            else
                printf("❌ Error: Logarithm of non-positive number!\n");
            break;
        default:
            printf("❗ Invalid option selected.\n");
    }

    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}
