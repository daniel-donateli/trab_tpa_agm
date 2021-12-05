#include <kruskal.h>

#include <stdlib.h>

typedef struct aresta {
	int u,v;
	float w;
} aresta;

typedef struct lista_aresta {
	aresta *arr;
	int n;
} lista_aresta;

static int find(int belongs[], int vertexno)
{
	return (belongs[vertexno]);
}

static void union1(int belongs[], int c1, int c2, int n)
{
	int i;
	for(i=0; i<n; i++)
		if(belongs[i] == c2)
			belongs[i] = c1;
}

int cmp(const void *elem1, const void *elem2) 
{
    float f = *((float *) elem1);
    float s = *((float *) elem2);
    if(f < s) return  1;
    if(f > s) return -1;
    return 0;
}

Grafo *kruskal(Grafo *g)
{
	int belongs[g->tam], i, j, cno1, cno2;
	Grafo *mst = init_grafo(g->tam);

	lista_aresta *arestas = (lista_aresta *) malloc(sizeof(lista_aresta));
	arestas->arr = (aresta *) malloc(sizeof(aresta) * g->tam * g->tam);
	arestas->n = 0;

	// Preencher lista de arestas
	for(i=1; i<g->tam; i++) {
		for(j=0; j<i; j++) {
			if(g->matriz[i][j] != 0) {
				arestas->arr[arestas->n].u = i;
				arestas->arr[arestas->n].v = j;
				arestas->arr[arestas->n].w = g->matriz[i][j];
				arestas->n++;
			}
		}
	}

	// Ordernar lista de arestas
	qsort(arestas->arr, g->tam, sizeof(aresta), cmp);

	for(i=0; i<g->tam; i++)
		belongs[i] = i;

	for(i=0; i<arestas->n; i++) {
		cno1 = find(belongs, arestas->arr[i].u);
		cno2 = find(belongs, arestas->arr[i].v);
		// Se não formar ciclo
		if(cno1 != cno2) {
			mst->matriz[arestas->arr[i].u][arestas->arr[i].v] = arestas->arr[i].w;
			mst->matriz[arestas->arr[i].v][arestas->arr[i].u] = arestas->arr[i].w;
			union1(belongs, cno1, cno2, g->tam);
		}
	}

	free(arestas->arr);
	free(arestas);
	return mst;
}
