#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraAleatorio(int *, int);
void geraQuaseOrdenado(int *, int);
void geraComRepeticoes(int *, int, int, int);
void exibe(char *, int *, int);
void selection(int *, int, long long int *, long long int *);
int soma(int *, int);
float media(int *, int);
void inverte(int *, int *, int);

int main() {
    int *v, n, *v2, *v3, *v4;
    long long int trocas, comparacoes;
    long int ini, fim;
    srand(time(0));
    printf("Escolha um tamanho para o vetor, 0 encerra:\n");
    scanf("%d", &n);

    while (n > 0) {
        v = (int *)malloc(n * sizeof(int));
        v2 = (int *)malloc(n * sizeof(int));
        v3 = (int *)malloc(n * sizeof(int));
        v4 = (int *)malloc(n * sizeof(int));
        geraAleatorio(v, n);
        geraQuaseOrdenado(v2, n); // Chama geraQuaseOrdenado sem argumentos para criar um vetor quase ordenado
        geraComRepeticoes(v3, n, 3, n / 2);
        trocas = 0;
        comparacoes = 0;
        
        inverte(v, v4, n);
        
        ini = time(0);
        selection(v, n, &trocas, &comparacoes);
        fim = time(0);

        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %lld comparacoes e %lld trocas no vetor aleatório", comparacoes, trocas);

        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        selection(v2, n, &trocas, &comparacoes);
        fim = time(0);

        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %lld comparacoes e %lld trocas no vetor quase ordenado", comparacoes, trocas);

        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        selection(v3, n, &trocas, &comparacoes);
        fim = time(0);

        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %lld comparacoes e %lld trocas no vetor com repetições variadas", comparacoes, trocas);

        trocas = 0;
        comparacoes = 0;
        ini = time(0);
        selection(v4, n, &trocas, &comparacoes);
        fim = time(0);

        printf("\nTempo para tamanho %d: %ld", n, fim - ini);
        printf("\nForam realizadas %lld comparacoes e %lld trocas no vetor invertido", comparacoes, trocas);

        printf("\nA soma dos vetores é de: %d\n", soma(v4, n));
        printf("\nA média é de: %f\n", media(v4, n));
        
        free(v);
        free(v2);
        free(v3);
        free(v4);
        
        printf("\nEscolha um tamanho para o vetor, 0 encerra:\n");
        scanf("%d", &n);
    }

    return 0;
}

void geraAleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (n * 10);
    }
}

void geraQuaseOrdenado(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    int maxElementosForaDeOrdem = n - 1; // Permitir que todos os elementos estejam fora de ordem
    int elementosForaDeOrdem = rand() % (maxElementosForaDeOrdem + 1); // Número aleatório de elementos fora de ordem
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

void selection(int *v, int n, long long int *trocas, long long int *comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
            (*trocas)++;
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
