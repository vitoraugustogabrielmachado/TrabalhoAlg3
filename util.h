#ifndef UTIL
#define UTIL

//talvez esse arquivo seja inutil dps, mas dps ve isso

float area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);

float altura2_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);

double *inicializaVetor(int numero);

/*void atualiza_prio_viz(ponto heap[], int ts[], float vet_pontos[], int tam, int viz_esq, int viz_dir, char *argv[]){
    if (heap[1].viz_esq != -1 && ts[heap[1].viz_esq] != -1){
        int idx = ts[heap[1].viz_esq];
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
    if (heap[1].viz_dir != -1 && ts[heap[1].viz_dir] != -1){
        int idx = ts[heap[1].viz_dir];
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
}*/

#endif