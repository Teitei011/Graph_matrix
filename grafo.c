#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

grafo_t * criar(int nvertices) 
{
  int i, j;
  grafo_t* g = (grafo_t*)malloc(sizeof(grafo_t));
  
  g->vertices = nvertices; /* Definindo o tamanho da matriz*/ 
  g->arestas = (int**) malloc(nvertices * sizeof(int*));
  

  for (i = 0 ; i < g->vertices ; i++)             /* Alocando espaço para as arestas*/
    g->arestas[i] = (int*) malloc(nvertices * sizeof(int));

  for (i = 0 ; i < nvertices ; i++) /* Inicializando todos os dados da matriz com 0*/
    for (j = 0 ; j < nvertices ; j++)
      g->arestas[i][j] = 0;
    return g;
}

/* Percorrer a matriz inteira e imprimir todos os dados da mesma */
void imprimir(grafo_t* g) 
{
  for (int i = 0; i < g->vertices; i++)
  {
    for (int j = 0; j < g->vertices; j++) 
      printf(" %d ", g->arestas[i][j]);
    printf("\n");
  }
  printf("\n");
}


/* Afim de criar uma aresta é necessario ver se a aresta é positiva e 
menor do que o tamanho de vertices que podem ser formados pela grafo,
tem de ser verificado para v1 e v2  */
int criar_aresta(grafo_t* g, int v1, int v2, int peso) 
{
  if (v1 >= 0 && v1 < g->vertices && v2 >= 0 && v2 < g->vertices && g->arestas[v1][v2] == 0)
  {

    g->arestas[v1][v2] = peso;
    g->arestas[v2][v1] = peso;
   
  return 0;
  }
  return -1;
}

/*  Mesmo processo para ver se é possivel inserir do criar_aresta, 
com a diferença que é colocado os valor das arestas com 0*/
int retirar_aresta(grafo_t* g, int v1, int v2) 
{
  int peso = -1;
  if (v1 >= 0 && v1 < g->vertices && v2 >= 0 && v2 < g->vertices && g->arestas[v1][v2] > 0) 
  {
    peso = g->arestas[v1][v2];
  
    g->arestas[v1][v2] = 0;
    g->arestas[v2][v1] = 0;
  }
  return peso;
}

int existe_aresta(grafo_t* g, int v1, int v2) 
  {
    if (g->arestas[v1][v2] > 0) /* Verificando se existe a aresta */
      return g->arestas[v1][v2];
  }

void liberar_memoria(grafo_t* g) /* Problema com a desalocacao de memoria*/
{
      
  for (int i = 0 ; i < g->vertices ; i++)             /* Desalocando espaço das arestas*/
    free(g->arestas[i]);

  free(g->arestas);
  free(g);
}