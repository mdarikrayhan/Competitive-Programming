
/*بسم الله الرحمن الرحيم */
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


const int N = 1e5 + 5;
int parent[N], sz[N];

void initial()
{
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int getRoot(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = getRoot(parent[u]);
}
bool sameSet(int u, int v)
{
    return getRoot(u) == getRoot(v);
}

void merge(int u, int v)
{
    u = getRoot(u);
    v = getRoot(v);
    if (u == v)  return;
    parent[u] = v;
    sz[v] += sz[u];
}

void solve()
{
    int n;cin >> n;
    initial();
    vector<int>v(n + 1);
    vector<vector<int>>root(n + 1);
    for(int i = 1 ; i <= n ; i++)cin >> v[i];
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            char x;cin >> x;
            if(x == '1')merge(i , j);
        }
    }
    for(int i = 1 ; i <= n ; i++)root[getRoot(i)].push_back(v[i]);
    for(int i = 1 ; i <= n ; i++) {
        sort(root[getRoot(i)].rbegin() , root[getRoot(i)].rend());
        cout << root[getRoot(i)].back() << ' ';
        root[getRoot(i)].pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll _ = 1;
    //cin >> _;
    for (ll __ = 1; __ <= _; __++) {
        solve();  
        //cout << '\n';
    }
}

 			 	  		 	   		  	 	  	  	 		