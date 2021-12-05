#pragma once

#include <stdio.h>

#include <cidade.h>
#include <grafo.h>

Grafo *read_file(FILE *fp, Cidade ***c);

void write_file(FILE *fp, Grafo *g, Cidade ***c);
