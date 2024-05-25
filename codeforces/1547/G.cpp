#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e5 * (2ll * 2ll) + 100ll;

vector<ll>g[N];
map<ll, ll>used;
vector<ll>black;
vector<ll>cycle;
void dfs(ll v){

used[v] = 1ll;

for(auto to : g[v]){

    if(used[to] == 2){
        black.push_back(to);
    }
    else if(used[to] == 1){

        cycle.push_back(to);

    }
    else if(used[to] == 0){

        dfs(to);

    }

}

used[v] = 2ll;

}
map<ll, ll>used2;
map<ll, ll>used3;
set<ll>infin;
set<ll>con;
void dfs2(ll v){

used2[v] = 1ll;

infin.insert(v);

for(auto to : g[v]){

    if(used2[to] == 0){

        dfs2(to);
    }

}

}

void dfs3(ll v){

used3[v] = 1ll;

if(used2[v] != 1ll) con.insert(v);

for(auto to : g[v]){

    if(used3[to] == 0){

        dfs3(to);
    }

}

}

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

ll t;
cin >> t;
while(t--){

    ll n, m;
    cin >> n >> m;


    for(ll i = 1; i <= m; ++i){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
      //  g[b].push_back(a);
    }

    dfs(1);
    for(auto x : cycle){

        dfs2(x);

    }

   // for(ll i = 1; i <= n; ++i){
   //     cout << used2[i] << " ";
   // }
   // cout << endl;

    for(auto x : black){

        dfs3(x);

    }

    for(ll i = 1; i <= n; ++i){

        if(used[i] == 0){
            cout << 0 << ' ';
        }
        else if(used2[i] == 1){

            cout << -1 << ' ';

        }
        else if(used3[i] == 1 and used2[i] != 1){

            cout << 2 << ' ';

        }
        else{

            cout << 1 << ' ';

        }

    }

    cout << '\n';




    for(ll i = 1; i <= n; ++i){
        used[i] = 0;
        used2[i] = 0;
        used3[i] = 0;
        g[i].clear();
    }

    infin.clear();
    con.clear();
    black.clear();
    cycle.clear();
}

return 0;

}
