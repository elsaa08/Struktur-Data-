#include "tp1.h"

/*
Saya Elsa Nabiilah [2108805] mengerjakan TP1
dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

void createlist(list *L)
{
    (*L).first = NULL;
}

int countelemen(list L)
{
    int hasil = 0;
    if ((L.first, "-") != 0)
    {
        // list tdk kosong
        elemen *tunjuk;

        // inisialisasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            // proses
            hasil = hasil + 1;
            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addfirst(char judul[], char bioskop[], char rate[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.bioskop, bioskop);
    strcpy(baru->kontainer.rate, rate);

    if ((*L).first == NULL)
    {
        // jika list kosong (Addfirst)
        baru->next = NULL;
    }
    else
    {
        // jika list tidak kosong
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru == NULL;
}

void printelemen(struct nilaimatkul list[100], int n)
{
    int i, j;

    for (i = 1; i < n; i++) // looping agar tidak membawa si strip
    {
        printf("%s - %s\n", list[i].judul, list[i].bioskop); // output
    }
}
void printdesc(struct nilaimatkul list[100], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++) // printf untuk desc agar strip paling akhir gak ikutan
    {
        printf("%s - %s\n", list[i].judul, list[i].bioskop);
    }
}

void selectionLinked(int s, struct nilaimatkul list[100]) // sorting
{
    int i, j;
    struct nilaimatkul temp;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s - i; j++)
        {

            while ((strcmp(list[j].judul, list[j + 1].judul) > 0)) // jika indeks pertama lebih kecil
            {
                // copy copy
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void selectionjuduldesc(int s, struct nilaimatkul list[100])
{
    int i, j;
    struct nilaimatkul temp;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s - i; j++)
        {

            while (strcmp(list[j].judul, list[j + 1].judul) < 0) // jika lebih kecil
            {
                // copy disini yach
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void selectionrateasc(int s, struct nilaimatkul list[100]) // sorting rating
{
    int i, j;
    struct nilaimatkul temp;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s - i; j++)
        {

            while ((strcmp(list[j].rate, list[j + 1].rate) > 0)) // dari kecil ke besar
            {
                // coppy disini

                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void selectionratedesc(int s, struct nilaimatkul list[100])
{
    int i, j;
    struct nilaimatkul temp;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s - i; j++)
        {

            while (strcmp(list[j].rate, list[j + 1].rate) < 0) // kecil ke besar
            {
                // copy yahh
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
