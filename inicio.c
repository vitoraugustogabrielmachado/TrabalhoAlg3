#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arvore.h"
#include "heap.h"
#include "util.h"


int main(int argc, char *argv[]){
    if(argv[1][1] != 'h' && argv[1][1] != 'a'){
        perror("ta errado ai amigao\n"); //quero q saia no terminal e nn q va para o arquivo de saida
        return(0);
    }

    long int numero;
    scanf("%ld", &numero); //numero de elementos

    double *vetor = inicializaVetor(numero); //o vetor com os pontos 
    double *vetorheap = inicializaVetor(numero); //o vetor com as distancias calculadas

    for(int i = 1; i <= numero ; i++)
        scanf("%lf", &vetor[i]); //leitura dos pontos

    double distancia;
    int tamHeap = 0;

    //para todas as funcoes: OS DOIS VETORES COMEÇAM EM 1 E NAO EM 0
    for(int i = 1; i <= numero; i++){
        tamHeap++;
        if(i == 1 || i == numero)
            distancia = 0.0;
        else{
            if(argv[1][1] == 'h') 
                distancia = altura2_triangulo(i-1, vetor[i-1], i, vetor[i], i+1, vetor[i+1]);
            else    
                distancia = area_triangulo(i-1, vetor[i-1], i, vetor[i], i+1, vetor[i+1]);
        }
        vetorheap[tamHeap] = distancia;
        //inserir arvore(i); isso eu ax q funciona pq o primeiro ponto a ser adicionado eh o vetor[1] ent o i = 1 eh coerente
        //sobre a ARVORE: eu ax q ela vai precisar apontar para o endereço no vetor normal E no vetor HEAP
        //pq se ela nn apontar pro vetor HEAP nn tem como saber daonde o elemento removido veio, se eh do ponto 4, ponto 8 etc
        //mas se ela nn apontar para o vetor normal, na hr de imprimir, q tem q imprimir (4, 9.0) nn vai funcionar, pq tem q imprimir o PONTO e nn a DISTANCIA
    }
    heapfy(tamHeap, vetorheap);
    for(int i = 1; i <= tamHeap; i++)
        printf("%f\n", vetorheap[i]);
    //calcular as distancias e colocar no heap e na arvore
    //remover com base no argv[]
    //imprimir
}