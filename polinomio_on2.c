#include <stdio.h>

double polinomio(int n, double a[], double x) {
    double soma = 0;
    int i, j;

    for(i = 0; i < n; i++) {

        double pot = 1;

        for(j = 0; j < i; j++) {
            pot *= x;
        }

        soma += a[i] * pot;
    }

    return soma;
}

int main() {

    double a[] = {1, 2, 3};
    double x = 2;

    double resultado = polinomio(3, a, x);

    printf("Resultado: %.2lf\n", resultado);

    return 0;
}