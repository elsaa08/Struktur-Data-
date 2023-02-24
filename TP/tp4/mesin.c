#include "tp4.h"

// void start(char str[]) // prosedur untuk start
// {                      // deklarasi nilai awal
//     idx = 0;
//     wlen = 0;
//     // cc = str[0];

//     while (str[idx] == ' ')
//     {
//         idx++;
//     }

//     while ((str[idx] != ' ') && (eop(str) == 0))
//     {
//         cw[wlen] = str[idx];
//         idx++;
//         wlen++;
//     }
//     cw[wlen] = '\0';
// };

// void reset()
// {
//     wlen = 0;
//     cw[wlen] = '\0';
// }

// int eop(char str[]) // untuk fungsi eop
// {
//     if (str[idx] == ';') // jika sama dengan . dan \0
//     {
//         return 1; // mengembalikan nilai 1
//     }
//     else
//     {
//         return 0; // jika tidak mengembalikan nilai 0
//     }
// }

// void inc(char str[]) // prosedur inc
// {
//     wlen = 0;

//     while (str[idx] == ' ')
//     {
//         idx++;
//     }

//     while ((str[idx] != ' ') && (str[idx] != ';'))
//     {
//         cw[wlen] = str[idx];
//         idx++;
//         wlen++;
//     }
//     cw[wlen] = '\0';
// }

// int getlen() // untuk indeks angka(urutan)
// {
//     return wlen;
// }

// char *getcw() // untuk indeks char (Satuan)
// {
//     return cw;
// // }
void makeTree(data input, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer, input.child);
    // strcpy(node->kontainer, input.nilai);

    // node->kontainer.nilai == input.nilai;
    node->sibling = NULL;
    node->child = NULL;
    node->pointer = 0;
    (*T).root = node;
}

