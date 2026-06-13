#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arvore.h"
#include "heap.h"
#include "util.h"
#define INF __INT_MAX__

void atualiza_campo_viz(ponto heap[], int ts[], int num){
    int idx = ts[heap[1].viz_esq];
    heap[idx].viz_dir = heap[1].viz_dir;
    idx = ts[heap[1].viz_dir];
    heap[idx].viz_esq = heap[1].viz_esq;
}

void atualiza_prio_viz(ponto heap[], int ts[], float vet_pontos[], int num, char *argv[]){
    int idx = ts[heap[1].viz_esq];
    int idx_esq = ts[heap[idx].viz_esq];
    int idx_dir = ts[heap[idx].viz_dir];
    if(heap[idx].viz_esq != -1 && heap[idx].viz_dir != -1) { 
        if(argv[1][1] == 'h'){
            heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            idx = ts[heap[1].viz_dir];
            idx_esq = ts[heap[idx].viz_esq];
            idx_dir = ts[heap[idx].viz_dir];
            heap[idx].prio = altura2_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
        }else{
            heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
            idx = ts[heap[1].viz_dir];
            idx_esq = ts[heap[idx].viz_esq];
            idx_dir = ts[heap[idx].viz_dir];
            heap[idx].prio = area_triangulo(heap[idx_esq].index, vet_pontos[heap[idx_esq].index], heap[idx].index, vet_pontos[heap[idx].index], heap[idx_dir].index, vet_pontos[heap[idx_dir].index]);
        }
    }
}

int main(int argc, char *argv[]){
    if((argv[1][1] != 'h' && argv[1][1] != 'a') || (argc != 3)){
        perror("ta errado ai amigao\n"); //quero q saia no terminal e nn q va para o arquivo de saida
        return(0);
    }
    
    float limite = atof(argv[2]); // limite aceitavel para a prioridade 
    int num;
    scanf("%d", &num); //numero de elementos

    float vet_pontos[num+1]; //o vetor com os pontos (comeca no indice 1 e vai ate num)
    ponto heap[num+1]; //o heap (vetor de structs)
    int ts[num+1]; // a tabela de simbolos

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

    float prioridade;
    int tamHeap = 0;

    //para todas as funcoes: OS DOIS VETORES COMEÇAM EM 1 E NAO EM 0
    /* 
    * LOOP PARA INICIALIZAR A PRIORIDADE
    * DOS PONTOS NA HEAP.
    */
    for(int i = 1; i <= num; i++){
        tamHeap++;
        if(i == 1 || i == num)
            prioridade = INF;
        else{
            if(argv[1][1] == 'h') 
                prioridade = altura2_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
            else    
                prioridade = area_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
        }
        heap[tamHeap].prio = prioridade;
    }
    
    /* 
    * LOOP DE REMOCAO DA CABECA DO HEAP
    * E EVENTUAIS ATUALIZACOES.
    */
    heapfy(heap, ts, tamHeap);
    while (1){
        if (heap[1].prio >= limite)
            break;

        atualiza_campo_viz(heap, ts, num); // atualiza o campo viz dos vizinhos do ponto heap[1]
        atualiza_prio_viz(heap, ts, vet_pontos, num, argv); // atualiza a prioridade dos vizinhos de ponto heap[1]

        int idx = heap[1].index;
        heap_remove(heap, ts, &tamHeap); // remove a cabeca do heap
        ts[idx] = -1; // atualiza ts para o ponto removido
    }

    /* IMPRIME A SAIDA */
    
    for(int i = 1; i <= num; i++){
        // achei mais facil varrer a ts ao inves do heap
        // porque assim da para imprimir os pontos na ordem 
        // outro jeito seria varrer o heap, mas sairia fora de ordem
        
        if (ts[i] != -1){
            printf("%d ", i);
            printf("%.1f\n", vet_pontos[i]);
        }
    }
}
