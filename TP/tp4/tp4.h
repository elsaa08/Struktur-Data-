#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[100];
    char child[100];
    // int nilai;
    char ortu[100];
    // char cek[100];
} data;
typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[100];
    alamatsimpul sibling;
    alamatsimpul child;
    int pointer;
} simpul;

typedef struct
{
    simpul *root;
} tree;

// extern int idx, wlen; // untuk indeks satuan char dari pita(string)
// extern char cw[52];   // untuk satuan char

// void start(char str[]);
// void reset(); // tombol mesin start
// int eop(char str[]);

// void inc(char str[]);
// // void adv(char str[]);

// int getlen();  // fungsi untuk mendapatkan indeks
// char *getcw(); // fungsi untuk mendapatkan char

void makeTree(data input, tree *T);
void addChild(data input, simpul *root);
void delAll(simpul *root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char input[], simpul *root);
void printTreePreOrder(simpul *root);
int count(simpul *root, int tmp);
// void printTreePostOrder(simpul *root, int *n);
// void copyTree(simpul *root1, simpul **root2);
// int isEqual(simpul *root1, simpul *root2);
