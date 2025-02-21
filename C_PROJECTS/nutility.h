#ifndef NUTILITY_H
#define NUTILITY_H

#define asize(a)				(sizeof(a) / sizeof(*a))
#define relem(a)				(a[rand() % asize(a)])
#define ISLEAP(y)				((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define RANDOM_DICE()			(rand() % 6 + 1)
#define NTH_PRIME(x)			(gprimes[x])

#include <stddef.h>

extern const int gprimes[];

int isprime(int x);
int ndigit(int x);

void clear_input_buffer(void);
void put_stars(int n);
void set_array_random(int* p, size_t size);
void print_array(const int* p, size_t size);
void randomize(void);
void sort_array(int* p, size_t size);
void bubble_sort(int* p, size_t size);
void sgets(char* p);
void swap(int* p1, int* p2);
void gswap(void* vp1, void* vp2, size_t n);

const char* rname(void);
const char* rfname(void);
const char* rtown(void);


#endif




