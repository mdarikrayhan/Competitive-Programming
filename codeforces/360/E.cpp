#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define task "HACK" 
const int N = 1e4 + 1 ; 
struct Data
{
    int u , v ;
    void Read1(){
        cin >> u >> v >> w ; 
    } 
    void Read2(){
        cin >> u >> v >> l >> r ; 
        w = r ; 
    }
    long long w, l , r ; 
}E[N + 200];
int n , m , k , s1 , s2 , t; 
vector<int> D[N] ; 
long long d1[N] , d2[N] ;
void Dij(int t, long long d[]){
    for(int i = 1 ; i <= n ; i++) d[i] = 1e18 ; 
    d[t] = 0 ; 
    priority_queue<pair<long long , int>> Q;
    Q.push({0 , t}) ; 
    while(Q.size()){
        long long w , u ; 
        tie(w , u) = Q.top(); Q.pop() ; 
        w =-w ; 
        if(d[u] != w) continue; 
        for(int id : D[u]){
            int v = E[id].v ; 
            if(d[v] > w + E[id].w){
                d[v] = w + E[id].w ; 
                Q.push({-d[v], v}) ; 
            }
        }
    }
} 
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    if(ifstream(task".INP")){
        freopen(task".INP","r",stdin) ; 
        freopen(task".OUT","w",stdout) ;
    }
    cin >> n >> m >> k >> s1 >> s2 >> t ; 
    for(int i = 1 ; i <= m ;i++){
        E[i].Read1() ;
        D[E[i].u].push_back(i) ;  
    }
    for(int i = 1 ; i <= k ; i++){
        E[i + m].Read2() ; 
        D[E[i + m].u].push_back(i + m) ; 
    }
    Dij(s1 , d1); 
    Dij(s2 , d2); 
    int last = k ; 
    while(d1[t] >= d2[t] && last){
        int node = 0 ; 
        for(int i = 1 + m ; i <= k + m ; i++) 
            if(E[i].w == E[i].r){
                if(d1[E[i].u] < d2[E[i].u]){
                    E[i].w = E[i].l;
                    last--; 
                    node = 1 ;
                    continue; 
                }
            }
        if(!node) break; 
        Dij(s1 , d1) ;
        Dij(s2 , d2) ; 
    }
    if(d1[t] <= d2[t]){
        cout<<(d1[t] < d2[t] ? "WIN\n":"DRAW\n") ; 
        for(int i = 1 + m ; i <= m + k ;i++){
            cout << E[i].w<<" " ; 
        }
    }else cout << "LOSE" ; 
    return 0;
}