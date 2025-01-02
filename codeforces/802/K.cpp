/*----- ॐ नमः शिवाय -----*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
typedef pair<ll,ll> pii;
#define INF 1e15

ll n,l;
vector<pii> adj[100010];
ll dp[100010][2];

bool compare(pii a, pii b) {
    return a.first > b.first; 
}

void dfs(ll u, ll p) {
    dp[u][1] = 0; dp[u][0] = 0;
    vector<pii> v;
    ll temp1 = -1*INF;
    //vertex to w+dp[c][0]
    unordered_map<ll,ll> m1;
    //vertex to dp[c][0]-dp[c][1]
    unordered_map<ll,ll> m2;
    for(auto& pr : adj[u]) {
        if(pr.first != p) {
            ll ver = pr.first; ll w = pr.second;
            dfs(ver,u);
            temp1 = max(temp1, dp[ver][0] - dp[ver][1]);
            v.push_back({w+dp[ver][1],ver});
            m1[ver] = w+dp[ver][0];
            m2[ver] = dp[ver][0] - dp[ver][1];
        }
    }
    sort(v.begin(), v.end(), compare);
    v.resize(v.size());
    ll x = v.size();
    for(int i=0; i<min(l-1,x); i++) {
        dp[u][1] += v[i].first;
    }

    if(l >= v.size()) {
        ll temp = 0;
        for(int i=0; i<v.size(); i++) temp += v[i].first;
        if(temp1 != -1*INF) dp[u][0] = temp + temp1;
    }
    else {
        ll temp = 0;
        for(int i=0; i<=(l-2); i++) {
            temp += v[i].first;
        }
        ll tmp1 = -1*INF, tmp2 = -1*INF;
        for(int i=0; i<l; i++) tmp1 = max(tmp1,m2[v[i].second]);
        for(int i=l; i<v.size(); i++) tmp2 = max(tmp2,m1[v[i].second]);
        if(tmp1 != -1*INF || tmp2 != -1*INF) dp[u][0] = max(temp+tmp2,temp+v[l-1].first+tmp1);
    }
}

int main() {
    cin >> n >> l;
    for(int i=1; i<n; i++) {
        ll u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dfs(0,-1);
    cout<<dp[0][0]<<endl;
}