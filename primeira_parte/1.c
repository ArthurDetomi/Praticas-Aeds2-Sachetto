#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int num;
    bool ehprimo = true;

    // Só irá permitir números positivos
    do {
        printf("Digite um numero positivo:");
        scanf("%d", &num);
    } while (num <= 0);

    if (num > 3 || num % 2 != 0) {
        for (int i = num - 1; i > 2; i--) {
            if (num % i == 0) {
                ehprimo = false;
                break;
            }
        }
    }

    if (ehprimo == false || num % 2 == 0) {
        printf("Numero nao eh primo\n");
    } else {
        printf("Eh primo\n");
    }
    return 0;
}
