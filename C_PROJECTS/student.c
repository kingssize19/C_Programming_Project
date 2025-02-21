#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nutility.h"


Student* set_random_student(Student* p)
{
	p->mno = rand() % 1000;
	strcpy(p->mname, rname());
	strcpy(p->msurname, rfname());
	strcpy(p->mtown, rtown());
	set_random_date(&p->mbdate);
}


void print_student(const Student* p)
{
	printf("%-5d %-16s %-18s %-20s ", p->mno, p->mname, p->msurname, p->mtown);
	print_date(&p->mbdate);
	
}


// isim => soy isim => sehir => dogum tarihi => numara
int cmp_student(const Student* p1, const Student* p2)
{
	int cmp_result = strcmp(p1->mname, p2->mname);
	if (cmp_result)
		return cmp_result;

	cmp_result = strcmp(p1->msurname, p2->msurname);
	if (cmp_result)
		return cmp_result;

	cmp_result = strcmp(p1->mtown, p2->mtown);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_date(&p1->mbdate, &p2->mbdate);
	if (cmp_result)
		return cmp_result;

}

/*

Test Kodu Student için:
-----------------------


int wcmp_student(const void* vp1, const void* vp2)
{
	return cmp_student((const Student*)vp1, (const Student*)vp2);
}


int main(void)
{
	size_t n;

	printf("Kac ogrenci : ");
	scanf("%zu", &n);

	Student* pd = (Student*)malloc(n * sizeof(Student));
	if (!pd) {
		fprintf(stderr, "bellek yetersiz!\n");
		return 1;
	}

	for (size_t i = 0; i < n; ++i) {
		set_random_student(pd + i);
	}

	qsort(pd, n, sizeof(Student), wcmp_student);
	clear_input_buffer();
	(void)getchar();

	for (size_t i = 0; i < n; ++i) {
		print_student(pd + i);
	}

	free(pd);



}

*/


