#include <stdio.h>

int calcula(int num_1, char op, int num_2);

int potencia(int num, int expoente);

int main(void) {
    int num, x, y;
    char op;
    printf(
        "1) Calcula (x ^ y)\n2) Calcula a multiplicação do primeiro pelo segundo(x * y)\n3) "
        "Calcula a "
        "divisão do primeiro pelo segundo(x / y)\n ");
    printf("\nDigite os valores de x (op) y = ");
    scanf("%d %c %d", &x, &op, &y);
    if (calcula(x, op, y) != -1) {
        printf("%d %c %d = %d\n", x, op, y, calcula(x, op, y));
    } else {
        printf("Operacao invalida\n");
    }
    return 0;
}

int potencia(int num, int expoente) {
    int pot = 1;
    for (int i = 0; i < expoente; i++) { pot *= num; }
    return pot;
}

int calcula(int num_1, char op, int num_2) {
    int resposta = -1;
    switch (op) {
        case '*':
        case 'x':
            return num_1 * num_2;
        case '/':
            return num_1 / num_2;
        case '^':
            return potencia(num_1, num_2);
    }
    return resposta;
}
