#ifndef HEAP
#define HEAP

typedef struct {
    double prio;
    int index; // indice do ponto no vetor de pontos (coordenada x)
    int viz_esq;
    int viz_dir;
} ponto;

void heap_insere(ponto heap[], int ts[], int n); //talvez mudar e fazer com void e dentro dela fazer casting?

// Heapfy, atualizando a ts
void heapfy(ponto heap[], int ts[], int tam); //msm coisa q em cima

// Remove a raiz do heap, atualizando a ts
void heap_remove(ponto heap[], int ts[], int *tam);

int heap_checa(ponto heap[], int tamanhoHeap);

#endif