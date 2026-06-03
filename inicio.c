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
    double *vetor = malloc((numero + 1) * sizeof(double)); //o vetor com os pontos 
    double *vetorheap = malloc((numero + 1) * sizeof(double)); //o vetor com as distancias calculadas
    for(int i = 1; i <= numero ; i++)
        scanf("%lf", &vetor[i]); //leitura dos pontos
    double distancia;
    int tamHeap = 0;
    for(int i = 1; i <= numero; i++){
        /*if(i != 1 && i != numero){ //talvez fazer o 1 e o maximo terem um valor de distancia incomparavel
            tamHeap++;
            if(argv[1][1] == 'h') //ta errado aq, qqlr coisa q nn seja h vai fazer o else
                distancia = altura2_triangulo(i-1, vetor[i-1], i, vetor[i], i+1, vetor[i+1]);
            else    
                distancia = area_triangulo(i-1, vetor[i-1], i, vetor[i], i+1, vetor[i+1]);
            vetorheap[tamHeap] = distancia; //aqui o vetor ainda nn esta heapificado, mas a arvore ainda vai dar certo
            //inserir_arvore(i);
        }*/
        //a parte de cima era so um basicao, agr eu vou fazer certinho
        
        tamHeap++;
        if(i == 1 || i == numero)
            distancia = 0.0;
        else{

        }
    }
    heapfy(tamHeap, vetorheap);
    for(int i = 1; i <= tamHeap; i++)
        printf("%f\n", vetorheap[i]);
    //calcular as distancias e colocar no heap e na arvore
    //remover com base no argv[]
    //imprimir
}