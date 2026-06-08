#ifndef HEAP
#define HEAP

void insereHeap(int n, double vetor[]); //talvez mudar e fazer com void e dentro dela fazer casting?

void heapfy(int n, double vetor[]); //msm coisa q em cima

int checaHeap(int tamanhoHeap, double vetorHeap[]);
void removeHeap(int *tamanhoHeap, double vetorHeap[]);

#endif