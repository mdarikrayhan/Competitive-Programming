#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    const int m = (n + 1) / 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int> > b(n, vector<int>(n));
    
    auto get = [&](int x, int y){
        if (b[x][y] == 0) return a[x][y];
        return -a[x][y];
    };
    
    int ans = -1e9;
    for(int i = 0; i < 1 << m; i++){
        for(int j = 0; j < m; j++){
            b[j][m - 1] = i >> j & 1;
        }
        for(int j = m; j < n; j++){
            b[j][m - 1] = b[j - m][m - 1] ^ b[m - 1][m - 1];
        }
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += get(j, m - 1);
        }
        for(int j = 0; j < m - 1; j++){
            int mx = -1e9;
            for(int t = 0; t < 2; t++){
                int s = 0;
                b[m - 1][j] = t;
                b[m - 1][j + m] = b[m - 1][j] ^ b[m - 1][m - 1];
                s += get(m - 1, j) + get(m - 1, j + m);
                for(int k = 0; k < m - 1; k++){
                    int mx2 = -1e9;
                    for(int l = 0; l < 2; l++){
                        b[k][j] = l;
                        b[k][j + m] = b[k][j] ^ b[k][m - 1];
                        b[k + m][j] = b[k][j] ^ b[m - 1][j];
                        b[k + m][j + m] = b[k][j + m] ^ b[m - 1][j + m];
                        mx2 = max(mx2, get(k, j) + get(k, j + m) + get(k + m, j) + get(k + m, j + m));
                    }
                    s += mx2;
                }
                mx = max(mx, s);
            }
            sum += mx;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';

}