void addChild(data input, simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
        */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->pointer = root->pointer + 1;
        // baru->kontainer = input;
        strcpy(baru->kontainer, input.child);

        // baru->pointer++;
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */

            baru->sibling = NULL;
            root->child = baru;
        }
        else // ada child
        {
            if (root->child->sibling == NULL) // kondisi anaknya satu
            {
                /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else // anak banyak
            {
                simpul *last = root->child;
                // cari anak terakhir (siblingnya anak pertama)
                /* mencari simpul anak terakhir
                karena akan dikaitkan dengan simpul
                baru sebagai simpul anak terakhir yang
                baru, simpul anak terakhir adalah yang
                memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul
                anak terakhir, penunjuk last akan
                berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child);
                free(root);
            }
            simpul *bantu;
            simpul *proses;
            bantu = root->child;
            while (bantu->sibling != root->child)
            {
                proses = bantu;
                bantu = bantu->sibling;
                delAll(proses);
            }
        }
        free(root);
    }
    else
    {
        free(root);
    }
}
void delChild(char c[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (strcmp(root->child->kontainer, c) == 0)
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul
                anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (strcmp(hapus->kontainer, c) == 0)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /*memproses simpul anak terakhir karena
belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus
                        anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak
                            lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last == hapus))
                        // if ((prev == root->child) && (last->sibling == root->child))
                        {
                            /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */

                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua
                            simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul *findSimpul(char input[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer, input) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer, input) == 0)
                    {

                        hasil = bantu;
                    }

                    else
                    {

                        hasil = findSimpul(input, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(bantu->kontainer, input) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(input, bantu);
                            if (hasil != NULL)
                            {
                                ketemu = 1;
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer, input) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil =
                                findSimpul(input, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}
// simpul *findSimpul(data input, simpul *root)
// {

//     simpul *hasil = NULL;
//     if (root != NULL)
//     {
//         if (root->kontainer.nama == input.)
//         {
//             hasil = root;
//         }
//         else
//         {

//             simpul *bantu = root->child;
//             if (bantu != NULL)
//             {
//                 if (bantu->sibling == NULL)
//                 {
//                     /*jika memiliki satu simpul anak*/
//                     if (bantu->kontainer.a == input.a)
//                     {
//                         hasil = bantu;
//                     }
//                     else
//                     {
//                         hasil = findSimpul(input, bantu);
//                     }
//                 }
//                 else
//                 {

//                     /*jika memiliki banyak simpul anak*/
//                     int ketemu = 0;
//                     while ((bantu->sibling != root->child) && (ketemu == 0))
//                     {
//                         if (bantu->kontainer.a == input.a)
//                         {
//                             hasil = bantu;
//                             ketemu = 1;
//                         }
//                         else
//                         {
//                             hasil = findSimpul(input, bantu);
//                             if (hasil != NULL)
//                             {
//                                 ketemu = 1
//                             }
//                             bantu = bantu->sibling;
//                         }
//                     }

//                     /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                     if (ketemu == 0)
//                     {
//                         if (bantu->kontainer.a == input.a)
//                         {
//                             hasil = bantu;
//                         }
//                         else
//                         {
//                             hasil = findSimpul(input, bantu);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return hasil;
// }
int count(simpul *root, int tmp)
{
    if (root != NULL)
    {

        tmp = tmp + 1;
        tmp = count(root->child, tmp);
        tmp = count(root->sibling, tmp);
    }
    return tmp;
}
void printTreePreOrder(simpul *root)
{

    if (root != NULL)
    {

        for (int i = 0; i < root->pointer; i++)
        {
            printf("->");
        }
        printf("%s\n", root->kontainer);
        // if (*n != 1)
        // {
        //     printf("-");
        //     *n = *n - 1;
        // }

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/

                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/
                printTreePreOrder(bantu);
            }
        }
    }
}

// void printTreePostOrder(simpul *root, int *n)
// {

//     if (root != NULL)
//     {
//         simpul *bantu = root->child;

//         if (bantu != NULL)
//         {
//             if (bantu->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 printTreePostOrder(bantu, n);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul
//                 anak*/
//                 /*mencetak simpul anak*/
//                 while (bantu->sibling !=
//                        root->child)
//                 {
//                     printTreePostOrder(bantu, n);
//                     bantu = bantu->sibling;
//                 }
//                 /*memproses simpul anak
// terakhir karena belum terproses
// dalam pengulangan*/

//                 printTreePostOrder(bantu, n);
//             }
//         }
//         // printf("%s %d-", root->kontainer.nama, root->kontainer.nilai);
//         printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
//         if (*n != 1)
//         {
//             printf("-");
//             *n = *n - 1;
//         }
//     }
// }

// void copyTree(simpul *root1, simpul **root2)
// {
//     if (root1 != NULL)
//     {
//         (*root2) = (simpul *)malloc(sizeof(simpul));
//         (*root2)->kontainer = root1->kontainer;
//         (*root2)->sibling = NULL;
//         (*root2)->child = NULL;
//         if (root1->child != NULL)
//         {
//             if (root1->child->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 copyTree(root1->child, &(*root2)->child);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 simpul *bantu1 = root1->child;
//                 simpul *bantu2 = (*root2)->child;

//                 while (bantu1->sibling != root1->child)
//                 {
//                     copyTree(bantu1, &bantu2);
//                     bantu1 = bantu1->sibling;
//                     bantu2 = bantu2->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena
//                 belum terproses dalam pengulangan*/
//                 copyTree(bantu1, &bantu2);
//             }
//         }
//     }
// }

// int isEqual(simpul *root1, simpul *root2)
// {
//     int hasil = 1;
//     if ((root1 != NULL) && (root2 != NULL))
//     {
//         if (strcmp(root1->kontainer.nama, root2->kontainer.nama) != 0)
//         {
//             hasil = 0;
//         }
//         else
//         {
//             if ((root1->child != NULL) && (root2->child != NULL))
//             {
//                 if (root1->child->sibling == NULL)
//                 {
//                     /*jika memiliki satu simpul anak*/
//                     hasil =
//                         isEqual(root1->child,
//                                 root2->child);
//                 }
//                 else
//                 {
//                     /*jika memiliki banyak simpul
//                     anak*/
//                     simpul *bantu1 = root1->child;
//                     simpul *bantu2 = root2->child;

//                     while (bantu1->sibling != root1->child)
//                     {
//                         if ((bantu1 != NULL) && (bantu2 != NULL))
//                         {
//                             hasil = isEqual(bantu1, bantu2);
//                             bantu1 = bantu1->sibling;
//                             bantu2 = bantu2->sibling;
//                         }
//                         else
//                         {
//                             hasil = 0;

//                             break;
//                         }
//                     }
//                     /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                     hasil = isEqual(bantu1, bantu2);
//                 }
//             }
//         }
//     }
//     else
//     {
//         if ((root1 != NULL) ||
//             (root2 != NULL))
//         {
//             hasil = 0;
//         }
//     }
//     return hasil;
// }
