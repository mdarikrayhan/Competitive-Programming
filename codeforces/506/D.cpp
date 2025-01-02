#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef pair<int,int> PII;
const int N=100010,B=300;
array<int,2> Q[N];
vector<array<int,2>> e[N];
int ans[N],p[N];
int find(int x)
{
    if (x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void solve()
{
    int n,m,q;
    cin>>n>>m;
    for (int i=1,x,y,c;i<=m;i++)
    {
        cin>>x>>y>>c;
        e[c].push_back({x,y});
    }
    cin>>q;
    for (int i=0;i<q;i++) cin>>Q[i][0]>>Q[i][1];
    map<array<int,2>,int> mp;
    for (int i=1;i<=m;i++)
        if (e[i].size()>=B)
        {   
            for (int i=1;i<=n;i++) p[i]=i;
            for (auto [x,y]:e[i]) p[find(x)]=find(y);
            for (int i=0;i<q;i++) ans[i]+=find(Q[i][0])==find(Q[i][1]);
        }
        else
        {
            vector<int> point;
            for (auto [x,y]:e[i]) p[x]=x,p[y]=y,point.push_back(x),point.push_back(y);
            sort(point.begin(),point.end());
            point.erase(unique(point.begin(),point.end()),point.end());
            for (auto [x,y]:e[i]) p[find(x)]=find(y);
            for (int i=0;i<point.size();i++)
                for (int j=i+1;j<point.size();j++)
                {
                    int a=point[i],b=point[j];
                    if (find(a)!=find(b)) continue;
                    if (a>b) swap(a,b);
                    mp[{a,b}]++;
                }
        }
    for (int i=0;i<q;i++) ans[i]+=mp[{min(Q[i][0],Q[i][1]),max(Q[i][0],Q[i][1])}];
    for (int i=0;i<q;i++) cout<<ans[i]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}