#ifndef STUDENT_H
#define STUDENT_H
#define MAX_NAME 50
#define NUM_GRADES 5
#define NUM_STUDENTS 10

typedef struct {
    char name[MAX_NAME];
    int kurs;
    int ses[NUM_GRADES];
    float average;
} STUDENT;

void calculateAverage(STUDENT *student);
float calculateGroupAverage(STUDENT students[], int count);
void sortStudentsByName(STUDENT students[], int count);
void findAboveAverage(STUDENT students[], int count, float groupAverage);

void inputStudent(STUDENT *student);
void printStudent(const STUDENT *student);
void printAllStudents(STUDENT students[], int count);
void clearInputBuffer();

#endif
