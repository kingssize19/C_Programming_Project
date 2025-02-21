#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include <stdlib.h>
#include "student_list.h"



int main(void)
{
	randomize();

	int n = rand() % 10 + 10;

	Student s;

	for (int i = 0; i < n; ++i) {
		set_random_student(&s);
		push_front(&s);
	}



	while (!is_empty()) {
		
		printf("listede %d ogrenci var!\n", get_size());

		top(&s);
		printf("listedeki ilk ogrenci : \n");
		put_stars(80);
		print_student(&s);
		
		pop_front();
		put_stars(80);
		print_list();
		
		(void)getchar();
		system("cls");
		
	}

}


/*
 55. video test kodları (student_list için)
 ------------------------------------------

 1. Test Kodu :  (Başarılı)
 --------------

 #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include <stdlib.h>
#include "student_list.h"



int main(void)
{
	Student s;

	randomize();

	for (int i = 0; i < 10; ++i) {
		set_random_student(&s);
		print_student(&s);
		push_front(&s);
	}

	printf("listede %d ogrenci var\n", get_size());
	print_list();

	make_empty();
	printf("listede %d ogrenci var\n", get_size());

}
--------------------------------------------------------------------------
--------------------------------------------------------------------------

2. Test Kodu :  (Başarılı)
--------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include <stdlib.h>
#include "student_list.h"



int main(void)
{
	int n;

	printf("listeye kac ogrenci eklensin : ");
	scanf("%d", &n);

	randomize();

	Student s;

	for (int i = 0; i < n; ++i) {
		set_random_student(&s);
		push_front(&s);
	}

	printf("listede %d ogrenci var\n", get_size());

	make_empty();

}

--------------------------------------------------------------------------
--------------------------------------------------------------------------

3. Test Kodu :  Başarılı
--------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include <stdlib.h>
#include "student_list.h"



int main(void)
{
	randomize();

	int n = rand() % 10 + 10;

	Student s;

	for (int i = 0; i < n; ++i) {
		set_random_student(&s);
		push_front(&s);
	}



	while (!is_empty()) {

		printf("listede %d ogrenci var!\n", get_size());

		top(&s);
		printf("listedeki ilk ogrenci : \n");
		put_stars(80);
		print_student(&s);

		pop_front();
		put_stars(80);
		print_list();

		(void)getchar();
		system("cls");

	}

}






*/



