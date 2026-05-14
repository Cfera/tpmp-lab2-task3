#include "student.h"
#include <stdio.h>
#include <string.h>

double calculate_average_score(const Student *s) {
    if (s == NULL) return 0.0;
    int sum = 0;
    for (int i = 0; i < GRADES_COUNT; ++i) {
        sum += s->ses[i];
    }
    return (double)sum / GRADES_COUNT;
}

int compare_by_name(const void *a, const void *b) {
    const Student *student_a = (const Student *)a;
    const Student *student_b = (const Student *)b;
    return strcmp(student_a->name, student_b->name);
}

void print_student(const Student *s) {
    if (s == NULL) return;
    printf("Имя: %-20s | Курс: %d | Оценки: ", s->name, s->kurs);
    for (int i = 0; i < GRADES_COUNT; ++i) {
        printf("%d ", s->ses[i]);
    }
    printf("| Средний балл: %.2f\n", calculate_average_score(s));
}