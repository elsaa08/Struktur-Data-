
/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 2
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/
#include "tepe.h"
int main()
{
    list L;
    createList(&L);
    nilaiMatkul nilai1;

    char nama[50];
    int tgl = 0;

    while (strcmp(nama, "--stop--") != 0)
    {
        scanf("%s", nama); // meminta masukan user berupa nama
        // jika masukan nama bukan berupa kata "--stop--"
        if (strcmp(nama, "--stop--") != 0)
        {
            scanf("%d", &tgl);       // meminta masukan user berupa tanggal
            addFirst(nama, tgl, &L); // memanggil prosedur untuk menambahkan elemen di awal list
        }
    }
    // memanggil mesin prosedur untuk memberikan keluaran
    printf("==== Inventory Dapur ====\n");
    printf("List semua bahan:\n");
    selection_sort(&L);
    printElement(L);
    printf("\n");
    printf("List bahan kadaluarsa:\n");
    sort_k(&L, tgl);
    printnew(L, tgl);

    printf("\n");
    printf("List bahan sisa:\n");
    sort_s(&L, tgl);
    printku(L, tgl);

    printf("=========================\n");

    return 0;
}