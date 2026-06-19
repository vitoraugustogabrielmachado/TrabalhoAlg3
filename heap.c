// BIBLIOTECA COM FUNCOES DA HEAP
#include <stdlib.h>
#include "heap.h"

void troca(ponto heap[], int ts[], int i, int j){
    ponto aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;
    ts[heap[i].index] = i;
    ts[heap[j].index] = j;
}

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

/* Sobe um elemento na heap (necessário após diminuir prioridade) */
void sobeHeap(ponto heap[], int ts[], int pos){
    int i = pos;
    while (i > 1 && heap[i/2].prio > heap[i].prio){
        troca(heap, ts, i/2, i);
        i /= 2;
    }
}

/* Reposiciona um elemento: sobe ou desce conforme necessário */
void atualiza_pos(ponto heap[], int ts[], int pos, int tam){
    sobeHeap(heap, ts, pos);
    sacodeHeap(heap, ts, ts[heap[pos].index], tam);
}

void heap_remove(ponto heap[], int ts[], int *tam){
    troca(heap, ts, 1, (*tam));
    sacodeHeap(heap, ts, 1, (*tam) - 1);
    (*tam)--;
}

void heap_insere(ponto heap[], int ts[], int n){
    int i = n + 1;
    while (i > 1 && heap[i/2].prio > heap[i].prio){
        troca(heap, ts, i/2, i);
        i /= 2;
    }
}

void heapfy(ponto heap[], int ts[], int n){
    for (int i = n/2; i >= 1; i--)
        sacodeHeap(heap, ts, i, n);
}

int heap_checa(ponto heap[], int tam){
    for (int i = tam; i > 1; i--)
        if (heap[i].prio < heap[i/2].prio)
            return 0;
    return 1;
}
