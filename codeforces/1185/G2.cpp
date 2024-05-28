#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pl std::pair<ll, ll>
#define vi std::vector<ll>
#define vii std::vector<vi>
#define viii std::vector<vii>
#define vc std::vector<char>
#define vcc std::vector<vc>
#define vp std::vector<pl>
#define mi std::map<ll,ll>
#define mc std::map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {std::cout << "YES\n"; return;}
#define NO {std::cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

ll getval(vector<viii> &vis, vi X, int lst){
    int mx, mn;
    mx = *max_element(all(X));
    mn = *min_element(all(X));
    if (mn < 0) return (0);
    if (mx == mn && mx == 0) return (1);

    ll &ans = vis[X[0]][X[1]][X[2]][lst];
    if (~ans) return (ans);
    ans = 0;

    for (int i = 0; i < 3; i++)
    {
        if (lst == i) continue;
        X[i]--;
        ans += getval(vis, X, i) * (X[i] + 1);
        ans %= MODE;
        X[i]++;
    }

    return ans;
}

void solve() {
    ll n, k, summ, re, A, B, C, mx = 0;

    cin >> n >> k;

    summ = A = B = C = 0;
    vp X(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i].first >> X[i].second;

        if (X[i].second == 1) A++;
        if (X[i].second == 2) B++;
        if (X[i].second == 3) C++;
        
        X[i].second--;
    }
    sortx(X);        

    vector<viii> Z(k + 1, viii(A + 2, vii(B + 2, vi(C + 2, 0))));
    Z[0][0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = min(k - X[i].first, mx); j >= 0; j--)
        {
            for (int a = 0; a <= A; a++)
            {
                for (int b = 0; b <= B; b++)
                {
                    for (int c = 0; c <= C; c++)
                    {
                        if (Z[j][a][b][c]) {
                            Z[j + X[i].first]
                            [a + (X[i].second == 0)]
                            [b + (X[i].second == 1)]
                            [c + (X[i].second == 2)] += Z[j][a][b][c];

                            Z[j + X[i].first]
                            [a + (X[i].second == 0)]
                            [b + (X[i].second == 1)]
                            [c + (X[i].second == 2)] %= MODE;
                            mx = max(mx, j + X[i].first);
                        }
                    }
                }
            }
        }
    }
        
    vector<viii> vis(A + 1, viii(B + 1, vii(C + 1, vi(4, -1))));
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            for (int h = 0; h <= C; h++)
            {
                if (!Z[k][i][j][h]) continue;
                vi Y = {i, j, h};
                re = getval(vis, Y, 3);           
                //cout << re << ' ' << Y[0] << ' ' << Y[1] << ' ' << Y[2] << '\n';
                summ += re * Z[k][i][j][h];
                summ %= MODE;
            }
        }
    }
    
    cout << summ << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++) {
        solve();
    }
}
