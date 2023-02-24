#include "tp2.h"

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
    // elemen *baru;
    // baru = (elemen *)malloc(sizeof(elemen));
    // strcpy(baru->kontainer.tgl, tgl);
    // strcpy(baru->kontainer.nama, nama);
    // // strcpy(baru->kontainer.nilai, nilai);
    // if ((*L).first == NULL)
    // {

    //     baru->prev = NULL;
    //     baru->next = NULL;

    //     (*L).tail = baru;
    // }
    // else
    // {
    //     baru->next = (*L).first;
    //     baru->prev = NULL;

    //     (*L).first->prev = baru;
    // }
    // (*L).first = baru;
    // baru = NULL;
    elemen *baru;                            // pointer elemen baru
    baru = (elemen *)malloc(sizeof(elemen)); // siapkan elemen baru
    strcpy(baru->kontainer.nama, nama);      // isi elemen
    baru->kontainer.tgl = tgl;
    // baru->container.rating = rating;
    if ((*L).first == NULL)
    {                      // jika pointer first null
        baru->next = NULL; // maka pointer next element new null
    }
    else
    {
        baru->next = (*L).first; // pointer next elemen baru menunjuk ke elemen milik pointer first
    }
    (*L).first = baru; // pointer first diinisialisasi oleh elemen baru
    baru = NULL;       // mengosongkan pointer baru
}

// void addAfter(elemen *before, char tgl[], char nama[], list *L)
// {

//     if (before != NULL)
//     {
//         elemen *baru;
//         baru = (elemen *)malloc(sizeof(elemen));
//         strcpy(baru->kontainer.tgl, tgl);
//         strcpy(baru->kontainer.nama, nama);
//         // strcpy(baru->kontainer.nilai, nilai);
//         if (before->next == NULL)
//         {

//             baru->next = NULL;
//             (*L).tail = baru;
//         }
//         else
//         {
//             baru->next = before->next;
//             baru->next->prev = baru;
//         }
//         baru->prev = before;
//         before->next = baru;
//         baru = NULL;
//     }
// }

// void addbefore(elemen *before, char tgl[], char nama[], list *L)
// {
//     before != NULL;
//     addAfter(before->prev, tgl, nama, L);
// }

// void addLast(char tgl[], char nama[], list *L)
// {

//     if ((*L).first == NULL)
//     {
//         /*proses jika list masih kosong*/
//         addFirst(tgl, nama, L);
//     }
//     else
//     {
//         /*proses jika list telah berisi elemen*/
//         addAfter((*L).tail, tgl, nama, L);
//     }
// }
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
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
// void swapElement(elemen *x, elemen *y)
// {
//     char temp[100];
//     char temp2[100];

//     // tukar data judul dari elemen yang ditunjuk pointer x dengan yang ditunjuk pointer y
//     strcpy(temp, x->kontainer.tgl);
//     strcpy(x->kontainer.tgl, y->kontainer.tgl);
//     strcpy(y->kontainer.tgl, temp);

//     // tukar data produksi dari elemen yang ditunjuk pointer x dengan yang ditunjuk pointer y
//     strcpy(temp2, x->kontainer.nama);
//     strcpy(x->kontainer.nama, y->kontainer.nama);
//     strcpy(y->kontainer.nama, temp2);
// }
// void sorting_asc(elemen *before, char tgl[], char nama[], list *L)
// {

//     elemen *bantu = (*L).first;

//     elemen *temp2;

//     // perulangan sampai tunjuk null
//     while (bantu != NULL)
//     {
//         // pointer temp sama dengan next dari tunjuk
//         temp2 = bantu->next;
//         // perulangan selama temp bukan null
//         while (temp2 != NULL)
//         {
//             // for (i = 0; i < n; i++)
//             // {

//             if (strcmp(bantu->kontainer.nama, temp2->kontainer.nama) > 0)
//             {
//                 // memanggil prosedur untuk menukarkan elemen
//                 swapElement(bantu, temp2);
//                 //  addbefore(before->next, tgl, nama, L);
//             }
//             //}

