#include "util.h"
#include <stdlib.h>


float area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area;

    area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
    return (area < 0.0) ? -area : area;
}

float altura2_triangulo(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area, dx, dy;

    area = area_triangulo(x1, y1, x2, y2, x3, y3);
    dx = x3 - x1;
    dy = y3 - y1;    
    return 4 * (area * area) / (dx * dx + dy * dy);
}

double *inicializaVetor(int numero){
    double *temp = calloc(numero + 1, sizeof(double));
    return(temp);
}

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
