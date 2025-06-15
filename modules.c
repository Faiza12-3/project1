// modules.c
#include <stdio.h>
#include <math.h>
#include "allheaders.h"

void modules_menu() {
    printf("\033[1;35m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("📊      MODULES OPERATIONS      📊\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    printf("\033[1;36m📚 Available Modules: Factorial, Prime, Quadratic 📚\033[0m\n");

    printf("1️⃣  Factorial\n2️⃣  Prime Check\n3️⃣  Solve Quadratic\n");
    printf("👉 Enter choice: ");

    int mChoice;
    if (scanf("%d", &mChoice) != 1) {
        printf("\033[1;31m❌ Invalid input!\033[0m\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (mChoice == 1) {
        int n = get_valid_int("Enter number for factorial: ");
        printf("\033[1;32m✨ Factorial of %d = %llu\033[0m\n", n, factorial(n));
    } else if (mChoice == 2) {
        int n = get_valid_int("Enter number to check prime: ");
        printf("\033[1;32m✨ %d is %s prime number.\033[0m\n", n, is_prime(n) ? "a" : "not a");
    } else if (mChoice == 3) {
        double a, b, c;
        printf("Enter coefficients a, b, c: ");
        if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
            printf("\033[1;31m❌ Invalid input!\033[0m\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        solve_quadratic(a, b, c);
    } else {
        printf("\033[1;31m❌ Invalid module choice.\033[0m\n");
    }
}

// These helper functions are internal and not declared in the header
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        printf("\033[1;31m❌ Not a quadratic equation (a = 0).\033[0m\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\033[1;32m✅ Roots are real and distinct:\n");
        printf("x1 = %.2lf, x2 = %.2lf\033[0m\n", x1, x2);
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("\033[1;32m✅ Roots are real and equal:\n");
        printf("x = %.2lf\033[0m\n", x);
    } else {
        double real = -b / (2 * a);
        double imag = sqrt(-discriminant) / (2 * a);
        printf("\033[1;32m✅ Complex roots:\n");
        printf("x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\033[0m\n", real, imag, real, imag);
    }
}
