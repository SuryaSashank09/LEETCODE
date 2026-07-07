#include <stdio.h>

long long sumAndMultiply(int n) {
    if (n == 0) {
        return 0;
    }

    int digits[12];
    int count = 0;
    
    while (n > 0) {
        int remainder = n % 10;
        if (remainder != 0) {
            digits[count++] = remainder;
        }
        n /= 10;
    }
    
    if (count == 0) {
        return 0;
    }
    
    long long x = 0;
    long long sum = 0;
    
    for (int i = count - 1; i >= 0; i--) {
        x = x * 10 + digits[i];
        sum += digits[i];
    }
    
    return x * sum;
}