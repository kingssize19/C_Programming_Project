#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int gprimes[] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                       53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
                       113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
                       181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,
                       251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
                       317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
                       397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
                       463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 };


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

static int icmp(const void* vp1, const void* vp2);

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

int isprime(int x)
{
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x == 3)
        return 1;
    if (x == 5)
        return 1;
    if (x == 7)
        return 1;

    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0)
            return 0;
    }   
    return 1;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

int ndigit(int x)
{
    int digit = 0;
    while (x) {
        digit++;
        x /= 10;
    }
    
    return digit;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; //null statement
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void put_stars(int n)
{
    while (n) {
        printf("*");
        n--;
    }
    printf("\n");
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void set_array_random(int* p, size_t size)
{
    while (size--) {
        *p++ = rand() % 1000;
    }

}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void print_array(const int* p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        if (i && i % 20 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }
    printf("\n-------------------------------------------------------------------------\n");
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void randomize(void)
{
    srand((unsigned)time(NULL));
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


void sort_array(int* p, size_t size)
{
    qsort(p, size, sizeof(*p), icmp);
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

static int icmp(const void* vp1, const void* vp2)
{
    return *(const int*)vp1 - *(const int*)vp2;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


void bubble_sort(int* p, size_t size);

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void sgets(char* p)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        *p++ = (char)c;
    *p = '\0';
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

void gswap(void* vp1, void* vp2, size_t n)
{
    char* p1 = (char*)vp1;
    char* p2 = (char*)vp2;

    while (n--) {
        char ptemp = *p1;
        *p1++ = *p2;
        *p2++ = ptemp;
    }
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

const char* rname(void)
{
    static const char* const pnames[] = {
    "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah", "Isaac", "Jack",
    "Kathy", "Liam", "Megan", "Nina", "Oliver", "Paul", "Quinn", "Rita", "Sam", "Tom",
    "Ursula", "Victor", "Wendy", "Xander", "Yvonne", "Zack", "Anna", "Ben", "Clara", "Daniel",
    "Eleanor", "Fiona", "George", "Holly", "Ivy", "James", "Kaitlyn", "Leo", "Maria", "Nathan",
    "Olivia", "Peter", "Quincy", "Rebecca", "Sophia", "Travis", "Ulysses", "Vanessa", "William", "Xena",
    "Yara", "Zane", "Amelia", "Blake", "Catherine", "Daniela", "Ella", "Freddie", "Gina", "Harry",
    "Isabella", "Jason", "Kylie", "Lily", "Max", "Naomi", "Oscar", "Penny", "Quinn", "Riley",
    "Samantha", "Theo", "Uriah", "Vera", "Wyatt", "Zoe", "Abigail", "Benjamin", "Chloe", "David",
    "Evelyn", "Franklin", "Grace", "Harrison", "Iris", "Jackie", "Ken", "Lana", "Maya", "Nico",
    "Ophelia", "Parker", "Quinn", "Rose", "Steve", "Tessa", "Ursula", "Violet", "Wesley", "Xander",
    "Yasmin", "Zachary", "Ava", "Blake", "Caden", "Diana", "Emilio", "Felicity", "Gabe", "Hannah",
    "India", "John", "Kara", "Luke", "Mason", "Nina", "Oscar", "Piper", "Quincy", "Ryan",
    "Sophia", "Tyler", "Ursula", "Veronica", "Walter", "Xander", "Yasmine", "Zeke", "Aiden", "Brittany",
    "Connor", "Daisy", "Evan", "Faith", "Grace", "Hunter", "Ivy", "Jake", "Katherine", "Leo",
    "Madeline", "Nicholas", "Olivia", "Paige", "Quinn", "Rachel", "Seth", "Trinity", "Uriah", "Vera",
    "Wyatt", "Xander", "Yara", "Zane", "Anna", "Ben", "Clara", "David", "Eleanor", "Frank",
    "Grace", "Hannah", "Isaac", "Jack", "Kathy", "Liam", "Megan", "Nina", "Oliver", "Paul",
    "Quinn", "Rita", "Sam", "Tom", "Ursula", "Victor", "Wendy", "Xander", "Yvonne", "Zack",
    "Amelia", "Blake", "Catherine", "Daniel", "Eve", "Freddy", "Gina", "Holly", "Ivy", "James",
    "Kaitlyn", "Leo", "Maria", "Nina", "Olivia", "Peter", "Quincy", "Rebecca", "Samantha", "Theo",
    "Uriah", "Vera", "Wyatt", "Zoe", "Abigail", "Benjamin", "Chloe", "David", "Evelyn", "Franklin",
    "Grace", "Harrison", "Iris", "Jackie", "Ken", "Lana", "Maya", "Nico", "Olivia", "Penny",
    "Quinn", "Riley", "Samantha", "Theo", "Uriah", "Vera", "Wyatt", "Zoe", "Abigail", "Benjamin"
    };

    return relem(pnames);

}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

const char* rfname(void)
{
    static const char* const gfnames[] = {
    "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor",
    "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Roberts",
    "Lopez", "Gonzalez", "Wilson", "Young", "King", "Scott", "Adams", "Baker", "Nelson", "Carter",
    "Mitchell", "Perez", "Robinson", "Hall", "Clark", "Lewis", "Lee", "Walker", "Allen", "Young",
    "King", "Wright", "Hill", "Scott", "Green", "Baker", "Adams", "Nelson", "Carter", "Mitchell",
    "Perez", "Robinson", "Harris", "Hernandez", "Gonzalez", "Lopez", "Taylor", "Moore", "Jackson", "Martin",
    "Thomas", "Garcia", "Martinez", "Rodriguez", "Wright", "King", "Scott", "Baker", "Nelson", "Carter",
    "Mitchell", "Perez", "Robinson", "Harris", "Hernandez", "Gonzalez", "Lopez", "Taylor", "Moore", "Jackson",
    "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez", "Walker", "Allen", "Young", "King", "Scott",
    "Baker", "Nelson", "Carter", "Mitchell", "Perez", "Robinson", "Harris", "Hernandez", "Gonzalez", "Lopez",
    "Taylor", "Moore", "Jackson", "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez", "Wright", "Hill",
    "Green", "Adams", "Baker", "Carter", "Nelson", "Mitchell", "Perez", "Robinson", "Harris", "Hernandez",
    "Gonzalez", "Lopez", "Taylor", "Moore", "Jackson", "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez",
    "Walker", "Allen", "Young", "King", "Scott", "Wright", "Hill", "Green", "Baker", "Adams",
    "Nelson", "Carter", "Mitchell", "Perez", "Robinson", "Harris", "Hernandez", "Gonzalez", "Lopez", "Taylor",
    "Moore", "Jackson", "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez", "Walker", "Allen", "Young",
    "King", "Scott", "Baker", "Nelson", "Carter", "Mitchell", "Perez", "Robinson", "Harris", "Hernandez",
    "Gonzalez", "Lopez", "Taylor", "Moore", "Jackson", "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez",
    "Walker", "Allen", "Young", "King", "Scott", "Wright", "Hill", "Green", "Adams", "Baker",
    "Nelson", "Carter", "Mitchell", "Perez", "Robinson", "Harris", "Hernandez", "Gonzalez", "Lopez", "Taylor",
    "Moore", "Jackson", "Martin", "Thomas", "Garcia", "Martinez", "Rodriguez", "Walker", "Allen", "Young"
    };

    return relem(gfnames);
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

const char* rtown(void)
{
    static const char* const ptowns[] = {
    "Ýstanbul", "Ankara", "Ýzmir", "Bursa", "Antalya", "Konya", "Adana", "Gaziantep", "Þanlýurfa", "Kocaeli",
    "Mersin", "Samsun", "Trabzon", "Kayseri", "Eskiþehir", "Denizli", "Balýkesir", "Aydýn", "Manisa", "Hatay",
    "Diyarbakýr", "Tekirdað", "Muðla", "Sakarya", "Çorum", "Çanakkale", "Zonguldak", "Rize", "Kütahya", "Mardin",
    "Van", "Kýrklareli", "Aksaray", "Bolu", "Niðde", "Tokat", "Afyon", "Batman", "Karabük", "Nevþehir",
    "Karaman", "Ordu", "Uþak", "Giresun", "Yozgat", "Kastamonu", "Bingöl", "Osmaniye", "Artvin", "Bayburt",
    "Isparta", "Aðrý", "Bolu", "Erzurum", "Erzincan", "Sakarya", "Gümüþhane", "Bartýn", "Kýrýkkale", "Sinop",
    "Çankýrý", "Sivas", "Kýrþehir", "Kocaeli", "Ýçel", "Burdur", "Þýrnak", "Muþ", "Adýyaman", "Mardin"
    };

    return relem(ptowns);
}