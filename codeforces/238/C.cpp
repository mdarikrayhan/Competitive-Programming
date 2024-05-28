#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vi>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set


#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;



vi taken;
vi taken2;

vi green;
vi red;
vector<vector<pii>> AL;

void dfs(int u,int source){
    taken[u]=1;
    for(auto v: AL[u]){
        if(!taken[v.first]) {
            if (v.second == 1) {
                green[source]++;
            } else red[source]++;
            dfs(v.first,source);
        }
    }
}

void count(int u){
    taken[u]=1;
    for(auto v: AL[u]){
        if(!taken[v.first]) {
            if (v.second == 1) {
                green[v.first]=green[u]-1;
                red[v.first]=red[u]+1;
            } else {
                red[v.first] = red[u] - 1;
                green[v.first]=green[u]+1;
            }
            count(v.first);
        }
    }
}

void explore(int u,int &mini){
    taken[u]=1;
    mini=min(mini,red[u]);
    for(auto v: AL[u]){
        if(!taken[v.first]) {
            explore(v.first,mini);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >>n;
    taken.assign(n,0);
    green.assign(n,0);
    red.assign(n,0);
    AL.assign(n,vector<pii>());
    vi indegree(n);
    f(i,0,n-1){
        int a,b; cin>>a>>b; --a; --b;
        AL[a].eb(b,1);
        indegree[b]++;
        AL[b].eb(a,-1);
    }
    dfs(0,0);
    taken.assign(n,0);
    count(0);
    int result=INF;
    int countroots=0;
    f(i,0,n){
        if(indegree[i]==0){
            countroots++;
        }
    }
    if (countroots>2){
        f(i,0,n){
            taken.assign(n,0);
            taken[i]=1;
            vi candidates;
            if(AL[i].size()>=2){
                f(j,0,AL[i].size()){
                    int mini=INF;
                    explore(AL[i][j].first,mini);
                    candidates.pb(mini);
                }
                sort(candidates.begin(),candidates.end());
                result=min(candidates[0]+candidates[1]-red[i],result);
            }
        }

        cout<<((result==INF) ? 0 : result)<<'\n';
    }
    else cout<<0<<'\n';


    return 0;
}