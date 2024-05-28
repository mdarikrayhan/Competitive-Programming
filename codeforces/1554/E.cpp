// LUOGU_RID: 160224575
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,p=998244353;
int T,n,flag,f[maxn];
vector<int> e[maxn];
int dfs(int now,int fa,int myf)
{
    int tot=0;
    for(int i:e[now])
    {
        if(i!=fa) tot+=dfs(i,now,myf);
        if(!flag) return 0;
    }
    if(tot%myf==0) return 1;
    else if((tot+1)%myf==0)
    {
        if(now==1) flag=0;
        return 0;
    }
    return flag=0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) f[i]=0,e[i].clear();
        f[1]=1;
        for(int i=1;i<n;i++)
        {
            f[1]=(f[1]<<1)%p;
            int x,y;
            scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
        }
        for(int i=n-1;i>1;i--)
        {
            if((n-1)%i==0)
            {
                flag=1,dfs(1,0,i),f[i]=flag;
                for(int j=(i<<1);j<=n;j+=i) f[i]-=f[j];
                f[1]-=f[i];
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
        printf("\n");
    }
    return 0;
}