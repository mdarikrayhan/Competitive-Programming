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
#define Task "C_796(DIV1)"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int n,m,q,a[maxn];
ordered_set st[10105];
vector<int>luu[maxn];
void Add(int &a,int b){
    a += b;
    if(a >= MOD)a -= MOD;
    if(a < 0)a += MOD;
}
queue<int>qu;
set<int>s;
void solve(){
    while(!qu.empty()){
         int u = qu.front();
         //cout << u << '\n';
         qu.pop();
         for(int i = 0;i < luu[u].size();i++){
            int v = luu[u][i];
            if(s.find(v) != s.end())continue;
            auto it = s.lower_bound(min(u,v));
            while(it != s.end() && *it <= max(u,v)){
               qu.push(*it);
               s.erase(it++);
            }
         }
    }
    if(!s.size())cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
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
        cin >> n >> m;
        s.clear();
        for(int i = 1;i <= n;i++)cin >> a[i];
        for(int i = 1;i <= n;i++){
            int val;
            cin >> val;
            a[i] = a[i - 1] + a[i] - val;
        }
        for(int i = 0;i <= n;i++){
            if(a[i])s.insert(i);
            else qu.push(i);
            luu[i].clear();
        }
        for(int i = 1;i <= m;i++){
            int l,r;
            cin >> l >> r;
            l--;
            luu[l].push_back(r);
            luu[r].push_back(l);
        }
        //for(int x : s)cout << x << " ";
        solve();
    }
}
