#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int tgl;

} nilaiMatkul;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatkul kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], int tgl, list *L);
// void addAfter(elemen *before, char tgl[], char nama[], list *L);
// void addbefore(elemen *before, char tgl[], char nama[], list *L);
// void addLast(char tgl[], char nama[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);
// void swapElement(elemen *x, elemen *y);
// void sorting_asc(elemen *before, char tgl[], char nama[], list *L);
void printElement(list L);
void selection_sort(list *L);
void sort_k(list *L, int tgl);
void sort_s(list *L, int tgl);
void pindah_pointer(list *L, elemen *before, elemen *key, elemen *temp);
void printnew(list L, int tgl);
void printku(list L, int tgl);

// void printRvg(list L);