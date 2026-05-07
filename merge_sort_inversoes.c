#include <stdio.h>

int merge(int v[], int temp[],
          int esquerda,
          int meio,
          int direita) {

    int i = esquerda;
    int j = meio;
    int k = esquerda;
    int inversoes = 0;

    while(i <= meio - 1 && j <= direita) {

        if(v[i] <= v[j]) {
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j++];
            inversoes += (meio - i);
        }
    }

    while(i <= meio - 1)
        temp[k++] = v[i++];

    while(j <= direita)
        temp[k++] = v[j++];

    for(i = esquerda; i <= direita; i++)
        v[i] = temp[i];

    return inversoes;
}

int mergeSort(int v[],
              int temp[],
              int esquerda,
              int direita) {

    int meio;
    int inversoes = 0;

    if(direita > esquerda) {

        meio = (direita + esquerda) / 2;

        inversoes += mergeSort(v,
                               temp,
                               esquerda,
                               meio);

        inversoes += mergeSort(v,
                               temp,
                               meio + 1,
                               direita);

        inversoes += merge(v,
                           temp,
                           esquerda,
                           meio + 1,
                           direita);
    }

    return inversoes;
}

int main() {

    int v[] = {2, 3, 8, 6, 1};

    int n = 5;

    int temp[5];

    int inversoes = mergeSort(v,
                              temp,
                              0,
                              n - 1);

    printf("Numero de inversoes: %d\n",
           inversoes);

    return 0;
}   