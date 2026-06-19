// BIBLIOTECA PARA FUNCOES AUXILIARES DA MAIN
#ifndef UTIL
#define UTIL

#include "heap.h"

float area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);

float altura2_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);

void atualiza_campo_viz(ponto heap[], int ts[]);

void atualiza_prio_viz(ponto heap[], int ts[], float vet_pontos[], int tam, char *argv[]);

#endif
