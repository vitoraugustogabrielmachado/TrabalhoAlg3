#include "heap.h"
#include <string.h>
#include <stdlib.h>

void insereHeap(int n, double vetor[]){
    double aux;
    int i = n + 1;
    while(i > 1 && vetor[i/2] < vetor[i]){
        aux = vetor[i/2];
        vetor[i/2] = vetor[i];
        vetor[i] = aux;
        i /= 2;
    }
}

void heapfy(int n, double vetor[]){ 
    for(int i = 1; i <= n; i++){
        insereHeap(i, vetor);
	}
}

int checaHeap(int tamanhoHeap, double vetorHeap[]){
    for(int i = tamanhoHeap; i > 1; i--)
        if(vetorHeap[i] > vetorHeap[i/2])
            return(0);
    return(1);
}

void sacodeHeap(int tamanhoHeap, double vetorHeap[]){
    double aux = 0.0;
    int i = 2;
    while(i <= tamanhoHeap){
        if(i < tamanhoHeap && vetorHeap[i] < vetorHeap[i + 1])
            i++;
        if(vetorHeap[i/2] >= vetorHeap[i])
            break;
        aux = vetorHeap[i/2];
        vetorHeap[i/2] = vetorHeap[i];
        vetorHeap[i] = aux;
        i *= 2;
    }
}

void troca(int j, double vetorHeap[]){
	double aux = vetorHeap[1];
	vetorHeap[1] = vetorHeap[j];
	vetorHeap[j] = aux;
}

void removeHeap(int *tamanhoHeap, double vetorHeap[]){
	troca((*tamanhoHeap), vetorHeap); 
	sacodeHeap((*tamanhoHeap) - 1, vetorHeap);
    (*tamanhoHeap)--;
}

