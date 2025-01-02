#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e3+10,M=1e6+10;
int n,k;
int a[N];
// vector<pii>tmp[M];
pii tmp[M][6];
int len[M];
void Add(int p,int x,int y){
    if(len[p]>k)return;
    for(int i=0;i<len[p];i++)
        if(tmp[p][i].fi==x){
            tmp[p][i].se+=y;
            return;
        }
    tmp[p][len[p]++]={x,y};
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    // n=5000,k=1;
    // for(int i=1;i<=n;i++)a[i]=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        Add(a[j]-a[i],a[i]%(a[j]-a[i]),1);
    int ans;
    for(int i=1;i<M;i++)
    {
        bool flag=0;
        for(int j=2*i;j<M;j+=i)
            if(len[j]>k||len[i]>k)flag=1;
            else for(int k=0;k<len[j];k++)Add(i,tmp[j][k].fi%i,tmp[j][k].se);
        if(!flag)
        {
            int tot=0;
            for(int j=0;j<len[i];j++)
            {
                tot+=(-1+sqrt(1+8*tmp[i][j].se))/2;
                if(tot>k)break;
            }
            if(tot<=k){
                ans=i;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}