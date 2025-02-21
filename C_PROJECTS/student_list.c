#include "student_list.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

	Student s;
	struct Node* pnext;

}Node;


static Node* gpfirst = NULL;
static int gsize = 0;


static Node* allocate_node(void)
{

	Node* pnewnode = (Node*)malloc(sizeof(Node));
	if (!pnewnode) {
		fprintf(stderr, "yetersiz bellek\n");
		exit(EXIT_FAILURE);
	}

	return pnewnode;

}

int get_size(void)
{
	return gsize;
}

int is_empty(void)
{
	return gpfirst == NULL;
	//return gsize == 0;
}

void print_list(void)
{
	for (Node* p = gpfirst; p != NULL; p = p->pnext) {
		print_student(&p->s);
	}
}

void top(struct Student* p)
{
	if (is_empty()) {
		fprintf(stderr, "bos listede top hatasi\n");
		exit(EXIT_FAILURE);
	}

	*p = gpfirst->s;
}

void push_front(const struct Student* p)
{
	Node* pnewnode = allocate_node();
	pnewnode->s = *p;
	pnewnode->pnext = gpfirst;
	gpfirst = pnewnode;
	++gsize;

}

void pop_front(void)
{
	if (is_empty()) {
		fprintf(stderr, "bos listede pop hatasi\n");
		exit(EXIT_FAILURE);
	}

	Node* ptemp = gpfirst;
	gpfirst = gpfirst->pnext;
	free(ptemp);

	--gsize;
}

void make_empty(void)
{
	while (!is_empty()) {
		pop_front();
	}
}






