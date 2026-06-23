#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "heap.h"
#include "util.h"
#define INF __FLT_MAX__

int main(int argc, char *argv[]){
    if (argc != 3 || (argv[1][1] != 'h' && argv[1][1] != 'a')){ //trata de parametros errados
        puts("Erro: parametro incorreto.");
        puts("Forma de uso: ./inicio -a <valor> ou ./inicio -h <valor>");
        return 0;
    }

    float limite = atof(argv[2]);
    int num;
    scanf("%d", &num); //le a quantidade de pontos que vao ser lidos

    //AS ESTRUTURAS COMECAM NO 1 
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
    for(int i = 1; i <= num; i++){
        tamHeap++;
        float prioridade;
        if (i == 1 || i == num) // se for o primeiro ou o ultimo recebem o maximo possivel
            prioridade = INF;
        else if (argv[1][1] == 'h')
            prioridade = altura2_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
        else
            prioridade = area_triangulo(i-1, vet_pontos[i-1], i, vet_pontos[i], i+1, vet_pontos[i+1]);
        heap[tamHeap].prio = prioridade;
    }

    heapfy(heap, ts, tamHeap);
    while (heap[1].prio < limite){
        atualiza_campo_viz(heap, ts);
        atualiza_prio_viz(heap, ts, vet_pontos, tamHeap, argv);
        int idx = heap[1].index;
        heap_remove(heap, ts, &tamHeap);
        ts[idx] = -1;
    }

    printf("%d\n", tamHeap);
    for (int i = 1; i <= num; i++){
        if (ts[i] != -1){
            printf("%.1f ", (float)i);
            printf("%.1f\n", vet_pontos[i]);
        }
    }

    return 0;
}
