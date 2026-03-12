#include <stdio.h>
#include "student.h"

int main() {
    STUDENT group[NUM_STUDENTS];
    float groupAverage;
    printf("Введите данные для %d студентов:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\n--- Студент %d ---", i + 1);
        inputStudent(&group[i]);
    }
    sortStudentsByName(group, NUM_STUDENTS);
    printAllStudents(group, NUM_STUDENTS);
    groupAverage = calculateGroupAverage(group, NUM_STUDENTS);
    printf("\nОбщий средний балл группы: %.2f\n", groupAverage);
    findAboveAverage(group, NUM_STUDENTS, groupAverage);
    return 0;
