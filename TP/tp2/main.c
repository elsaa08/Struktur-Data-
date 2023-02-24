#include "tp2.h"

int main()
{
    list L;
    createList(&L);
    nilaiMatkul nilai1;

    char nama[50];
    int tgl = 0;
    // scanf("%s %s", &nilai1.tgl, &nilai1.nama);
    // addFirst(tgl, nama, &L);
    // int i = 0, n = 0;

    while (strcmp(nama, "--stop--") != 0)
    {
        // i++;
        scanf("%s", nama); // meminta masukan user judul film/serial TV
        // jika masukan judul bukan tanda "-"
        if (strcmp(nama, "--stop--") != 0)
        {
            scanf("%d", &tgl); // meminta masukan user produksi film/serial TV
                               // memanggil prosedur untuk menambahkan elemen di awal list
                               // addbefore(tgl, nama, &L);
            addFirst(nama, tgl, &L);
        }

        //  n++;
    }
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