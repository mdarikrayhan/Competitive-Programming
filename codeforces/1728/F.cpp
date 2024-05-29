// LUOGU_RID: 159204628
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2001;
int n,q,a[N],g[N];
ll b[N*N];
bool h[N];
vector<int> d[N*N];
bool dfs(int x)
{
    for(auto i:d[x])
    {
        if(h[i]) continue;
        h[i]=true;
        if(g[i]==0||dfs(g[i]))
        {
            g[i]=x;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        for(int j=1;j<=n;++j) b[++q]=(ll)a[i]*j;
    }
    sort(b+1,b+q+1);
    q=unique(b+1,b+q+1)-b-1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x=lower_bound(b+1,b+q+1,(ll)a[i]*j)-b;
            d[x].push_back(i);
        }
    }
    ll s=0;
    for(int i=1;i<=q;++i)
    {
        if(dfs(i))
        {
            s+=b[i];
            for(int j=1;j<=n;++j) h[j]=false;
        }
    }
    printf("%lld",s);
    return 0;
}