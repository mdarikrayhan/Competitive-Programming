#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
const ll MOD = 1e9 + 7,  N=105, X = 12e3;
ll n, m;
vector<int>adj[N];
int build(vector<ll>v,int idx,int sz)
{
    if(idx>sz)
        return 0;
    if(idx==sz)
        return v[idx];
    int x;
    x = max_element(v.begin() + idx, v.begin() + sz+1) - v.begin();

    int z =build(v ,idx,x-1);
    if(z)
    adj[v[x]].push_back(z);

    int a =build(v,x+1,sz);
    if(a)
      adj[v[x]].push_back(a);
    return v[x];
}
vector<int>ans(N);
void rec(int idx,int cnt)
{
    if(idx==0)
        return;
    ans[idx]= cnt;
    for(auto&x:adj[idx])
    {
       rec(x,cnt+1);
    }
}
void sol() {
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        adj[i].clear();
        ans[v[i]]=0;
    }
    build(v,0,n-1);
    rec(n,0);
    for(int i=1;i<=n;i++)cout<<ans[v[i-1]]<<" ";
}


void file() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    file();
    int tests = 1;
    cin >> tests;
    while (tests--) {
        sol();
        cout << nl;
    }
    return 0;
}