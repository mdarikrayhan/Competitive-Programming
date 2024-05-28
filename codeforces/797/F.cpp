// LUOGU_RID: 159647249
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5005;
LL f[N][N],cnt[N],sum[N];
array<int,2>p[N];
int a[N];
void solve()
{
    memset(f,0x3f,sizeof f);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>p[i][0]>>p[i][1];
    sort(a+1,a+n+1),sort(p+1,p+m+1);
    for (int i=1;i<=m;i++) cnt[i]=cnt[i-1]+p[i][1];
    f[0][0]=0;
    if (cnt[m]<n)
    {
        cout<<"-1";
        return;
    }
    for (int i=1;i<=m;i++)
    {
        deque<int>q;
        f[i][0]=0;
        q.push_back(0);
        for (int j=1;j<=n&&j<=cnt[i];j++)
        {
           // cout<<q.size()<<'\n';
            f[i][j]=f[i-1][j];
            sum[j]=sum[j-1]+abs(a[j]-p[i][0]);
            while (q.size()&&(j-q.front()>p[i][1]||f[i-1][q.front()]-sum[q.front()]>f[i-1][j]-sum[j]))
                q.pop_front();
            q.push_back(j);
            f[i][j]=min(f[i][j],sum[j]+f[i-1][q.front()]-sum[q.front()]);
        }
    }
    cout<<f[m][n];
        
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while (T--) solve();
    return 0;
}