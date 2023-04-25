#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>>num[200010];
int siz[200010];
int dfs(int x,int &k){
    siz[x]=1;
    for(auto [i,v]:num[x])if(!siz[i]&&k>=v)
    siz[x]+=dfs(i,k);
    return siz[x];
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)num[i].clear();
        for(int i=1;i<=m;i++){
            int x,y,v;scanf("%d%d%d",&x,&y,&v);
            num[x].push_back({y,0});
            num[y].push_back({x,v});
        }
        int l=0,r=1e9+10;
        while(l<r){
            int mid=l+r>>1,res;
            for(int i=1;i<=n;i++)siz[i]=0;
            for(int i=1;i<=n;i++)if(!siz[i])dfs(i,mid),res=i;
            for(int i=1;i<=n;i++)siz[i]=0;res=dfs(res,mid);
            if(res==n)r=mid;
            else l=mid+1;
        }
        if(l>1e9)l=-1;
        printf("%d\n",l);
    }
}