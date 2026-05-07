#include <stdio.h>

double horner(int n, double a[], double x) {

    double resultado = a[n - 1];
    int i;

    for(i = n - 2; i >= 0; i--) {
        resultado = resultado * x + a[i];
    }

    return resultado;
}

int main() {

    double a[] = {1, 2, 3};
    double x = 2;

    double resultado = horner(3, a, x);

    printf("Resultado: %.2lf\n", resultado);

    return 0;
}   