//             temp2 = temp2->next;
//         }
//         // tunjuk sekarang sama dengan next dari tunjuk sebelumya
//         bantu = bantu->next;
//         // bantu->next = bantu->next;
//         // bantu->next->prev = bantu;
//     }
//}
void printElement(list L)
{
    int n;
    int i;
    // printf("List semua bahan:\n");
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen *bantu = L.first;
        // i = 1;
        while (bantu != NULL)
        {

            // /*proses*/
            if (bantu->kontainer.tgl < 10)
            {

                printf("0%d ", bantu->kontainer.tgl);
            }
            else
            {
                printf("%d ", bantu->kontainer.tgl);
            }
            printf("%s\n", bantu->kontainer.nama);
            // printf("%s\n", bantu->kontainer.nilai);
            // }

            /*iterasi*/
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
{                                // selection sort pada list
    elemen *key, *temp, *before; // elemet untuk penunjuk
    int tukar;                   // variabel penanda loop
    do
    {                     // loop
        tukar = 0;        // tukar diisi 0
        key = (*L).first; // key diisi first element
        temp = key->next; // temp isi elemen setelah key

        // sort berdasarkan title ascending
        while (temp != NULL)
        { // selama temp tidak null
            if (key->kontainer.tgl < temp->kontainer.tgl)
            {                                         // kondisi sort
                pindah_pointer(L, before, key, temp); // saling tukar pointer next nya dengan prosedur
                before = temp;                        // before diisi nilai temp
                tukar = 1;                            // tandai terjadi penukaran
            }
            else
            {                    // jika tidak
                before = key;    // key sekarang jadi before
                key = key->next; // key lanjut maju ke depan
            }
            temp = key->next; // temp maju di depan key
        }

    } while (tukar == 1); // looping trus selama masih ada proses penukaran
}

void sort_k(list *L, int tgl)
{ // selection sort pada list
  // elemen *key, *temp, *before;
  // int i = 0, n;

    // if (tgl < 9)
    // {
    //     delAfter((*L).first->prev, L);
    //     i = i + 1;
    //     printf("%d", i);
    // }
    elemen *key, *temp, *before; // elemet untuk penunjuk
    int tukar;
    if (tgl < 9)
    { // variabel penanda loop
        do
        {                     // loop
            tukar = 0;        // tukar diisi 0
            key = (*L).first; // key diisi first element
            temp = key->next; // temp isi elemen setelah key

            // dellall()
            //  sort berdasarkan title ascending
            // while (temp != NULL)
            // { // selama temp tidak null

            if (strcmp(key->kontainer.nama, temp->kontainer.nama) < 0)
            {                                         // kondisi sort
                pindah_pointer(L, before, key, temp); // saling tukar pointer next nya dengan prosedur
                before = temp;                        // before diisi nilai temp
                tukar = 1;                            // tandai terjadi penukaran
            }
            else
            {                    // jika tidak
                before = key;    // key sekarang jadi before
                key = key->next; // key lanjut maju ke depan
            }
            temp = key->next; // temp maju di depan key
            // }

        } while (tukar == 1);
    }
}

void sort_s(list *L, int tgl)
{

    // selection sort pada list
    elemen *key, *temp, *before; // elemet untuk penunjuk
    int tukar;
    if (tgl >= 9)
    { // variabel penanda loop
        do
        {                     // loop
            tukar = 0;        // tukar diisi 0
            key = (*L).first; // key diisi first element
            temp = key->next; // temp isi elemen setelah key

            // dellall()
            //  sort berdasarkan title ascending
            // while (temp != NULL)
            // { // selama temp tidak null

            if (strcmp(key->kontainer.nama, temp->kontainer.nama) < 0)
            {                                         // kondisi sort
                pindah_pointer(L, before, key, temp); // saling tukar pointer next nya dengan prosedur
                before = temp;                        // before diisi nilai temp
                tukar = 1;                            // tandai terjadi penukaran
            }
            else
            {                    // jika tidak
                before = key;    // key sekarang jadi before
                key = key->next; // key lanjut maju ke depan
            }
            temp = key->next; // temp maju di depan key
                              // }

        } while (tukar == 1);
    }
}

void pindah_pointer(list *L, elemen *before, elemen *key, elemen *temp)
{ // tukar pointer
    if (key == (*L).first)
    {                        // jika  key masih di first
        (*L).first = temp;   // first tunjuk ke temp
        before = (*L).first; // before tunjuk ke first
    }
    else
    {                        // jika tidak
        before->next = temp; // before next tunjuk ke temp
    }
    key->next = temp->next; // key next tunjuk ke temp next
    temp->next = key;       // temp next tunjuk ke key
}
void printnew(list L, int tgl)
{
    int n;
    int i;

    int ada = 0;

    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen *bantu = L.first;

        i = 1;
        while (bantu != NULL)
        {
            if (bantu->kontainer.tgl < 9)
            {
                ada = 1;
                // /*proses*/
                if (bantu->kontainer.tgl < 10)
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
            printf("-\n");
        }
    }
}

void printku(list L, int tgl)
{
    int n;
    int i;
    // printf("List semua bahan:\n");
    int ada = 0;
    //  sort_s(L, tgl);

    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/

        if (tgl >= 9)
        {
            ada = 1;
            elemen *bantu = L.tail;

            i = 1;
            while (bantu != NULL)
            {

                // /*proses*/

                if (bantu->kontainer.tgl < 10)
                {

                    printf("0%d ", bantu->kontainer.tgl);
                }
                else
                {
                    printf("%d ", bantu->kontainer.tgl);
                }
                printf("%s\n", bantu->kontainer.nama);

                /*iterasi*/
                bantu = bantu->prev;
                i = i + 1;
            }
        }

        if (ada == 0)
        {
            printf("-\n");
        }
    }
}
