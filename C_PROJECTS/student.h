#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN		19
#define MAX_SURNAME_LEN		24
#define MAX_TOWN_LEN		19

#include "date.h"

typedef struct Student {
	int mno;
	char mname[MAX_NAME_LEN + 1];
	char msurname[MAX_SURNAME_LEN + 1];
	char mtown[MAX_TOWN_LEN + 1];
	Date mbdate;

}Student;

Student* set_random_student(Student*);
void print_student(const Student*);
int cmp_student(const Student* p1, const Student* p2);

#endif
