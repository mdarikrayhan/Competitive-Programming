// LUOGU_RID: 160513680
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m;
int p[N];
ll siz[N], s[N];
struct Edge{
    int u, v, w;
}edges[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i ++ )
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    sort(edges + 1, edges + n, [](Edge &x, Edge &y){
        return x.w < y.w;
    });
    for (int i = 1; i <= n; i ++ ) p[i] = i, siz[i] = 1;

    for (int i = 1; i < n; i ++ ){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        u = find(u), v = find(v);
        s[w] += siz[u] * siz[v];
        p[u] = v;
        siz[v] += siz[u];
    }

    for (int i = 1; i <= 2e5; i ++ ) s[i] += s[i - 1];
    while (m -- ){
        int w;
        scanf("%d", &w);
        printf("%lld ", s[w]);
    }
}