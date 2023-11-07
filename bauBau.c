#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w, int g[], int v[], int s[]) {
    int c[n + 1][w + 1];
    short int items[n][w + 1];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= w; j++) {
            if (j - g[i] < 0)
                c[i + 1][j] = c[i][j];
            else {
                c[i + 1][j] = max(c[i][j - g[i]] + v[i], c[i][j]);
                if (c[i][j - g[i]] + v[i] > c[i][j])
                    items[i][j] = 1;
            }
        }
    }
    for (i = n - 1, j = w; i >= 0; i--) {
        if (items[i][j] == 1) {
            printf("%d ", s[i]);
            j -= g[i];
        }
    }
    printf("\n%d\n", c[n][w]);
}

int main() {
    int w, a, b, c;
    int n = 0;
    int v[8001], g[8001], s[8001];
    scanf("%d", &w);
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        s[n] = a;
        g[n] = b;
        v[n++] = c;
    }
    knapsack(n, w, g, v, s);
    return 0;
}
