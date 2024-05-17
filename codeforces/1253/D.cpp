#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define fr(i, a, b) for (ll i = a; i < b; i++)

ll mod = 998244353;

ll exponent(ll n, ll ind)
{
    if(ind==0)
        return 1;
    if(ind==1)
        return n%mod;
    ll ans = exponent(n,ind/2)*exponent(n,ind/2);
    ans %= mod;
    if(ind%2==0)
        return ans;
    else
        return (ans*n)%mod;
}


void bfs(int src, vb &vis, vi adj[], vi &comp, int t)
{
    comp[src] = t;
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        fr(j, 0, adj[curr].size())
        {
            if(!vis[adj[curr][j]])
            {
                q.push(adj[curr][j]);
                vis[adj[curr][j]] = true;
                comp[adj[curr][j]] = t;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        vi adj[n+1];
        fr(i, 0, m)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> comp(n+1,0);
        vector<bool> vis(n+1, false);
        vi diff;
        int t = 0;
        fr(i, 1, n+1)
        {
            if(!vis[i])
            {
                t++;
                diff.push_back(t);
                bfs(i, vis, adj, comp, t);
            }
        }
        vector<int> max_el(n+1,0);
        fr(i, 1, n+1)
        {
            max_el[comp[i]] = i;
        }
        // cout << "Comp : \n";
        // fr(i, 1, n+1)
        // {
        //     cout << comp[i] << " ";
        // }
        // cout << endl;
        // cout << "Diff : \n";
        // fr(i, 0, diff.size())
        // {
        //     cout << diff[i] << " ";
        // }
        // cout << endl;
        // cout << "MAX_EL : \n";
        // fr(i, 0, diff.size())
        // {
        //     cout << max_el[diff[i]] << " ";
        // }
        // cout << endl << endl;
        vector<pii> edge;
        int ans = 0;
        int curr = 1;
        int upto = max_el[1];
        vi last_added(n+1,-1);
        fr(i, 1, n+1)
        {
            if(i>upto)
            {
                curr = comp[i];
                upto = max_el[curr];
            }
            else if(comp[i]!=curr && comp[i]>last_added[curr])
            {
                ans++;
                last_added[curr] = comp[i]; 
            }
            upto = max(upto, max_el[comp[i]]);
        }
        cout << ans << endl;
    }
      
}