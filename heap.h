#ifndef HEAP
#define HEAP

typedef struct {
    double prio;
    int index; // indice do ponto no vetor de pontos (coordenada x)
    int viz_esq;
    int viz_dir;
} ponto;

// Heapfy, atualizando a ts
void heapfy(ponto heap[], int ts[], int tam); //msm coisa q em cima

// Remove a raiz do heap, atualizando a ts
void heap_remove(ponto heap[], int ts[], int *tam);

/*Sobe um elemento depois da atualizacao da prioridade dos vizinhos*/
void atualizaHeap(ponto heap[], int ts[], int pos);

/*Desce o elemento que esta na posicao errada no heap*/
void sacodeHeap(ponto heap[], int ts[], int pos, int tam);

#endif