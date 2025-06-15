
#include <stdio.h>

 #include "allheaders.h"// for get_valid_int and get_valid_double

// Function to show unit conversion menu
void unit_converter_menu() {
    printf("\033[1;36m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("📐     UNIT CONVERTER MENU      📐\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    printf("Select conversion type:\n1️⃣  Length\n2️⃣  Weight\n3️⃣  Temperature\n4️⃣  Speed\n");
    int uChoice = get_valid_int("👉 Enter choice: ");

    double value, result;
    int fromUnit, toUnit;

    switch (uChoice) {
        case 1:  // Length
            printf("\033[1;34mUnits: 1-cm, 2-m, 3-km, 4-inch, 5-foot\033[0m\n");
            printf("Enter value, from unit, to unit: ");
            scanf("%lf %d %d", &value, &fromUnit, &toUnit);
            result = convert_length(value, fromUnit, toUnit);
            break;

        case 2:  // Weight
            printf("\033[1;34mUnits: 1-gram, 2-kg, 3-lb\033[0m\n");
            printf("Enter value, from unit, to unit: ");
            scanf("%lf %d %d", &value, &fromUnit, &toUnit);
            result = convert_weight(value, fromUnit, toUnit);
            break;

        case 3:  // Temperature
            printf("\033[1;34mUnits: 1-Celsius, 2-Fahrenheit\033[0m\n");
            printf("Enter value, from unit, to unit: ");
            scanf("%lf %d %d", &value, &fromUnit, &toUnit);
            result = convert_temperature(value, fromUnit, toUnit);
            break;

        case 4:  // Speed
            printf("\033[1;34mUnits: 1-km/h, 2-m/s, 3-mph\033[0m\n");
            printf("Enter value, from unit, to unit: ");
            scanf("%lf %d %d", &value, &fromUnit, &toUnit);
            result = convert_speed(value, fromUnit, toUnit);
            break;

        default:
            printf("\033[1;31m❌ Invalid conversion type.\033[0m\n");
            return;
    }

    if (result == -1 || result == -9999)
        printf("\033[1;31m❌ Conversion error! Check your units.\033[0m\n");
    else
        printf("\033[1;32m✅ Converted result = %.4lf\033[0m\n", result);
}

// 💡 Length Conversion
double convert_length(double value, int from, int to) {
    double cm;

    switch (from) {
        case 1: cm = value; break;                   // cm
        case 2: cm = value * 100; break;             // m
        case 3: cm = value * 100000; break;          // km
        case 4: cm = value * 2.54; break;            // inch
        case 5: cm = value * 30.48; break;           // foot
        default: return -1;
    }

    switch (to) {
        case 1: return cm;
        case 2: return cm / 100;
        case 3: return cm / 100000;
        case 4: return cm / 2.54;
        case 5: return cm / 30.48;
        default: return -1;
    }
}

// 💡 Weight Conversion
double convert_weight(double value, int from, int to) {
    double gram;

    switch (from) {
        case 1: gram = value; break;
        case 2: gram = value * 1000; break;
        case 3: gram = value * 453.592; break;
        default: return -1;
    }

    switch (to) {
        case 1: return gram;
        case 2: return gram / 1000;
        case 3: return gram / 453.592;
        default: return -1;
    }
}

// 💡 Temperature Conversion
double convert_temperature(double value, int from, int to) {
    if (from == to) return value;

    if (from == 1 && to == 2)
        return value * 9.0 / 5.0 + 32;
    else if (from == 2 && to == 1)
        return (value - 32) * 5.0 / 9.0;

    return -9999;  // unsupported
}

// 💡 Speed Conversion
double convert_speed(double value, int from, int to) {
    double mps;

    switch (from) {
        case 1: mps = value * 1000.0 / 3600.0; break; // km/h
        case 2: mps = value; break;                  // m/s
        case 3: mps = value * 0.44704; break;        // mph
        default: return -1;
    }

    switch (to) {
        case 1: return mps * 3.6;
        case 2: return mps;
        case 3: return mps / 0.44704;
        default: return -1;
    }
}
