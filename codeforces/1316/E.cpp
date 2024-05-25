#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int maxP = 8;
const int MOD = 1e9 + 7;

ll n, p, K;
ll a[maxN], str[maxN][maxP];
ll f[maxN][1 << maxP], id[maxN];

void ReadInput()    
{
    cin >> n >> p >> K;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> str[i][j];
    iota(id, id + n, 0);
    sort(id, id + n, [](int i, int j)
    {
        return a[i] > a[j];
    });
}

void Solve()
{
    memset(f, -0x3f, sizeof(f));
    f[0][0] = a[id[0]];
    for (int i = 0; i < p; i++)
        f[0][1 << i] = str[id[0]][i];
    for (int t = 1; t < n; t++)
        for (int mask = 0; mask < (1 << p); mask++)
        {
            int i = id[t];
            for (int j = 0; j < p; j++)
                if (mask & (1 << j))
                    f[t][mask] = max(f[t][mask], f[t - 1][mask ^ (1 << j)] + str[i][j]);
            f[t][mask] = max(f[t][mask], f[t - 1][mask]);
            if (t - __builtin_popcount(mask) < K) 
                f[t][mask] = max(f[t][mask], f[t - 1][mask] + a[i]);
        }
    cout << f[n - 1][(1 << p) - 1];
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

 	 					 	   	 	 	 			       	