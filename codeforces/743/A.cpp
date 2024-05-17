#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define  pi acos(-1)
#define el cout<<"\n";
#define FIO ios_base::sync_with_stdio(0);cin.tie(0)
#define  ll long long
#define NO cout <<"NO\n"
#define YES cout <<"YES\n"

const int MOD = 1e9 + 7,M=1e7+5;
int prime[M];

set<ll>primess;

vector<ll>primes;
void sieve() {
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= M; ++i)
        if (prime[i]) {
            primes.push_back(i);
            primess.insert(i);
            for (int j = i * i; j < M; j += i)
                prime[j] = false;
        }
}
void FileIO(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return ((a - b) % MOD + MOD) % MOD;
}

int mul(ll a, ll b) {
    return 1ll * a * b % MOD;
}

int power_recursive(ll b, ll p) {
    if (p == 0) return 1;
    ll sub = power_recursive(b, p / 2);
    ll ans = mul(sub, sub);
    if (p & 1) ans = mul(ans, b);
    return ans;
}
//const int N =1e6+5;
//vector<int>out[N],in[N],g[N];
//int vis[N],comp[N],root[N],vid,n,m,indeg[N];
//vector<int>topo,roots,cur_comp;
bool vis[1005];
int main() {
    FIO;
    // FileIO();
    int tc = 1;
   // cin >> tc;
    //sieve();
    while (tc--)
    {
        int n,x,y;cin>>n>>x>>y;
        string s;cin>>s;
        cout<<!(s[x-1]==s[y-1]);

    }
    return 0;
}
