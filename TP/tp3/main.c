#include "tp3.h"

/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 3
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

int main()
{
    // membuat stack
    stack S;           // untuk stack seluruh
    stack s2;          // stack lagu rock
    stack s3;          // stack lagu pop
    nilaimatkul input; // nemanggil struct

    createEmpty(&S);  // seluruh
    createEmpty(&s2); // rock
    createEmpty(&s3); // pop

    int n;
    int i;
    scanf("%d", &n); // memasukan batasan looping
    for (i = 0; i < n; i++)
    {

        scanf("%s", &input.tahun); // inputan 1
        scanf("%s", &input.judul); // inputan judul (2)
        scanf("%s", &input.nama);  // inputan 3 (idol)
        push(input, &S);           // memasukan data atau push ALL
    }

    stackAll(&S, &s2, &s3); // memanggil isi semua stack yang sudah di proses oleh if else (genap ganjil)

    /*|||| O U T P U T |||| */
    printf("Playlist Musik Rock:\n");
    printf("===================\n");
    printStack(s2); // memanggil stack 2 (rock)

    printf("\n");
    printf("Playlist Musik Pop:\n");
    printf("===================\n");
    printStackpop(s3); // memanggil stack 3 (pop)

    return 0;
}