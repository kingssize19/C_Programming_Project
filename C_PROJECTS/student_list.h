#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

struct Student;

void push_front(const struct Student* p);
void pop_front(void);
void top(struct Student* p);
int get_size(void);
int is_empty(void);
void print_list(void);
void make_empty(void);

#endif


