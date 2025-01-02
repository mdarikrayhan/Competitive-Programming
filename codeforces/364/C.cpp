// LUOGU_RID: 160080384
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,up,now=1;
int p[]={1,2,3,5,7,11,13};
vector<int>ans;
void dfs(int x,int d)
{
    if(d==now){
        ans.push_back(x);
        return;
    }
    dfs(x,d+1);
    for(;x*p[d+1]<=up;x*=p[d+1])
        dfs(x*p[d+1],d+1);
}
int cnt[10];
bool check()
{
    ans.clear();
    dfs(1,0);
    memset(cnt,0,sizeof cnt);
    if(ans.size()<n)return 0;
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=now;j++)
            if(ans[i]%p[j]==0)cnt[j]++;
    }
    for(int j=1;j<=now;j++)
        if(cnt[j]*2<n)return 0;
    for(int i=n-1;i>=0;i--)printf("%d ",ans[i]);
    return 1;
}
int main()
{
    scanf("%d",&n);up=2*n*n;
    while(!check())now++;
    return 0;
}