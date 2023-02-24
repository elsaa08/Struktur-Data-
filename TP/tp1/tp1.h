#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Saya Elsa Nabiilah [2108805] mengerjakan TP1
dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

struct nilaimatkul
{
    char judul[100];
    char bioskop[100];
    char rate[100];
};

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    struct nilaimatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

int i, j;
void createlist(list *L);
int countelemen(list L);
// int emptyelemen(list L);
void addfirst(char judul[], char bioskop[], char rate[], list *L);
void printelemen(struct nilaimatkul list[], int n);
//  void swap(nilaimatkul *a, nilaimatkul *b);
void printdesc(struct nilaimatkul list[], int n);
void selectionLinked(int s, struct nilaimatkul list[]);
void selectionjuduldesc(int s, struct nilaimatkul list[]);
void selectionrateasc(int s, struct nilaimatkul list[]);
void selectionratedesc(int s, struct nilaimatkul list[]);