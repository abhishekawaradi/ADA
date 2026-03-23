#include <stdio.h>
#define INF 999
#define MAX 100
int p[MAX], c[MAX][MAX];
int find(int v) {
    while (p[v] != 0)
        v = p[v];
    return v;
}
void union1(int u, int v) {
    p[v] = u;
}
void kruskal(int n) {
    int i, j, k;
    int u, v;
    int min, cost = 0;
    printf("Edges in MST:\n");
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {   
                if (c[i][j] != 0 && c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        min = c[i][j];
                        int a = i, b = j;
                        union1(u, v);
                        printf("%d -> %d\n", a, b);
                        cost += min;
                    }
                }
            }
        }
    }
    printf("Minimum Cost = %d\n", cost);
}
int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        p[i] = 0;
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    kruskal(n);
    return 0;
}
