int maxIceCream(int* costs, int costsSize, int coins) {
    int maxCost = 0;
    for (int i = 0; i < costsSize; i++) {
        if (costs[i] > maxCost) {
            maxCost = costs[i];
        }
    }

    int* freq = (int*)calloc(maxCost + 1, sizeof(int));
    for (int i = 0; i < costsSize; i++) {
        freq[costs[i]]++;
    }

    int count = 0;
    for (int price = 1; price <= maxCost; price++) {
        if (freq[price] > 0) {
            int buy = coins / price;
            if (buy > freq[price]) {
                buy = freq[price];
            }
            count += buy;
            coins -= buy * price;
            if (coins < price) break;
        }
    }

    free(freq);
    return count;
}
