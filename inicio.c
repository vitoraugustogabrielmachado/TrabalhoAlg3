#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arvore.h"
#include "heap.h"
#include "util.h"
#define INF INT_MAX

struct ponto{
    double prio;
    int index; // indice do ponto no vetor de pontos (coordenada x)
    int viz_esq;
    int viz_dir;
};

int main(int argc, char *argv[]){
    if(argv[1][1] != 'h' && argv[1][1] != 'a'){
        perror("ta errado ai amigao\n"); //quero q saia no terminal e nn q va para o arquivo de saida
        return(0);
    }

    long int num;
    scanf("%ld", &num); //numero de elementos

    double vet_pontos[num+1]; //o vetor com os pontos (comeca no indice 1 e vai ate num)
    struct ponto heap[num+1]; //o heap (vetor de structs)
    int ts[num+1]; // a tabela de simbolos

    for(int i = 1; i <= num ; i++){
        scanf("%lf", &vet_pontos[i]); // leitura dos pontos
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

    double prioridade;
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
                prioridade = area_triangulo(i-1, vetor[i-1], i, vetor[i], i+1, vetor[i+1]);
        }
        heap[tamHeap].prio = prioridade;
    }

    /* 
    * LOOP DE REMOCAO DA CABECA DO HEAP
    * E EVENTUAIS ATUALIZACOES.
    */
    while (1){
        heapfy(tamHeap, heap);
        atualiza_ts(ts, num);
        if (heap[1].prio < limite){
            atualiza_campo_viz(heap, ts, num, 1); // atualiza o campo viz dos vizinhos do ponto heap[1]
            atualiza_prio_viz(heap, ts, num, 1); // atualiza a prioridade dos vizinhos de ponto heap[1]
            remove_heap(1); // remove a cabeca do heap
            ts[heap[1].index] = -1 // atualiza ts para o ponto removido
            tamHeap--; // atualiza para a impressao
        }
        else 
            break;
    }

    /* IMPRIME A SAIDA */
    printf("%d\n", tamHeap);
    for(int i = 1; i <= tamHeap; i++){
        if (ts[i] != -1){
            printf("%f.1 ", i);
            printf("%f.1\n", vet_pontos[i]);
        }
    }
}
