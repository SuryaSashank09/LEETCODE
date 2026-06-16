#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* processStr(char* s) {
    int n = strlen(s);
    int capacity = 64;
    char* result = (char*)malloc(capacity);
    int len = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            if (len + 1 >= capacity) {
                capacity *= 2;
                result = (char*)realloc(result, capacity);
            }
            result[len++] = c;
        } else if (c == '*') {
            if (len > 0) len--;
        } else if (c == '#') {
            if (len > 0) {
                if (len * 2 >= capacity) {
                    while (len * 2 >= capacity) capacity *= 2;
                    result = (char*)realloc(result, capacity);
                }
                memcpy(result + len, result, len);
                len *= 2;
            }
        } else if (c == '%') {
            for (int j = 0; j < len / 2; j++) {
                char tmp = result[j];
                result[j] = result[len - 1 - j];
                result[len - 1 - j] = tmp;
            }
        }
    }

    result[len] = '\0';
    return result;
}
