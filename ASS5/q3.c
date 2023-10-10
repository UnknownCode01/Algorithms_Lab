#include <stdio.h>

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    int gcd = numbers[0];
    int lcm = numbers[0];    
    for (int i = 1; i < n; i++) {
        gcd = findGCD(gcd, numbers[i]);
        lcm = findLCM(lcm, numbers[i]);
    }

    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n", lcm);

    return 0;
}
