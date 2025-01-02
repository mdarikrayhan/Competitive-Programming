#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SZ = 256;

int v[SZ][SZ];

void Solve(){
    int n, m;
    cin >> n >> m;

    cout << n * m << '\n';

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << v[i][j] << " \n"[j + 1 == m];
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    {
        int now = 0;
        int n = 256;
        int m = 256;

        for(int i = 0; i < n; i += 2)
            for(int j = 0; j < m; j += 2){
                v[i][j] = now;
                v[i][j + 1] = now + 1;
                v[i + 1][j] = now + 2;
                v[i + 1][j + 1] = now + 3;
                now += 4;
            }
    }

    int num_test = 1;
    cin >> num_test;

    for(int i = 1; i <= num_test; i++){
        Solve();
    }
}