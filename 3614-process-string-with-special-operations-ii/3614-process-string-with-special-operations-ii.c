#include <stdio.h>
#include <string.h>

char resolve(char* s, int n, long long k) {
    long long len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            len++;
        } else if (s[i] == '*') {
            if (len > 0) len--;
        } else if (s[i] == '#') {
            len *= 2;
        }
    }
    if (k >= len) return '.';

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (k == len - 1) return s[i];
            len--;
        } else if (s[i] == '*') {
            len++;
        } else if (s[i] == '#') {
            len /= 2;
            if (k >= len) k -= len;
        } else if (s[i] == '%') {
            k = len - 1 - k;
        }
    }
    return '.';
}

char processStr(char* s, long long k) {
    int n = strlen(s);
    return resolve(s, n, k);
}
