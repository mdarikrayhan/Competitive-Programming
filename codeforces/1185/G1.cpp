#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll unsigned int
#define ld long double
#define pl std::pair<int, int>
#define vi std::vector<int>
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

void solve() {
    ll n, k, at = 0;

    cin >> n >> k;

    vp X(n);
    deque<vii> Z(20, vii(1 << n, vi(3, 0)));

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
        X[i].second -= 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (X[i].first <= k)
        Z[X[i].first][(1 << i)][X[i].second] += 1;
    }

    for (int i = 0; i < k; i++)
    {
        i -= at;
        for (int j = 0; j < Z[i].size(); j++)
        {
            for (int h = 0; h < 3; h++)
            {
                for (int g = 0; g < n; g++)
                {
                    while (X[g].first + i >= Z.size()) {
                        Z.push_back(vii(1 << n, vi(3, 0)));
                    }
                    
                    if (j & (1 << g)) continue;
                    if (X[g].first + i > k || X[g].second == h) continue;
                    Z[i + X[g].first][j | (1 << g)][X[g].second] += Z[i][j][h];
                    Z[i + X[g].first][j | (1 << g)][X[g].second] %= MODE;
                }
            }
        }
        i += at;
        at ++;
        Z.pop_front();
    }
    
    ll summ = 0;

    for (int i = 0; i < Z[0].size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            summ += Z[0][i][j];
            summ %= MODE;
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

   					 	 	    			 	 			     	