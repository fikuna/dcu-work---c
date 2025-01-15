#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student
{
    char name[20];
    char programme[20];
    float grade;
};

void get_student(int *len, char *argv[], Student *students);
void print_student(int *len, Student *students);

int main(int argc, char *argv[])
{
    int len = 2;
    Student *students = (Student *)calloc(len, sizeof(Student));
    if (!students)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }

    get_student(&len, argv, students);

    len = argc / 3;
    Student *tp = (Student *)realloc(students, len * sizeof(Student));
    if (!tp)
    {
        printf("Error allocating memory!\n");
        free(students);
        students = NULL;
        exit(0);
    }

    students = tp;
    get_student(&len, argv, students);
    print_student(&len, students);
    free(students);
    students = NULL;
    return 0;

}

void get_student(int *len, char *argv[], Student *students)
{
    int cnt;
    int i;
    if (*len == 2)
    {
        i = 0;
        cnt = 0;
    }
    else{
     i = 2;
     cnt = i * 3;
    }

    for (; i < *len; ++i)
    {
        Student *ptr = &students[i];
        strcpy(ptr->name, argv[cnt + 1]);
        strcpy(ptr->programme, argv[cnt + 2]);
        ptr->grade = atof(argv[cnt + 3]);
        cnt += 3;
    }
}

void print_student(int *len, Student *students)
{
    for (int i = 0; i < *len; ++i)
    {
        Student *ptr = &students[i];
        printf("%s, %s, %.2f\n", ptr->name, ptr->programme, ptr->grade);
    }
}