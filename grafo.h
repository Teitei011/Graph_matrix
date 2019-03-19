typedef struct {
  int vertices;
  int** arestas; /* O valor 0 é quanda não há conexoes*/// 0 represents the lack of adjacency
} grafo_t;


grafo_t *criar(int nvertices);
int criar_aresta(grafo_t * G, int v1, int v2, int peso);
void imprimir(grafo_t *G);
int existe_aresta(grafo_t * G, int v1, int v2);
int retirar_aresta(grafo_t *G, int v1, int v2);
void liberar_memoria(grafo_t *G);
