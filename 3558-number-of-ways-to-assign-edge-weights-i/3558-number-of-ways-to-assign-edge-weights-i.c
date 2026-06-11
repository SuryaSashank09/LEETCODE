#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *neighbors;
    int size;
    int capacity;
} AdjList;

void addEdge(AdjList *graph, int u, int v) {
    if (graph[u].size == graph[u].capacity) {
        graph[u].capacity *= 2;
        graph[u].neighbors = realloc(graph[u].neighbors, graph[u].capacity * sizeof(int));
    }
    graph[u].neighbors[graph[u].size++] = v;
}

void dfs(AdjList *graph, int node, int depth, int *maxDepth, int *deepestNode, int parent) {
    if (depth > *maxDepth) {
        *maxDepth = depth;
        *deepestNode = node;
    }
    for (int i = 0; i < graph[node].size; i++) {
        int neighbor = graph[node].neighbors[i];
        if (neighbor != parent) {
            dfs(graph, neighbor, depth + 1, maxDepth, deepestNode, node);
        }
    }
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    AdjList *graph = malloc((n + 1) * sizeof(AdjList));
    for (int i = 1; i <= n; i++) {
        graph[i].neighbors = malloc(2 * sizeof(int));
        graph[i].size = 0;
        graph[i].capacity = 2;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    int maxDepth = -1, deepestNode = 1;
    dfs(graph, 1, 0, &maxDepth, &deepestNode, -1);
    int pathLen = maxDepth;
    long long ways = 1;
    for (int i = 0; i < pathLen - 1; i++) {
        ways = (ways * 2) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        free(graph[i].neighbors);
    }
    free(graph);
    return (int)ways;
}
