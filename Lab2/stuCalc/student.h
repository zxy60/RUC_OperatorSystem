#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STU 100

typedef struct{
	int id;
	char name[20];
	float usual;
	float final;
	float total;
}Student;

void addStudent(Student arr[], int* n);
void deleteStudent(Student arr[], int* n);
void updateStudent(Student arr[], int n);
void queryStudent(Student arr[], int n);
void listStudent(Student arr[], int n);

#endif
