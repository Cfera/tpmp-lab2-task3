#include <stdio.h>
#include <string.h>
#include "student.h"

void calculateAverage(STUDENT *student) {
    int sum = 0;
    for (int i = 0; i < NUM_GRADES; i++) {
        sum += student->ses[i];
    }
    student->average = (float)sum / NUM_GRADES;
}

float calculateGroupAverage(STUDENT students[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].average;
    }
    return total / count;
}

void sortStudentsByName(STUDENT students[], int count) {
    STUDENT temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void findAboveAverage(STUDENT students[], int count, float groupAverage) {
    int found = 0;
    printf("\n--- Студенты с баллом выше среднего (%.2f) ---\n", groupAverage);
    
    for (int i = 0; i < count; i++) {
        if (students[i].average > groupAverage) {
            printStudent(&students[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Нет студентов с баллом выше среднего.\n");
    }
}
