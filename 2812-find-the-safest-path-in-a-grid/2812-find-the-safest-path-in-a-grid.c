#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int r, c;
} Point;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValidPath(int** dist, int n, int minDist) {
    if (dist[0][0] < minDist || dist[n - 1][n - 1] < minDist) return false;

    bool** visited = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }

    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int head = 0, tail = 0;

    queue[tail++] = (Point){0, 0};
    visited[0][0] = true;

    bool reached = false;
    while (head < tail) {
        Point curr = queue[head++];
        if (curr.r == n - 1 && curr.c == n - 1) {
            reached = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dirs[i][0];
            int nc = curr.c + dirs[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && dist[nr][nc] >= minDist) {
                visited[nr][nc] = true;
                queue[tail++] = (Point){nr, nc};
            }
        }
    }

    for (int i = 0; i < n; i++) free(visited[i]);
    free(visited);
    free(queue);

    return reached;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) dist[i][j] = -1; 
    }

    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int head = 0, tail = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1) {
                dist[r][c] = 0;
                queue[tail++] = (Point){r, c};
            }
        }
    }

    while (head < tail) {
        Point curr = queue[head++];
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dirs[i][0];
            int nc = curr.c + dirs[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[curr.r][curr.c] + 1;
                queue[tail++] = (Point){nr, nc};
            }
        }
    }
    free(queue);

    int low = 0, high = 2 * n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValidPath(dist, n, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);

    return ans;
}