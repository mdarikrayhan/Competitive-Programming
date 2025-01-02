#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#define clr(a,v) memset(a,v,sizeof(a))

typedef __int64 ll;
const int maxn = 200;

int n, D;
int arr[maxn];
int mat[maxn][maxn];
std::pair<int, int>  pt[maxn];
bool inq[maxn];
ll d[maxn];



int dis(int i, int j) {
    return abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second);
}

ll sol(int s) {
   std::queue<int> Q;
    clr(inq, 0);
    for (int i = 1; i <= n; i++)
        d[i] = LLONG_MAX;

    d[s] = 0, inq[s] = true, Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int v = 1; v <= n; v++) {
            if (v == u) continue;
            if (d[v] > d[u] + mat[u][v]) {
                d[v] = d[u] + mat[u][v];
                if (!inq[v]) 
                    Q.push(v); inq[v] = 1;
            }
        }
    }
    return d[1];
}

int main() {
    std::cin >> n >> D;
    arr[1] = arr[n] = 0;
    for (int i = 2; i < n; i++) 
        std::cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        std::cin >> pt[i].first >> pt[i].second;    }

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (i == j) mat[i][j] = 0;
            else mat[i][j] = dis(i, j) * D - arr[j];

    std::cout << sol(n) << "\n";

    return 0;
}
