#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arvore.h"
#include "heap.h"
#include "util.h"
#define INF __INT_MAX__

void atualiza_campo_viz(ponto heap[], int ts[]){
    int viz_esq = heap[1].viz_esq;
    int viz_dir = heap[1].viz_dir;
    if (viz_esq != -1 && ts[viz_esq] != -1){
        int idx_esq = ts[viz_esq];
        heap[idx_esq].viz_dir = viz_dir; 
    }
    if (viz_dir != -1 && ts[viz_dir] != -1){
        int idx_dir = ts[viz_dir];
        heap[idx_dir].viz_esq = viz_esq; 
    }
}

void atualiza_prio_viz(ponto heap[], int ts[], float vet_pontos[], int tam, int viz_esq, int viz_dir, char *argv[]){

if (viz_esq != -1 && ts[viz_esq] != -1){
    int idx = ts[viz_esq];
    int novo_esq = heap[idx].viz_esq;
    int novo_dir = heap[idx].viz_dir;
    if (novo_esq != -1 && novo_dir != -1 && ts[novo_esq] != -1 && ts[novo_dir] != -1){
        int idx_esq = ts[novo_esq];
            int idx_dir = ts[novo_dir];
            if (argv[1][1] == 'h')
                heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            else
                heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index],heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);

            heapfy(heap, ts, tam);
        }
}
if (viz_dir != -1 && ts[viz_dir] != -1){
    int idx = ts[viz_dir];
    int novo_esq = heap[idx].viz_esq;
    int novo_dir = heap[idx].viz_dir;
    if (novo_esq != -1 && novo_dir != -1 && ts[novo_esq] != -1 && ts[novo_dir] != -1){
        // calcula e atualiza prio normalmente
        int idx_esq = ts[novo_esq];
            int idx_dir = ts[novo_dir];
            if (argv[1][1] == 'h')
                heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            else
                heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index],heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);

            heapfy(heap, ts, tam);
    }
}
}

int main(int argc, char *argv[]){
    if (argc != 3 || (argv[1][1] != 'h' && argv[1][1] != 'a')){
        fprintf(stderr, "ta errado ai amigao\n");
        return 0;
    }

    float limite = atof(argv[2]);
    int num;
    scanf("%d", &num);

    float vet_pontos[num + 1];
    ponto heap[num + 1];
    int ts[num + 1];

    for(int i = 1; i <= num ; i++){
        scanf("%f", &vet_pontos[i]); // leitura dos pontos
        heap[i].index = i; // inicia campo index do heap
        // inicia campo vizinhos do heap
        if (i == 1){
            heap[i].viz_esq = -1;
            heap[i].viz_dir = i + 1;
        }
        else if (i == num){
            heap[i].viz_esq = i - 1;
            heap[i].viz_dir = -1;
        }
        else{
            heap[i].viz_esq = i - 1;
            heap[i].viz_dir = i + 1;
        }
        ts[i] = i; // inicia ts
    }

    int tamHeap = 0;
    for (int i = 1; i <= num; i++){
        tamHeap++;
        float prioridade;
        if (i == 1 || i == num)
            prioridade = INF;
        else if (argv[1][1] == 'h')
            prioridade = altura2_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
        else
            prioridade = area_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
        heap[tamHeap].prio = prioridade;
    }

    heapfy(heap, ts, tamHeap);

    while (1){
        if (heap[1].prio >= limite)
            break;

        int viz_esq = heap[1].viz_esq;
        int viz_dir = heap[1].viz_dir;

        atualiza_campo_viz(heap, ts);
        atualiza_prio_viz(heap, ts, vet_pontos, tamHeap, viz_esq, viz_dir, argv);

        int idx = heap[1].index;
        heap_remove(heap, ts, &tamHeap);
        ts[idx] = -1;
    }

    for (int i = 1; i <= num; i++){
        if (ts[i] != -1){
            printf("%d ", i);
            printf("%.1f\n", vet_pontos[i]);
        }
    }

    return 0;
}