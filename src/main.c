#include <stdio.h>
#include <stdlib.h>

#include <grafo.h>

int main()
{
    Grafo *g = init_grafo(3);
	add_aresta(g, 0, 1, 5);
	print_matriz(g);
    return 0;
}
