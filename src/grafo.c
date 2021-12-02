#include <grafo.h>

#include <stdlib.h>
#include <stdio.h>

Grafo *init_grafo(int tam)
{
	int i, j;
	Grafo *g = (Grafo *) malloc(sizeof(Grafo));
	g->tam = tam;
	g->matriz = (float **) malloc(sizeof(float *));
	for(i=0; i<tam; i++) {
		g->matriz[i] = (float *) malloc(sizeof(float));
	}
	for(i = 0; i < tam; i++)
        for(j = 0; j < tam; j++)
            g->matriz[i][j] = 0;
    return g;
}

void add_aresta(Grafo *g, int origem, int destino, float peso)
{
	g->matriz[origem][destino] = peso;
}

void print_matriz(Grafo *g)
{
	int i, j;

    for(i=0; i<g->tam; i++)
    {
        for(j=0; j<g->tam; j++)
         {
             printf("%.2f ", g->matriz[i][j]);
         }
         printf("\n");
     }
}
