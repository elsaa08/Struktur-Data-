#include "tp4.h"

int main()
{
    tree T;
    char cek[100];
    char tanda[100];
    //  char uyut[100];
    char nn[100];

    data input;
    simpul *simpen;
    simpul *simpendel;
    // data MT;
    // data anak;
    // data anak2;
    // scanf("%s", &cek);
    int o,
        p;
    int n;       // variabel banyak huruf dari kata utama
    int k;       // variabel banyak huruf dari kata kunci
    int i, j, m; // variabel untuk membantu proses perulangan
    int jk;

    n = 0;
    i = 1;
    while ((strcmp(input.nama, "DONE;") != 0) && (i < 100))
    {
        // i++;
        scanf("%s", &input.nama);
        if (strcmp(input.nama, "MAKETREE") == 0)
        {
            scanf("%s", &input.child);
            char *hilang = strtok(input.child, ";");
            makeTree(input, &T);
        }
        else if (strcmp(input.nama, "CHILD") == 0)
        {
            scanf("%s %s", &input.child, &input.ortu);
            char *ilang = strtok(input.ortu, ";");

            strcpy(input.ortu, ilang);
            simpen = findSimpul(input.ortu, T.root);
            addChild(input, simpen);
        }
        else if (strcmp(input.nama, "PREORDER;") == 0)
        {
            printf("Output %d:", i);
            printf("\n=========\n");
            printTreePreOrder(T.root);
            i++;
        }

        else if (strcmp(input.nama, "DELLCHILD") == 0)
        {
            // simpul *temp;
            scanf("%s %s", input.child, input.ortu);
            char *temp = strtok(input.ortu, ";");
            simpendel = findSimpul(temp, T.root);
            delChild(input.child, simpendel);
        }
    }
    // printf("=========\n");
    printf("=========\n");

    return 0;
}

/*
=================
preOrder
 A  B  E  F  C  G  D  H  I  J  K  L  M
=================
postOrder
 E  F  B  G  C  H  I  K  L  M  J  D  A
=================
pohon sama
=================
preOrder setelah dihapus
 A  B  E  F  C  G  D  H  I  J
=================
1
*/