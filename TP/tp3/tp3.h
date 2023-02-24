#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 3
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

typedef struct
{
    char tahun[100];
    char judul[100], nama[100];
} nilaimatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaimatkul kontainer;
    // nilaimat kontainer2;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(nilaimatkul input, stack *S);
void pop(stack *S);
int total_ascii(char judul[]);
void printStack(stack S);
void printStackpop(stack S);
void stackAll(stack *S1, stack *S2, stack *S3);
