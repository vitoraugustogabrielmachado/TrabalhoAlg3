#include "heap.h"
/*Falta completar, dexa com o pai*/

void insereHeap(int n, double vetor[]){
    int aux, i = n + 1;
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