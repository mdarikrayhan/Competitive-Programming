#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 2e5 + 10;
vector<int> e[N];
bool vis[N];
int x[N], y[N], c[N];

void dfs(int u, int fa, int col){
    c[u] = col;
    vis[u] = 1;

    for(auto v : e[u]){
        if(v == fa) continue;

        if(!vis[v]) dfs(v, fa, 3 - col);
    }
}

void work(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];

        e[x[i]].push_back(y[i]);
        e[y[i]].push_back(x[i]);
    }

    for(int i = 1; i <= n; i++){
        e[2 * i].push_back(2 * i - 1);
        e[2 * i - 1].push_back(2 * i);
    }

    for(int i = 1; i <= 2 * n; i++){
        if(!vis[i]) dfs(i, 0, 1);
    }

    for(int i = 1; i <= n; i++){
        cout << c[x[i]] << " " << c[y[i]] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}