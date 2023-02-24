#include "tp3.h"
/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 3
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/
void createEmpty(stack *S)
{

    (*S).top = NULL;
}

int isEmpty(stack S) // stack kosong / ngga
{

    int hasil = 0;
    if (S.top == NULL) // top atas null
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{

    int hasil = 0;

    if (S.top != NULL)
    {

        /* stack tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = S.top;

        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(nilaimatkul input, stack *S) // memasukan data kedalam stack
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    // pindah pointer

    baru->kontainer = input;
    if ((*S).top == NULL) // kosong
    {
        // jika stack kosong
        baru->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S) // ngeluarin data nya
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top; // delete tunjuk top
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}

void printStack(stack S) // PRINT STACK UNTUK ROCK
{
    if (S.top != NULL) // jika tidak nol
    {
        elemen *bantu = S.top; // memanggil elemen bantu (kontainer)
        int i = 1;             // inisialisasi buat nomor
        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.judul); // output
            bantu = bantu->next;
            i++; // iterasi
        }
    }
    else
    {
        printf("BUKAN ANAK ROCK!\n"); // disini bedanya, biar pake else "bukan anak rock" kalo isi stack kosong
    }
}
void printStackpop(stack S)
{

    if (S.top != NULL)
    {

        elemen *bantu = S.top;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.judul);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("BUKAN ANAK POP!\n"); // ini juga biar nge print "bukan anak kpop" kalo list pop kosong
        // isi kodingannya sama persis sama print yang rock
    }
}

int total_ascii(char judul[])
{
    //|||| N G I T U N G   A S C I I |||||
    int count = 0; // set = 0 biar aman
    int j;

    for (int i = 0; i < strlen(judul); i++)
    {
        count += judul[i]; // mentotalkan jumlah ascii di satu kalimat string
    }
    return count; // mengembalikan nilai count
}

void stackAll(stack *S, stack *s2, stack *s3) // semua stack
{
    if ((*S).top != NULL)
    { // jika tdk kosong
        // jika stack tidak kosong
        elemen *pindah = (*S).top;
        while (pindah != NULL)
        {
            if (total_ascii(pindah->kontainer.judul) % 2 == 0) // jika genap
            {
                push(pindah->kontainer, s2); // nge push rock
            }
            else // jika ganjil
            {
                push(pindah->kontainer, s3); // nge push pop
            }
            pindah = pindah->next; // pointer maju
        }
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}