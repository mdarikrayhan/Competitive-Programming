#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<int>g[N];
int subSz[N];
double st[N];

void dfs(int v, int p){
    subSz[v]=1;
    for(int ch:g[v]){
        dfs(ch,v);
        subSz[v]+=subSz[ch];
    }
}

void dfs2(int v, int p){
    if(v==1) st[v]=1;
    else{
        double other = subSz[p]-subSz[v]-1;
        st[v] = st[p] + 1 + other/2;
    }

    for(int ch: g[v]){
        dfs2(ch,v);
    }
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    dfs(1,0);
    dfs2(1,0);

    cout << setprecision(12);
    for(int i=1;i<=n;i++) cout << st[i]<<" ";
}