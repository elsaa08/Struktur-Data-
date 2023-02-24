/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 2
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/

#include "tepe.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}
int countElement(list L)
{

    int hasil = 0;

    if (L.first != NULL)
    {
        /*list tidak kosong*/

        elemen *bantu;

        /*inisialisasi*/
        bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
    printf("%d\n", hasil);
}

void addFirst(char nama[], int tgl, list *L)
{

    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.tgl = tgl;

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    elemen *hapus = before->next;

    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            before->next = NULL;
            (*L).tail = before;
        }
        else
        {
            before->next = hapus->next;
            hapus->next->prev = before;
            hapus->next = NULL;
        }
        hapus->prev = NULL;
        free(hapus);
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {

            delAfter((*L).tail->prev, L);
        }
    }
}

void delAll(list *L)
{

    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        delLast(L);
    }
}

void printElement(list L)
{
    int n;
    int i;

    if (L.first != NULL)
    {

        elemen *bantu = L.first;
        // i = 1;
        while (bantu != NULL)
        {

            // /*proses*/
            if (bantu->kontainer.tgl < 10) // jika kurang dari 10, seperi 01, 02, 03, 04, 05, 06, 07, 08, 09
            {

                printf("0%d ", bantu->kontainer.tgl); // akan memberi tanda 0
            }
            else
            {
                printf("%d ", bantu->kontainer.tgl);
            }
            printf("%s\n", bantu->kontainer.nama);
            bantu = bantu->next;
            // i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("List Kosong\n");
    }
}

void selection_sort(list *L)
{
    elemen *key, *temp, *before; // elemen untuk penunjuk
    int tukar;
    do
    {              // loop
        tukar = 0; // tukar diisi 0
        // key diisi first element
        key = (*L).first;
        // temp isi elemen nunjukkey
        temp = key->next;

        while (temp != NULL)
        { // selama temp tidak null
            if (key->kontainer.tgl < temp->kontainer.tgl)
            { // tukar pointer next nya dengan prosedur
                pindah_pointer(L, before, key, temp);
                before = temp; // before diisi nilai temp
                tukar = 1;     // tanda telah terjadi penukaran
            }
            else
            {
                // key sekarang jadi before
                before = key;
                // key lanjut maju ke depan
                key = key->next;
            }
            temp = key->next;
        }

    } while (tukar == 1); // terus melooping selama msh trjadi tukar menukar
}

// sort kadaluarsa
void sort_k(list *L, int tgl)
{ // selection sort pada list

    // penjelasannya sama seperti pada sort diatas
    elemen *key, *temp, *before; // elemen untuk penunjuk
    int tukar;
    if (tgl < 9)
    {
        do
        {
            tukar = 0;
            key = (*L).first;
            temp = key->next;

            if (key->kontainer.tgl < temp->kontainer.tgl) // mengurutkan sesuai tanggak dari yang terbesar
            {
                pindah_pointer(L, before, key, temp);
                before = temp;
                tukar = 1;
            }
            else
            {
                before = key;
                key = key->next;
            }
            temp = key->next;
            // }

        } while (tukar == 1);
    }
}
void swapElement(elemen *x, elemen *y)
{
    // coba coba tukar elemem
    char temp[50];
    int temp2;

    // tukar data judul dari elemen yang ditunjuk pointer x dengan yang ditunjuk pointer y
    strcpy(temp, x->kontainer.nama);
    strcpy(x->kontainer.nama, y->kontainer.nama);
    strcpy(y->kontainer.nama, temp);

    // tukar data produksi dari elemen yang ditunjuk pointer x dengan yang ditunjuk pointer y
    (temp2 = x->kontainer.tgl);
    (x->kontainer.tgl = y->kontainer.tgl);
    (y->kontainer.tgl = temp2);
}
void sort_s(list *L, int tgl)
// sorting untuk bahan sisa
{

    elemen *tunjuk = (*L).first;
    // deklarasi pointer temp
    elemen *temp;
    if (tunjuk->kontainer.tgl > 8)
    {
        // perulangan sampai tunjuk null
        while (tunjuk != NULL)
        {
            // pointer temp sama dengan next dari tunjuk
            temp = tunjuk->next;
            // perulangan selama temp bukan null
            while (temp != NULL)
            {

                if (strcmp(tunjuk->kontainer.nama, temp->kontainer.nama) > 0) // sorting sesuai abjad
                {
                    // memanggil prosedur untuk menukarkan elemen
                    swapElement(tunjuk, temp);
                }
                // temp sekarang sama dengan next dari temp sebelumnya
                temp = temp->next;
            }
            // tunjuk sekarang sama dengan next dari tunjuk sebelumya
            tunjuk = tunjuk->next;
        }
    }
}

void pindah_pointer(list *L, elemen *before, elemen *key, elemen *temp)
{ // tukar pointer
  // jika  key ada di first
    if (key == (*L).first)
    {
        // first nunjuk ke temp
        (*L).first = temp;
        // before nunjuk ke first
        before = (*L).first;
    }
    else
    {
        // before next tunjuk ke temp
        before->next = temp;
    }
    // key next tunjuk ke temp next
    key->next = temp->next;
    // temp next tunjuk ke key
    temp->next = key;
}

void printnew(list L, int tgl)
{
    // ini buat print kadaluarsa
    int n;
    int i;

    int ada = 0;

    if (L.first != NULL)
    {
        elemen *bantu = L.first; // elemen ada di first

        i = 1;
        while (bantu != NULL) // tidak null
        {
            if (bantu->kontainer.tgl < 9) // kurang dari 9 list nya ( 9 adalah tgl kadaluarsa )
            {
                ada = 1; // terjadi adanya tukar menukar
                // /*proses*/
                if (bantu->kontainer.tgl < 10) // buat kaya yg tadi biar ada 0 nya di bilangan yg kurang dr 10
                {

                    printf("0%d ", bantu->kontainer.tgl);
                }
                else
                {
                    printf("%d ", bantu->kontainer.tgl);
                }
                printf("%s\n", bantu->kontainer.nama);
            }

            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
        // printf("%d", ada);
        if (ada == 0)
        {
            printf("-\n"); // print strip
        }
    }
}

void printku(list L, int tgl)
// ini buat print list bahan sisa
{
    int n;
    int i;
    // printf("List semua bahan:\n");
    int ada = 0;
    //  sort_s(L, tgl);

    if (L.first != NULL)
    {
        // penjelasannya sama kaya yang diatas
        elemen *bantu = L.first;

        i = 1;
        while (bantu != NULL)
        {

            // /*proses*/
            if (bantu->kontainer.tgl > 8) // ini kalo lebih dari 9 atau sama dengan 9
            {
                ada = 1; // tanda

                if (bantu->kontainer.tgl < 10) // sama ini biar ada 0 nya
                {

                    printf("0%d ", bantu->kontainer.tgl);
                }
                else
                {
                    printf("%d ", bantu->kontainer.tgl);
                }
                printf("%s\n", bantu->kontainer.nama);
            }
            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }

        if (ada == 0)
        {
            printf("-\n");
        }
    }
}
/*
tahu 29
tempe 8
telur 2
buncis 13
Kangkung 11
Wortel 22
Selada 30
Alpukat 9
Susu 8
Santan 2
--stop--


==== Inventory Dapur ====
List semua bahan:
30 Selada
29 tahu
22 Wortel
13 buncis
11 Kangkung
09 Alpukat
08 tempe
08 Susu
02 telur
02 Santan

List bahan kadaluarsa:
08 tempe
08 Susu
02 telur
02 Santan

List bahan sisa:
09 Alpukat
11 Kangkung
30 Selada
22 Wortel
13 buncis
29 tahu
=========================*/
