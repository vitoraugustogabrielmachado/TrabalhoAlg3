// BIBLIOTECA COM FUNCOES DA HEAP
#include <stdlib.h>
#include "heap.h"

/*Realiza a troca entre dois elementos no heap e ajusta a tabela de simbolos*/
void troca(ponto heap[], int ts[], int i, int j){
    ponto aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;
    ts[heap[i].index] = i;
    ts[heap[j].index] = j;
}

/*Desce o elemento que esta na posicao errada no heap*/
void sacodeHeap(ponto heap[], int ts[], int pos, int tam){
    int i = 2 * pos;
    while (i <= tam){
        if (i < tam && heap[i].prio > heap[i + 1].prio)
            i++;
        if (heap[i/2].prio <= heap[i].prio)
            break;
        troca(heap, ts, i/2, i);
        i *= 2;
    }
}

/*Sobe um elemento depois da atualizacao da prioridade dos vizinhos*/
void atualizaHeap(ponto heap[], int ts[], int pos){
    int i = pos;
    while (i > 1 && heap[i/2].prio > heap[i].prio){
        troca(heap, ts, i/2, i);
        i /= 2;
    }
}

/*Remove um elemento do heap*/
void heap_remove(ponto heap[], int ts[], int *tam){
    troca(heap, ts, 1, (*tam));
    sacodeHeap(heap, ts, 1, (*tam) - 1);
    (*tam)--;
}

/*Heapfica um vetor*/
void heapfy(ponto heap[], int ts[], int n){
    for (int i = n/2; i >= 1; i--)
        sacodeHeap(heap, ts, i, n);
}
