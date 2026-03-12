#include <stdio.h>
#include <string.h>
#include "student.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inputStudent(STUDENT *student) {
    printf("\n--- Ввод данных студента ---\n");
    
    printf("Введите фамилию и инициалы: ");
    fgets(student->name, MAX_NAME, stdin);
    size_t len = strlen(student->name);
    if (len > 0 && student->name[len-1] == '\n') {
        student->name[len-1] = '\0';
    }
    
    do {
        printf("Введите курс (1-5): ");
        scanf("%d", &student->kurs);
        if (student->kurs < 1 || student->kurs > 5) {
            printf("Ошибка! Курс должен быть от 1 до 5.\n");
        }
    } while (student->kurs < 1 || student->kurs > 5);
    
    printf("Введите 5 оценок (0-10):\n");
    for (int i = 0; i < NUM_GRADES; i++) {
        do {
            printf("Оценка %d: ", i + 1);
            scanf("%d", &student->ses[i]);
            if (student->ses[i] < 0 || student->ses[i] > 10) {
                printf("Ошибка! Оценка должна быть от 0 до 10.\n");
            }
        } while (student->ses[i] < 0 || student->ses[i] > 10);
    }
    
    clearInputBuffer();
    calculateAverage(student);
}

void printStudent(const STUDENT *student) {
    printf("\nСтудент: %s\n", student->name);
    printf("Курс: %d\n", student->kurs);
    printf("Оценки: ");
    for (int i = 0; i < NUM_GRADES; i++) {
        printf("%d ", student->ses[i]);
    }
    printf("\nСредний балл: %.2f\n", student->average);
    printf("------------------------\n");
}

void printAllStudents(STUDENT students[], int count) {
    printf("\n=== ПОЛНЫЙ СПИСОК СТУДЕНТОВ ===\n");
    for (int i = 0; i < count; i++) {
        printStudent(&students[i]);
    }
}
