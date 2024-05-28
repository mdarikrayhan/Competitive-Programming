#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 4e4 + 10;
int f[N];
bool a[2][N];
int n, m;

int find(int u){
    if(f[u] == u) return u;
    return f[u] = find(f[u]);
}

void work(){
    cin >> n >> m;
    ll res = 0;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;

        int u = i & 1;
        for(int j = 1; j <= m / 4; j++){
            int sign = 0;
            if(isdigit(s[j - 1])) sign = s[j - 1] - '0';
            else sign = s[j - 1] - 'A' + 10;

            a[u][j * 4] = (sign & 1); res += (sign & 1); sign >>= 1;
            a[u][j * 4 - 1] = (sign & 1); res += (sign & 1); sign >>= 1;
            a[u][j * 4 - 2] = (sign & 1); res += (sign & 1); sign >>= 1;
            a[u][j * 4 - 3] = (sign & 1); res += (sign & 1); sign >>= 1;
        }

        int d = u * m;

        for(int j = 1; j <= m; j++) f[d + j] = d + j;
        for(int j = 1; j < m; j++){
            if(a[u][j] && a[u][j + 1]){
                int x = d + j;
                int y = x + 1;

                int fx = find(x), fy = find(y);
                if(fx != fy){
                    f[fy] = fx;
                    res--;
                }
            }
        }

        for(int j = 1; j <= m; j++){
            if(a[u][j] && a[u ^ 1][j]){
                int x = d + j;
                int y = (u ^ 1) * m + j;

                int fx = find(x), fy = find(y);
                if(fx != fy){
                    f[fy] = fx;
                    res--;
                }
            }
        }
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}