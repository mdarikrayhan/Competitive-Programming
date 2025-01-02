#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 7 ;
const ll OO = 1e18 + 5 ;
const ll N = 5e5 + 5   ;
using namespace std;
ll n , y , vis[N] , noty[N] , tt = 1 ;

set < ll > adj[27] , In[27] ;
string s[N] , g = "" ;

bool ok = true ;

void dfs(ll u , ll par)
{
    y += 1 ;
    g += char(u + 'a') ;
    vis[u] = true ;
    ok &= ((ll)adj[u].size() <= 1) ;
    for(auto v : adj[u])
    {
        if(v == par || vis[v])continue ;
        dfs(v , u) ;
    }
}


int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    //cin >> tt ;
    while(tt--)
    {
        cin >> n ;

        ll x = 0 ;
        for(ll i = 0 ; i < n ; ++i)
        {
            cin >> s[i] ;
            for(ll j = 0 ; j < (ll)s[i].size() ; ++j)noty[s[i][j] - 'a'] = true ;
            for(ll j = 0 ; j + 1 < (ll)s[i].size() ; ++j)
            {
               adj[s[i][j] - 'a'].insert(s[i][j + 1] - 'a') ;
               In[s[i][j + 1] - 'a'].insert(s[i][j] - 'a') ;
            }
        }

        for(ll i = 0 ; i <= 25 ; ++i)x += noty[i] ;


        vector < string > vec ;

        for(ll i = 0 ; i <= 25 ; ++i)
        {
            ok &= ((ll)In[i].size() <= 1) ;
            if(vis[i] || (ll)In[i].size() != 0 || noty[i] == false)continue ;
            dfs(i , -1) ;
            vec.push_back(g) ;
            g = "" ;
        }

        sort(vec.begin() , vec.end()) ;


        if(ok == false || x != y){
            cout << "NO\n";
            continue;
        }

        for(auto x : vec)
            cout << x ;





    }


}



