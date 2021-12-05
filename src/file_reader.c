#include <file_reader.h>

#include <stdlib.h>
#include <string.h>

Grafo *read_file(FILE *fp, Cidade ***c)
{
	if(fp == NULL) {
		perror("Não foi possível abrir o arquivo.");
		return NULL;
	}
	int i, j;
	char *token;
	char linha[256];
	int qtd = atoi(fgets(linha, 256, fp));
	*c = (Cidade **) malloc(sizeof(Cidade *) * qtd);
	Grafo *g = init_grafo(qtd);
	for(i=0; i<qtd; i++) {
		(*c)[i] = (Cidade *) malloc(sizeof(Cidade));
	}
	printf("Lendo arquivo...\n");
	fflush(stdout);
	for(i=0; i<qtd; i++) {
		printf("Cidades: %d/%d\n", i+1, qtd);
		fflush(stdout);
		fgets(linha, 256, fp);
		token = strtok(linha, ";");
		(*c)[i]->codigo = atoi(token);
		token = strtok(NULL, ";");
		strcpy((*c)[i]->nome, token);
		(*c)[i]->nome[strcspn((*c)[i]->nome, "\n")] = 0;
	}
	for(i=0; i<qtd; i++) {
		j = 0;
		printf("Distâncias: %d/%d\n", i+1, qtd);
		fflush(stdout);
		fgets(linha, 256, fp);
		token = strtok(linha, ";");
		add_aresta(g, i, j, atof(token));
		for(j=1; j<qtd; j++) {
			token = strtok(NULL, ";");
			add_aresta(g, i, j, atof(token));
		}
	}
	printf("\nLeitura finalizada.\n");
	fclose(fp);
	return g;
}

void write_file(FILE *fp, Grafo *g, Cidade ***c)
{
	if(fp == NULL) {
		perror("Não foi possível abrir o arquivo.");
		return;
	}
	int i, j;
	float soma = 0;

	printf("Salvando arquivo...\n");
	for(i=0; i<g->tam; i++) {
		for(j=i; j<g->tam; j++) {
			if(g->matriz[i][j] != 0) {
				fprintf(fp, "%d;%s;%d;%s;%f\n", (*c)[i]->codigo, (*c)[i]->nome, (*c)[j]->codigo, (*c)[j]->nome, g->matriz[i][j]);
				soma += g->matriz[i][j];
			}
		}
	}
	fprintf(fp, "%f", soma);
	fclose(fp);
	printf("Arquivo salvo.\n");
}
