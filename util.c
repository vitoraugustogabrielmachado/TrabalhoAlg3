#include <stdlib.h>
#include "util.h"

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

/*Atualiza o campo vizinho direito do vizinho esquerdo do elemento removido e o vizinho esquerdo do vizinho direito do elemento removido*/
void atualiza_campo_viz(ponto heap[], int ts[]){
    int viz_esq = heap[1].viz_esq; //o elemento removido eh a cabeca do heap
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

/*Atualiza o campo prioridade do vizinho esquerdo do elemento removido e do vizinho direito do elemento removido*/
void atualiza_prio_viz(ponto heap[], int ts[], float vet_pontos[], int tam, char *argv[]){
    if (heap[1].viz_esq != -1 && ts[heap[1].viz_esq] != -1){ // atualiza a prioridade do vizinho esquerdo
        int idx = ts[heap[1].viz_esq]; // acha a posicao no heap do elemento que vai ser calculado
        int novo_esq = heap[idx].viz_esq; // acha os vizinhos novos para o calculo
        int novo_dir = heap[idx].viz_dir;
        if (novo_esq != -1 && novo_dir != -1 && ts[novo_esq] != -1 && ts[novo_dir] != -1){
            int idx_esq = ts[novo_esq]; // acha a posicao no heap dos vizinhos para o codigo nn ficar ilegivel
            int idx_dir = ts[novo_dir];
            if (argv[1][1] == 'h')
                heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            else
                heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index],heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);

            atualizaHeap(heap, ts, idx); // atualiza o heap, chamar o heapfy pode causar bugs e fica caro 
            sacodeHeap(heap, ts, idx, tam);
        }
    }
    if (heap[1].viz_dir != -1 && ts[heap[1].viz_dir] != -1){ // atualiza a prioridade do vizinho direito
        int idx = ts[heap[1].viz_dir]; // acha a posicao no heap do elemento que vai ser calculado
        int novo_esq = heap[idx].viz_esq; // acha os vizinhos novos para o calculo
        int novo_dir = heap[idx].viz_dir;
        if (novo_esq != -1 && novo_dir != -1 && ts[novo_esq] != -1 && ts[novo_dir] != -1){
            int idx_esq = ts[novo_esq]; // acha a posicao no heap dos vizinhos 
            int idx_dir = ts[novo_dir];
            if (argv[1][1] == 'h')
                heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            else
                heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index],heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);

            atualizaHeap(heap, ts, idx); // atualiza o heap, chamar o heapfy pode causar bugs e fica caro 
            sacodeHeap(heap, ts, idx, tam);
        }
    }
}
