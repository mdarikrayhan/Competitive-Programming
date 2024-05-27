#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef long long ll;
 
using namespace std;
 
const ll INF = 1e18;
const double pi = acos(-1.0), eps = 1e-9;
const int N = 3e5 + 111, inf = 1e9, mod = 1e9 + 7;
 
ll ans;
int n, a, b, g[N], k[N], la[N], ra[N], f[N], cnt;
bool ok[N], used[N];

void rec(int v){
    if(v == b)
        return;
    if(v == inf || v == -1){
        cout << -1;
        exit(0);
    }
    if(used[v]){
    	cout << -1;
    	exit(0);
    }
    used[v] = 1;
    if(v < b){
        ans += b - v;
        rec(f[v]);
    }else{
        ans += v - b;
        rec(f[v]);
    }
}
 
int main(){
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

    //srand(time(NULL));
 
    //cin.tie(0);
    //cout.tie(0);
    //ios_base::sync_with_stdio(0);
 
    //cout << setprecision(10) << fixed;
 
    scanf("%d%d%d", &n, &a, &b);
    swap(a, b);
   
    for(int i = 1; i < n; ++i)
        scanf("%d", &g[i]);
 
    for(int i = 1; i <= n; ++i)
        scanf("%d", &k[i]);
 
    if(a > b){
        reverse(g + 1, g + n);
        reverse(k + 1, k + n + 1);
        a = n - a + 1;  
        b = n - b + 1;
    }
 
    f[b] = b;
 
    for(int i = 1; i <= 100000; ++i)
        la[i] = -1, ra[i] = inf;
 
    for(int i = b; i >= a; --i)
        la[k[i]] = max(la[k[i]], i);
 
    for(int i = b; i <= n; ++i)
        ra[k[i]] = min(ra[k[i]], i);
 
    ok[k[b]] = 1;
    int cur = b;
 
    for(int i = b - 1; i >= a; --i){
        if(!ok[g[i]])
            cur = max(cur, ra[g[i]]);
        f[i] = cur;
        ok[k[i]] = 1;
    }
    cur = b;
    memset(ok, 0, sizeof ok);
    ok[k[b]] = 1;
    for(int i = b + 1; i <= n; ++i){
        if(!ok[g[i - 1]])
            cur = min(cur, la[g[i - 1]]);
        f[i] = cur;
        ok[k[i]] = 1;
    }

    rec(f[a]);

    ans *= 2;
 
    if(ans >= INF)
        ans = -1;
    else ans += b - a; 
 
    cout << ans;
 
    //cout << (clock() + 0.0) / CLOCKS_PER_SEC;
    return 0;
}
