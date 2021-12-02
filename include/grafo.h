#pragma once

typedef struct grafo {
	float **matriz;
	int tam;
} Grafo;

Grafo *init_grafo(int tam);

void add_aresta(Grafo *g, int origem, int destino, float peso);

void print_matriz(Grafo *g);
