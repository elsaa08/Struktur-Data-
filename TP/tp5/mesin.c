#include "tp5.h"
/*
Saya Elsa Nabiilah [2108805] mengerjakan Tugas Praktikum 5
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin
*/
void createEmpty(graph *G)
{
    (*G).first = NULL;
}
void addSimpul(char c, graph *G)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;
    if ((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir
        graph*/

        simpul *last = (*G).first;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list
        jalur*/

        jalur *last = awal->arc;

        while (last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }

        last->next_jalur = baru;
    }
}

simpul *findSimpul(char c, graph G)
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;
    while ((bantu != NULL) &&
           (ketemu == 0))
    {
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, simpul *awal)
{
    jalur *hapus = awal->arc;
    if (hapus != NULL)
    {
        jalur *prev = NULL;
        /*mencari jalur yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) &&
               (ketemu == 0))
        {
            if (hapus->tujuan->kontainer == ctujuan)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }

        if (ketemu == 1)
        {
            if (prev == NULL)
            {
                /*hapus jalur pertama*/
                awal->arc = hapus->next_jalur;
                hapus->next_jalur = NULL;
            }
            else
            {
                if (hapus->next_jalur == NULL)
                {
                    /*hapus jalur terakhir*/
                    prev->next_jalur = NULL;
                }
                else
                {
                    /*hapus jalur di tengah*/
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
            free(hapus);
        }
    }
}

void delAll(simpul *awal)
{

    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->arc = bantu;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

void delSimpul(char c, graph *G)
{
    simpul *hapus = (*G).first;
    if (hapus != NULL)
    {
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) &&
               (ketemu == 0))
        {
            if (hapus->kontainer == c)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if (ketemu == 1)
        {
            /* jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain
            yang mengarah pada simpul yang dihapus */

            simpul *bantu;
            bantu = (*G).first;
            /* memeriksa semua simpul dalam graf */
            while (bantu != NULL)
            {
                /* jika simpul yang ditelusuri tidak sama
                dengan yang dihapus */
                if (bantu != hapus)
                {
                    /* hapus semua jalur yang mengarah pada
                    simpul yang dihapus */
                    delJalur(hapus->kontainer, bantu);
                }
                bantu = bantu->next;
            }
            /* hapus semua jalur */
            delAll(hapus);

            if (prev == NULL)
            {
                /*hapus simpul pertama*/
                (*G).first = hapus->next;
                hapus->next = NULL;
            }
            else
            {
                if (hapus->next == NULL)
                {
                    /*hapus simpul terakhir*/
                    prev->next = NULL;
                }
                else
                {
                    /*hapus simpul di tengah*/
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
    }
}

void printGraph(graph G)
{
    simpul *bantu = G.first;
    if (bantu != NULL)
    {
        while (bantu != NULL)
        {
            printf("Node %c\n", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;
            while (bantu_jalur != NULL)
            {
                printf("- Jalur %c ke %c\n", bantu->kontainer, bantu_jalur->tujuan->kontainer);
                bantu_jalur = bantu_jalur->next_jalur;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("graf kosong\n");
    }
}

void DFS(char ctujuan, simpul *awal, graph G, int i, int beban, char simpen[])
{
    jalur *find = awal->arc; // deklar dan isi menjadi simpul awal (arah simpul awal)
    // simpul awal(finish state) inputan yang akan diitung jaraknya
    simpen[i] = awal->kontainer; // ini tuh kaya inisialisasi makanya di pakein array of char simpen[i]
    // tutup sama '\0'
    simpen[i + 1] = '\0';
    // increment
    i++;
    // i itu jalur yg telah dilalui

    if (awal->kontainer == ctujuan) // jika simpul awal sama dengan simpul tujuan
    {
        // beban = 0;
        for (int j = 0; j < i; j++) // looping sepanjang i (jalur yg udah dilalui)
        {
            // nah print apaaja jalur nya
            printf("%c ", simpen[j]); // print char yg sudah disimpen dalam variabel simpen
        }
        // ini buat print beban sebanyak jalur yg udah ditempuh
        printf("%d\n", beban);
    }
    else
    { // jika tidak
        while (find != NULL)
        {

            // beban setiap jalur saling total (ditambahin total beban jalur yg sdh ditempuh)
            beban = beban + find->kontainer_jalur;
            //    printf("bbt %d\n", beban);
            // cari ulang si awal
            awal = findSimpul(find->tujuan->kontainer, G);
            // rekursif prosedur ini
            DFS(ctujuan, awal, G, i, beban, simpen);
            // kan yang beban = beban +find->kontainerjalur itu ngelooping bobot yang udah dilalui sebelumnya
            // ini biar yang bobot sebelumnya gak ikut ke totalin lagi jadi di bikin kebalikannya (dikurangi)
            // karna direkursif jadi ke looping ulang
            beban = beban - find->kontainer_jalur;
            // ini biar terus maju, nunjuk setelah nya
            find = find->next_jalur;
        }
    }
}