//JAI SHREE RAM
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18
#define MAXN 1123456
#define MOD 1000000007
/*
-----------------------------ordered set--------------------
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;  

typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
*/  
/*-----------------PRIME FACTOR-------------
for (int i = 2; i*i <= n; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
*/
/*-----------------------sieve----------------
vector<bool> prime(MAXN, false);
vector<bool> used(MAXN, false);
void precalc() {
    for (int i = 2; i < MAXN; ++i) {
        if (!   used[i]) {
            prime[i] = true;
            for (int j = i; j < MAXN; j += i) {
                used[j] = true;
            }
        }
    }
}*/
/*--------------------------------sqrt function------------------------
ll my_sqrt(ll a)
{
    ll l=0,r=5000000001;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
int getclosest(int x)
{
    int n = sqrt(x);
    if(n*n==x)
    {
        return 0;
    }
    else
    {
        return (n+1)*(n+1) - x;
    }
}

const int N = 40004;
const int M = 502;
int dp[N][M];

int reverse(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n = n / 10;
    }
    return r;
}

int palindrome(int i) {
    return reverse(i) == i;
}

void precompute_palindromes(vector<int>& palin) {
    palin.push_back(0);
    for (int i = 1; i < 2 * N; i++) {
        if (palindrome(i)) {
            palin.push_back(i);
        }
    }
}
*/
const int maxn = 1e6 + 1;

vector<int> bg[maxn], rg[maxn];
int b[maxn], r[maxn], d[maxn], col[maxn];
int n, m;

void solve() 
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        if (!t) bg[v].push_back(u);
        else rg[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        d[i] = b[i] = r[i] = n;
    queue<int> q;
    q.push(n - 1);
    d[n - 1] = r[n - 1] = b[n - 1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto to : bg[x]) {
            if (b[to] < n) continue;
            b[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
        for (auto to : rg[x]) {
            if (r[to] < n) continue;
            r[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
    }
    if (d[0] == n) cout << "-1\n";
    else cout << d[0] << '\n';
    for (int i = 0; i < n; i++) {
        if (b[i] > r[i]) col[i] = 0;
        else col[i] = 1;
        cout << col[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while (t--) {
        solve();
    }
    return 0;
}
