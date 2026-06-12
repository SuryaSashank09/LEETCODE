#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define LOGN 17

typedef struct {
    int *data;
    int size;
    int cap;
} Vec;

Vec *adj;
int **parent;
int *depth;
int n;

void vec_push(Vec *v, int x) {
    if (v->size == v->cap) {
        v->cap = v->cap ? v->cap * 2 : 2;
        v->data = realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = x;
}

long long modpow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 0; i < adj[u].size; i++) {
        int v = adj[u].data[i];
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void buildLCA() {
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j-1] != -1)
                parent[i][j] = parent[parent[i][j-1]][j-1];
            else
                parent[i][j] = -1;
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) { int tmp = u; u = v; v = tmp; }
    for (int j = LOGN-1; j >= 0; j--) {
        if (parent[u][j] != -1 && depth[parent[u][j]] >= depth[v])
            u = parent[u][j];
    }
    if (u == v) return u;
    for (int j = LOGN-1; j >= 0; j--) {
        if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

int* assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize,
                       int** queries, int queriesSize, int* queriesColSize,
                       int* returnSize) {
    n = edgesSize + 1;
    adj = calloc(n+1, sizeof(Vec));
    parent = malloc((n+1) * sizeof(int*));
    depth = calloc(n+1, sizeof(int));
    for (int i = 0; i <= n; i++) {
        parent[i] = malloc(LOGN * sizeof(int));
        for (int j = 0; j < LOGN; j++) parent[i][j] = -1;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        vec_push(&adj[u], v);
        vec_push(&adj[v], u);
    }
    depth[1] = 0;
    dfs(1, -1);
    buildLCA();

    int* ans = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0], v = queries[i][1];
        int w = lca(u, v);
        int L = depth[u] + depth[v] - 2 * depth[w];
        ans[i] = (L == 0) ? 0 : (int)modpow(2, L-1);
    }
    *returnSize = queriesSize;
    return ans;
}
