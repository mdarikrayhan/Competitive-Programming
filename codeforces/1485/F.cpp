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
#define Task "A"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int n,q,a[maxn];
ordered_set st[10105];
void Add(int &a,int b){
    a += b;
    if(a >= MOD)a -= MOD;
    if(a < 0)a += MOD;
}
map<int,int>mp;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> q;
    while(q--){
        cin >> n;
        mp.clear();
        int ans = 1,sum = 0;
        mp[0] = 1;
        for(int i = 1;i <= n;i++)cin >> a[i];
        for(int i = 1;i <= n;i++){
            int du = mp[sum];
            mp[sum] = ans;
            ans = (ans * 2 - du + MOD) % MOD;
            sum -= a[i];
        }
        cout << ans << '\n';

    }
}
