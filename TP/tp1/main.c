
#include "tp1.h"
/*
Saya Elsa Nabiilah [2108805] mengerjakan TP1
dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

int main()
{
    list L;                       // memanggil list
    createlist(&L);               // memanggil createlist
    struct nilaimatkul film[100]; // memanggil struct
    // deklarasi untuk jenis sorting
    char jenis[100];
    char sort[100];
    int n = 0, i = 0;
    while (strcmp(film[i].judul, "-") != 0 && (i < 100)) // jika judul belum mengandung masukan "-"
    {
        i++;
        scanf("%s", &film[i].judul);         // meminta masukan
        if (strcmp(film[i].judul, "-") != 0) // agar strip satu kali
        {
            scanf("%s", &film[i].bioskop);
            scanf("%s", &film[i].rate);
        }
        addfirst(film[i].judul, film[i].bioskop, film[i].rate, &L); // memanggil list addfirst
        n++;
    }
    // tentukan jenis sorting
    scanf("%s", jenis);
    scanf("%s", sort);

    if (strcmp(jenis, "judul") == 0) // jika sorting judul
    {
        if (strcmp(sort, "asc") == 0) // jika ascending
        {
            selectionLinked(n, film); // memanggil mesin sorting
            printelemen(film, n);     // inputan
        }
        else
        {
            selectionjuduldesc(n, film); // jika descending
            printdesc(film, n);          // memanggil inputan untuk descending
        }
    }
    else if (strcmp(jenis, "rating") == 0) // sorting ratingnya
    {
        if (strcmp(sort, "asc") == 0) // jika ascending
        {
            selectionrateasc(n, film); // memanggil mesin sorting ascending
            printelemen(film, n);      // output untuk asc
        }
        else
        {
            selectionratedesc(n, film); // memanggil mesin sort desc
            printdesc(film, n);         // output desc
        }
    }

    return 0;
}