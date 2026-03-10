#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static const char *DISCIPLINES[] = {
    "Alg I",
    "Alg II",
    "Banco I",
    "Banco II",
    "Alg Estruturas I",
    "Alg Estruturas II",
    "Web 1",
    "Web 2",
    "Org Computadores",
    "Sistemas Operacionais",
    "Redes"};

#define NUM_DISCIPLINES (sizeof(DISCIPLINES) / sizeof(DISCIPLINES[0]))

typedef struct adj
{
    int vertex;
    struct adj *next;
} Adjacency;

typedef struct
{
    int id;
    char discipline[100];
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
        strcpy(graph->vertexList[i].discipline, DISCIPLINES[i]);
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

    Adjacency *adjacency = createAdj(to);
    adjacency->next = graph->vertexList[from].adjList;
    graph->vertexList[from].adjList = adjacency;
    graph->edges++;
    return true;
}

void printGraph(Graph *graph, bool preRequisite)
{
    if (preRequisite)
    {
        for (int i = 0; i < graph->vertexs; i++)
        {
            if (graph->vertexList[i].adjList != NULL)
            {
                printf("%s:", graph->vertexList[i].discipline);
                Adjacency *adjacency = graph->vertexList[i].adjList;
                while (adjacency)
                {
                    printf(" %s ", graph->vertexList[adjacency->vertex].discipline);
                    adjacency = adjacency->next;
                }
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 0; i < graph->vertexs; i++)
        {
            if (graph->vertexList[i].adjList == NULL)
            {
                printf("%s\n", graph->vertexList[i].discipline);
            }
        }
    }
}

void isPreRequisite(Graph *graph)
{
    char preDiscipline[100];
    char discipline[100];

    printf("Nome da disciplina pre-requisito: ");
    fgets(preDiscipline, 100, stdin);
    preDiscipline[strcspn(preDiscipline, "\n")] = '\0';

    printf("Nome da outra disciplina: ");
    fgets(discipline, 100, stdin);
    discipline[strcspn(discipline, "\n")] = '\0';

    int indexDiscipline = -1;
    for (int i = 0; i < graph->vertexs; i++)
        if (strcmp(graph->vertexList[i].discipline, discipline) == 0)
            indexDiscipline = i;
    if (indexDiscipline == -1)
    {
        printf("Disciplina destino nao encontrada");
        return;
    }

    Adjacency *adjacency = graph->vertexList[indexDiscipline].adjList;
    while (adjacency)
    {
        char *preD = graph->vertexList[adjacency->vertex].discipline;
        if (strcmp(preD, preDiscipline) == 0)
        {
            printf("E pre-requisito!\n");
            return;
        }
        adjacency = adjacency->next;
    }
    printf("NAO e pre-requisito!\n");
}

int main()
{
    Graph *graph = createGraph(NUM_DISCIPLINES);
    createEdge(graph, 1, 0);
    createEdge(graph, 3, 2);
    createEdge(graph, 5, 4);
    createEdge(graph, 7, 6);
    createEdge(graph, 9, 8);
    createEdge(graph, 10, 8);

    while (1)
    {
        printf("\n1 - Imprimir disciplinas com pre-requisitos\n");
        printf("2 - Imprimir disciplinas sem pre-requisitos\n");
        printf("3 - Verificar se uma disciplina e pre-requisito de outra\n");
        printf("4 - Sair\n");
        int choice;
        scanf("%d", &choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("\n");
        switch (choice)
        {
        case 1:
            printGraph(graph, true);
            break;

        case 2:
            printGraph(graph, false);
            break;

        case 3:
            isPreRequisite(graph);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Opção inválida!");
            break;
        }
    }
}