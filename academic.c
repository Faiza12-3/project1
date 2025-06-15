#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allheaders.h"

// GPA Calculation
float calculateGPA(int creditHours[], float gradePoints[], int subjects) {
    float totalPoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < subjects; i++) {
        totalPoints += creditHours[i] * gradePoints[i];
        totalCredits += creditHours[i];
    }

    if (totalCredits == 0) return 0;
    return totalPoints / totalCredits;
}

// CGPA Calculation
float calculateCGPA(float previousCGPA, float currentGPA, int completedSemesters) {
    return ((previousCGPA * completedSemesters) + currentGPA) / (completedSemesters + 1);
}

// Convert percentage to grade point
float percentageToGradePoint(float percentage) {
    if (percentage >= 90) return 4.00;
    else if (percentage >= 85) return 3.70;
    else if (percentage >= 80) return 3.30;
    else if (percentage >= 75) return 3.00;
    else if (percentage >= 70) return 2.70;
    else if (percentage >= 65) return 2.30;
    else if (percentage >= 60) return 2.00;
    else if (percentage >= 50) return 1.00;
    else return 0.00;
}

// Menu for academic operations
void academic_menu() {
    printf("\033[1;36m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🎓     ACADEMIC CALCULATOR      🎓\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    int subjects = get_valid_int("Enter number of subjects: ");
    if (subjects <= 0) {
        printf("Invalid number of subjects.\n");
        return;
    }

    int* creditHours = (int*) malloc(subjects * sizeof(int));
    float* gradePoints = (float*) malloc(subjects * sizeof(float));
    char subjectName[100];

    if (!creditHours || !gradePoints) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < subjects; i++) {
        printf("\nEnter name of subject %d: ", i + 1);
        while (getchar() != '\n'); // clear buffer before fgets
        fgets(subjectName, sizeof(subjectName), stdin);
        subjectName[strcspn(subjectName, "\n")] = '\0'; // remove newline

        creditHours[i] = get_valid_int("Enter credit hours: ");

        float percentage;
        printf("Enter obtained percentage in %s: ", subjectName);
        while (scanf("%f", &percentage) != 1) {
            printf("Invalid input. Enter percentage: ");
            while (getchar() != '\n');
        }

        gradePoints[i] = percentageToGradePoint(percentage);
    }

    float gpa = calculateGPA(creditHours, gradePoints, subjects);
    printf("\033[1;32m\n✨ GPA = %.2f\033[0m\n", gpa);

    int semesters = get_valid_int("Enter completed semesters for CGPA calculation: ");
    float previousCGPA;
    printf("Enter previous CGPA: ");
    while (scanf("%f", &previousCGPA) != 1) {
        printf("Invalid input. Enter previous CGPA: ");
        while (getchar() != '\n');
    }

    float cgpa = calculateCGPA(previousCGPA, gpa, semesters);
    printf("\033[1;32m✨ CGPA = %.2f\033[0m\n", cgpa);

    // Free allocated memory
    free(creditHours);
    free(gradePoints);
}
