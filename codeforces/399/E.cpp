#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;
int n;
int main() {
    cin >> n;
    if(n == 5) {
        bool found = 0;
        srand(124);
        do { //genereaza
            vector<int> Sum(5);
            vector<int> L[5];
            vector<tuple<int, int, int> > Muchii;
            vector<vector<int> > Dist(5, vector<int>(5));
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j) Dist[i][j] = INF;
            for(int i = 0; i < 5; ++i) Dist[i][i] = 0;
            for(int i = 1; i < 5; ++i) {
                int a, b, c;
                do {
                    a = rand() % 5;
                    b = rand() % 5;
                    c = rand() % 25;
                } while(a == b);
                if(a > b) swap(a, b);
                for(int j = a; j <= b; ++j) Sum[j] += c;
                Muchii.push_back({a, b, c});
                Dist[a][b] = Dist[b][a] = c;
            }
            for(int k = 0; k < 5; ++k)
                for(int i = 0; i < 5; ++i)
                    for(int j = 0; j < 5; ++j)
                        Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j)
                    if(Dist[i][j] == INF) continue;
            int nr_ok = 0;
            for(int i = 1; i < 5; ++i) Sum[i] += Sum[i-1];
            for(int i = 0; i < 5; ++i)
                for(int j = i+1; j < 5; ++j)
                    if(Dist[i][j] == Sum[j] - (i?Sum[i-1]:0)) ++nr_ok;
            if(nr_ok > 1) {
                found = 1;
                for(auto [a, b, c] : Muchii) printf("%d %d %d\n", a+1, b+1, c);
                for(int i = 0; i < 5; ++i)
                for(int j = i+1; j < 5; ++j)
                    if(Dist[i][j] == Sum[j] - (i?Sum[i-1]:0))
                        printf("%d %d\n", i+1, j+1);
            }
        } while(!found);
    } else {
        for(int i = 1; i <= n/2; ++i) printf("%d %d %d\n", i, i + n/2, 1);
        for(int i = n/2+1; i < n; ++i) printf("%d %d %d\n", i, i + 1, (i-n/2) * 2 - 1);
        for(int i = 1; i < n/2; ++i) printf("%d %d\n", i, i + 1);
        printf("1 3\n");
    }
    return 0;
}
