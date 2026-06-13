#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char* result = (char*)malloc((wordsSize + 1) * sizeof(char));
    if (!result) return NULL;

    for (int i = 0; i < wordsSize; i++) {
        int sum = 0;
        char* word = words[i];
        for (int j = 0; word[j] != '\0'; j++) {
            int idx = word[j] - 'a';
            sum += weights[idx];
        }
        int modVal = sum % 26;
        result[i] = 'z' - modVal;
    }

    result[wordsSize] = '\0';
    return result;
}
