#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOTVISITED 0
#define DISCOVERED 1
#define VISITED 2

// Crie uma estrutura que represente um grafo não-direcionado. Crie um conjunto de vértices e arestas.
typedef struct adj
{
    int vertex;
    struct adj *next;
} Adjacency;

typedef struct
{
    int id;
    Adjacency *adjList;
} Vertex;

typedef struct
{
    int vertexs;
    int edges;
    Vertex *vertexList;
} Graph;

Graph *createGraph(int vertextAmount)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertexs = vertextAmount;
    graph->edges = 0;

    // cria os vértices
    graph->vertexList = (Vertex *)calloc(vertextAmount, sizeof(Vertex));

    // seta os ids dos vértices
    for (int i = 0; i < vertextAmount; i++)
    {
        graph->vertexList[i].id = i;
        graph->vertexList[i].adjList = NULL;
    }

    return graph;
}

Adjacency *createAdj(int value)
{
    Adjacency *adjacency = (Adjacency *)malloc(sizeof(Adjacency));
    adjacency->vertex = value;
    adjacency->next = NULL;
    return adjacency;
}

bool createEdge(Graph *graph, int from, int to)
{
    // verifica se o grafo existe, a origem e destino estão dentro do intervalo e se ñ é um laço
    if (!graph || from < 0 || from >= graph->vertexs || to < 0 || to >= graph->vertexs || from == to)
        return false;

    // verifica se a aresta já existe
    if (graph->vertexList[from].adjList != NULL)
    {
        Adjacency *adjacency = graph->vertexList[from].adjList;
        while (adjacency)
        {
            if (adjacency->vertex == to)
                return false;
            adjacency = adjacency->next;
        }
    }

    Adjacency *adjFrom = createAdj(from);
    Adjacency *adjTo = createAdj(to);
    adjTo->next = graph->vertexList[from].adjList;
    adjFrom->next = graph->vertexList[to].adjList;
    graph->vertexList[from].adjList = adjTo;
    graph->vertexList[to].adjList = adjFrom;
    graph->edges++;
    return true;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertexs; i++)
    {
        printf("V%d: ", i + 1);
        Adjacency *adjacency = graph->vertexList[i].adjList;
        while (adjacency)
        {
            printf("V%d ", adjacency->vertex + 1);
            adjacency = adjacency->next;
        }
        printf("\n");
    }
}

// Implemente algoritmo DFS para o grafo anterior. Execute a travessia DFS começando em um vértice especificado.
void visitDfs(Graph *graph, int vertex, int *status)
{
    status[vertex] = DISCOVERED;
    printf("%d -> ", vertex + 1);

    Adjacency *adjacency = graph->vertexList[vertex].adjList;

    while (adjacency)
    {
        if (status[adjacency->vertex] == NOTVISITED)
            visitDfs(graph, adjacency->vertex, status);
        adjacency = adjacency->next;
    }

    status[vertex] = VISITED;
}

void dfs(Graph *graph, int vertex)
{
    int *status = (int *)calloc(graph->vertexs, sizeof(int));
    for (int i = 0; i < graph->vertexs; i++)
        status[i] = NOTVISITED;
    for (int i = vertex; i < graph->vertexs; i++)
        if (status[i] == NOTVISITED)
            visitDfs(graph, i, status);
}

// Implemente algoritmo BFS para o grafo anterior. Execute a travessia BFS começando em outro vértice especificado.
void visitBfs(Graph *graph, int vertex, int *status)
{
    int *queue = (int *)calloc(graph->vertexs, sizeof(int));
    int start = 0;
    int end = 0;
    queue[end++] = vertex;
    status[vertex] = VISITED;

    while (start < end)
    {
        int v = queue[start++];
        Adjacency *adjacency = graph->vertexList[v].adjList;
        while (adjacency)
        {
            if (status[adjacency->vertex] != VISITED)
            {
                queue[end++] = adjacency->vertex;
                status[adjacency->vertex] = VISITED;
            }
            adjacency = adjacency->next;
        }
        printf("%d -> ", v + 1);
    }
}

void bfs(Graph *graph, int vertex)
{
    int *status = (int *)calloc(graph->vertexs, sizeof(int));
    for (int i = 0; i < graph->vertexs; i++)
        status[i] = NOTVISITED;
    for (int i = vertex; i < graph->vertexs; i++)
        if (status[i] != VISITED)
            visitBfs(graph, i, status);
}

int main()
{
    Graph *graph = createGraph(5);
    createEdge(graph, 0, 1);
    createEdge(graph, 0, 2);
    createEdge(graph, 0, 3);
    createEdge(graph, 2, 4);
    //      V2
    //      |
    //      |
    // V4 - V1 - V3
    //           |
    //           |
    //           V5

    printf("Graph:\n");
    printGraph(graph);

    printf("\nDFS: \n");
    dfs(graph, 3);

    printf("\nBFS: \n");
    bfs(graph, 3);
}