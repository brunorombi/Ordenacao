#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraAleatorio(int *, int);
void geraQuaseOrdenado(int *, int, int);
void geraComRepeticoes(int *, int, int, int);
void exibe(char *, int *, int);
void bubble(int *, int, long long int *, long long int *);
int soma(int *, int);
float media(int *, int);
void inverte(int *, int *, int);

int main() {
    int *v, n, *v2, *v3, *v4;
    int trocas, comparacoes;
    long int ini, fim;
    // Inicializando o gerador
    srand(time(0));
    printf("Escolha um tamanho para o vetor, 0 encerra:\n");
    scanf("%d", &n);

    // Repetir tamanho maior que 0
    while (n > 0) {
        // Alocar vetores dinamicamente, do tamanho que o usuário quiser
        v = (int *)malloc(n * sizeof(int));
        v2 = (int *)malloc(n * sizeof(int));
        v3 = (int *)malloc(n * sizeof(int));
        v4 = (int *)malloc(n * sizeof(int));
        // Gerar randomicamente os valores para o vetor aleatório
        geraAleatorio(v, n);
        geraQuaseOrdenado(v2, n, 5); // O terceiro argumento (5) determina a quantidade de elementos fora de ordem
        geraComRepeticoes(v3, n, 3, n / 2); // O terceiro argumento (3) determina o número a ser repetido e o quarto argumento (n / 2) determina a variação
        trocas = 0;
        comparacoes = 0;
        // Exibir os vetores
        exibe("Vetor aleatório", v, n);
        exibe("Vetor quase ordenado", v2, n);
        exibe("Vetor com repetições variadas", v3, n);
        
        // Inverter o vetor aleatório
        inverte(v, v4, n);
        exibe("Vetor aleatório invertido", v4, n);

        // Bubble Sort para o vetor aleatório
        ini = time(0);
        bubble(v, n, &trocas, &comparacoes);
        fim = time(0);
        // Exibir
        //exibe("Vetor aleatório ordenado", v, n);
        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %d comparacoes e %d trocas no vetor aleatório", comparacoes, trocas);

        // Bubble Sort para o vetor quase ordenado
        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        bubble(v2, n, &trocas, &comparacoes);
        fim = time(0);
        // Exibir
        //exibe("Vetor quase ordenado ordenado", v2, n);
        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %d comparacoes e %d trocas no vetor quase ordenado", comparacoes, trocas);

        // Bubble Sort para o vetor com repetições variadas
        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        bubble(v3, n, &trocas, &comparacoes);
        fim = time(0);
        // Exibir
        //exibe("Vetor com repetições variadas ordenado", v3, n);
        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %d comparacoes e %d trocas no vetor com repetições variadas", comparacoes, trocas);

        // Bubble Sort para o vetor  invertido
        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        bubble(v4, n, &trocas, &comparacoes);
        fim = time(0);
        // Exibir
        //exibe("Vetor aleatório invertido ordenado", v4, n);
        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %d comparacoes e %d trocas no vetor invertido",comparacoes,trocas);

        // Somar
        printf("\nA soma dos vetores é de: %d\n", soma(v4, n));
        // Média
        printf("\nA média é de: %f\n", media(v4, n));
        // Liberar memória
        free(v);
        free(v2);
        free(v3);
        free(v4);
        // Ler novo tamanho
        printf("\nEscolha um tamanho para o vetor, 0 encerra:\n");
        scanf("%d", &n);
    }

    return 0;
}

void geraAleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (n * 10); // Gera números aleatórios de 0 a n*10-1
    }
}

void geraQuaseOrdenado(int *v, int n, int elementosForaDeOrdem) {
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    for (int i = 0; i < elementosForaDeOrdem; i++) {
        int pos1 = rand() % n;
        int pos2 = rand() % n;
        int temp = v[pos1];
        v[pos1] = v[pos2];
        v[pos2] = temp;
    }
}

void geraComRepeticoes(int *v, int n, int repeticao, int variacao) {
    for (int i = 0; i < n; i++) {
        v[i] = repeticao + rand() % (variacao + 1);
    }
}

void exibe(char *mensagem, int *v, int n) {
    printf("\n%s:\n", mensagem);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble(int *v, int n, long long int *trocas, long long int *comparacoes) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

int soma(int *v, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma;
}

float media(int *v, int n) {
    return (float)soma(v, n) / n;
}

void inverte(int *v, int *v_invertido, int n) {
    for (int i = 0; i < n; i++) {
        v_invertido[i] = n - i;
    }
}