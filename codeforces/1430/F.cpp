#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define random(l, r) (l + rand() % (r - l + 1))
#define int long long
#define maxn 200005
#define bit(x, i) ((x >> i) & 1)
#define pii pair<int, int>
#define MOD 1000000007
#define Task "EDU_96_F"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int n,k,l[maxn],r[maxn],w[maxn],du[maxn],ans = 0;
ordered_set st[10105];
void Add(int &a,int b){
    a += b;
    if(a >= MOD)a -= MOD;
    if(a < 0)a += MOD;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i] >> w[i];
        ans += w[i];
    }
    for(int i = n;i >= 1;i--){
        int val = w[i];
        if(r[i] == l[i + 1])val += du[i + 1];
        du[i] = max(0ll,val - (r[i] - l[i]) * k);
        if(du[i] > k){
           cout << -1;
           return 0;
        }
        //cout << i << " " << du[i] << '\n';
    }
    int val = k;
    for(int i = 1;i <= n;i++){
        if(du[i] > val){
           ans += val;
           val = k;
        }
        val = (val - w[i] % k + k) % k;
    }
    cout << ans;
}
