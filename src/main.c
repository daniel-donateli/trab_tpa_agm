#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <grafo.h>
#include <cidade.h>
#include <file_reader.h>

int main()
{
    //setlocale(LC_ALL, "Portuguese");
    /*
    Grafo *g = init_grafo(3);
	add_aresta(g, 0, 1, 5);
	print_matriz(g);
    */
    Grafo *g = NULL;
    Cidade **c = NULL;
    FILE *fp = fopen("entrada.txt", "r");
    g = read_file(fp, c);
    //g = init_grafo(10);
    print_grafo(g);
    return 0;
}
