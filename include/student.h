#ifndef STUDENT_H
#define STUDENT_H

#define GRADES_COUNT 5
#define NAME_LEN 100

typedef struct {
    char name[NAME_LEN];
    int kurs;
    int ses[GRADES_COUNT];
} Student;

double calculate_average_score(const Student *s);
int compare_by_name(const void *a, const void *b);
void print_student(const Student *s);

#endif