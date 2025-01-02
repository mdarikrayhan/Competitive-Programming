#include<bits/stdc++.h>
#define LL long long 
#ifdef ONLINE_JUDGE
#define N 500005
#else 
#define N 101
#endif
using namespace std;

vector <int> c[N];


LL n,m,k;
int dep[N];
vector <int> a;
// priority_queue <int,vector<int>,greater<int>> a;


void dfs(int u,int fa)
{
    if(c[u].size()==1)
    {
        a.push_back(dep[u]);
    }

    for(auto i: c[u])
    {
        if(i==fa)
            continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
    }
    return ;
}

int main()
{
    #ifdef ONLINE_JUDGE
    #else
    freopen("F://2_1_code//C//in.txt","r",stdin);
    //freopen("F://2_1_code//C//out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        c[x].push_back(y);
        c[y].push_back(x);
    }

    int ans=1;

    for(auto fakeroot:c[1])
    {
        a.clear();
        dep[fakeroot]=1;
        dfs(fakeroot,1);
        sort(a.begin(),a.end(),[](int x,int y)->bool{return x<y;});

        for(int i=1;i<a.size();i++)
        {
            a[i]=max(a[i-1]+1,a[i]);
        }
        if(a.size())
            ans=max(ans,a.back());
    }
    cout<<ans;
    return 0;
}
