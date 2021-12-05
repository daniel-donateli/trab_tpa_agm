#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <grafo.h>
#include <cidade.h>
#include <file_reader.h>
#include <kruskal.h>

int main()
{
    Grafo *g = NULL;
    Cidade **c = NULL;
    FILE *fp = fopen("entrada.txt", "r");
    g = read_file(fp, &c);
    /*
    printf("Grafo gerado do arquivo: \n");
    print_grafo(g);
    */
    
    Grafo *mst = kruskal(g);
    /*
    printf("Árvore geradora mínima: \n");
    print_grafo(mst);
    printf("\n\n\n");
    */
    fp = fopen("viasAsfaltadas.txt", "w");
    write_file(fp, mst, &c);

    return 0;
}
