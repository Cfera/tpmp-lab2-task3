#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"
#include "student.h"

#define STUDENT_COUNT 10

int main() {
    printf("Задание 3. Вариант 2\n");

    printf("--- Часть 1: Поиск чисел с максимальной суммой цифр ---\n");
    int numbers[] = {123, 45, 999, 81, 456, 189, 727};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int indices[100];
    int count = 0;

    printf("Исходный массив: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    find_max_digit_sum_indices(numbers, size, indices, &count);

    printf("Максимальная сумма цифр у чисел: ");
    for (int i = 0; i < count; ++i) {
        printf("%d (сумма: %d) ", numbers[indices[i]], sum_of_digits(numbers[indices[i]]));
    }
    printf("\n\n");

    printf("--- Часть 2 и 3: Ввод и обработка данных студентов ---\n");

    Student students[STUDENT_COUNT];

    printf("Введите данные о %d студентах (Фамилия И.О., курс, 5 оценок):\n", STUDENT_COUNT);
    for (int i = 0; i < STUDENT_COUNT; ++i) {
        printf("\nСтудент %d:\n", i + 1);
        printf("  Фамилия и инициалы: ");
        fgets(students[i].name, NAME_LEN, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("  Курс: ");
        scanf("%d", &students[i].kurs);

        printf("  5 оценок через пробел: ");
        for (int j = 0; j < GRADES_COUNT; ++j) {
            scanf("%d", &students[i].ses[j]);
        }
        getchar();
    }

    qsort(students, STUDENT_COUNT, sizeof(Student), compare_by_name);

    double total_average = 0.0;
    for (int i = 0; i < STUDENT_COUNT; ++i) {
        total_average += calculate_average_score(&students[i]);
    }
    total_average /= STUDENT_COUNT;

    printf("\n--- Результаты ---\n");
    printf("Общий средний балл всех студентов: %.2f\n", total_average);
    printf("\nСтуденты, чей средний балл превышает общий средний:\n");

    int found = 0;
    for (int i = 0; i < STUDENT_COUNT; ++i) {
        double avg = calculate_average_score(&students[i]);
        if (avg > total_average) {
            print_student(&students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Таких студентов нет.\n");
    }

    return 0;
}