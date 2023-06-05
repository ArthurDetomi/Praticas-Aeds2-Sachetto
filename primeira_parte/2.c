#include <stdio.h>

int main(void) {
    int num;
    do {
        printf("Digite um numero:");
        scanf("%d", &num);
    } while (num <= 0);

    int soma = 0;
    for (int i = 2; i <= num; i += 2) {
        if (num % i == 0) {
            printf("num divisivel = %d\n", i);
            soma += i;
        }
    }

    printf("A soma dos numeros pares divisiveis = %d\n", soma);
}
