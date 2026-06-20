static int cmp(const void* a, const void* b);

int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {
    if (restrictionsSize == 0) return n - 1;

    int has1 = 0, hasN = 0;
    for (int i = 0; i < restrictionsSize; i++) {
        if (restrictions[i][0] == 1) has1 = 1;
        if (restrictions[i][0] == n) hasN = 1;
    }

    int extra = (has1 ? 0 : 1) + (hasN ? 0 : 1);
    int newSize = restrictionsSize + extra;
    int** arr = (int**)malloc(newSize * sizeof(int*));
    int idx = 0;
    for (int i = 0; i < restrictionsSize; i++) {
        arr[idx++] = restrictions[i];
    }
    int* sentinel1 = NULL;
    int* sentinelN = NULL;
    if (!has1) {
        sentinel1 = (int*)malloc(2 * sizeof(int));
        sentinel1[0] = 1;
        sentinel1[1] = 0;
        arr[idx++] = sentinel1;
    }
    if (!hasN) {
        sentinelN = (int*)malloc(2 * sizeof(int));
        sentinelN[0] = n;
        sentinelN[1] = n - 1;
        arr[idx++] = sentinelN;
    }

    qsort(arr, newSize, sizeof(int*), cmp);

    for (int i = 1; i < newSize; i++) {
        int dist = arr[i][0] - arr[i - 1][0];
        if (arr[i][1] > arr[i - 1][1] + dist) {
            arr[i][1] = arr[i - 1][1] + dist;
        }
    }
    for (int i = newSize - 2; i >= 0; i--) {
        int dist = arr[i + 1][0] - arr[i][0];
        if (arr[i][1] > arr[i + 1][1] + dist) {
            arr[i][1] = arr[i + 1][1] + dist;
        }
    }

    long long ans = 0;
    for (int i = 1; i < newSize; i++) {
        int dist = arr[i][0] - arr[i - 1][0];
        long long left = arr[i - 1][1];
        long long right = arr[i][1];
        long long diff = llabs(left - right);
        long long peak = (left > right ? left : right) + (dist - diff) / 2;
        if (peak > ans) ans = peak;
    }

    if (sentinel1) free(sentinel1);
    if (sentinelN) free(sentinelN);
    free(arr);
    return (int)ans;
}

static int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}