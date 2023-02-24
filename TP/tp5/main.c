#include "tp5.h"
/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 5
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/
int main()
{
    graph G;          // panggil struct Graph
    char awal, akhir; // variabel inputan
    int beban = 0;
    createEmpty(&G); // buat graph kosong
    char n;
    int i;
    char temp[100]; // buat simpen

    // buat simpul (manggil pass by reference)
    simpul *begin;
    simpul *end;
    simpul *test;

    char input1, input2;
    scanf("%d", &n);            // ada berapa simpul?
    for (int i = 0; i < n; i++) // looping sebanyak simpul yang diinginkan user
    {
        scanf(" %c %c %d", &awal, &akhir, &beban); // inputan simpul jalur awal dan akhir beserta beban
        test = findSimpul(awal, G);                // cari simpul awal

        if (test == NULL)
        {
            addSimpul(awal, &G); // add awal
        }

        test = findSimpul(akhir, G); // cari simpul akhir
        if (test == NULL)            // jika masih null
        {
            addSimpul(akhir, &G); // add jadi simpul akhir
        }

        begin = findSimpul(awal, G); // set inputan yang awal menjadi begin
        end = findSimpul(akhir, G);  // set inputan akhir menjadi simpul end (tujuan)
        if (begin != NULL && end != NULL)
        {
            addJalur(begin, end, beban); // jadiin jalur
        }
    }

    // printGraph(G);
    scanf(" %c %c", &awal, &akhir); // meminta masukan simpul jalur yg ingin dicari
    begin = findSimpul(awal, G);    // set begin

    beban = 0;                            // set beban menjadi 0
    DFS(akhir, begin, G, i, beban, temp); // manggil prosedur
    end = findSimpul(akhir, G);           // akhiri dengan end
    return 0;
}