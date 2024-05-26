#include <iostream>

using namespace std;
const int NMAX=2e5+5;
int a[NMAX+5],b[NMAX+5],ap[NMAX+5];
pair<int,int> ma[NMAX+5];
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        ma[a[i]].first=i;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        ma[b[i]].second=i;
    }
    int s1=0,s2=0,s3=0;
    for (int i=1;i<=n;++i)
    {
        if (ap[i]==0)
        {
            int cnt=1,t=i;
            ap[i]=1;
            while (true)
            {
                t=a[ma[t].second];
                if (ap[t]==1) break;
                cnt++;
                ap[t]=1;
            }
            s1+=cnt/2; s3+=cnt/2;
        }
    }
    cout<<1LL*s1*(n+n-s1+1)-1LL*s3*(s3+1)<<'\n';
    for (int i=1;i<=n;++i)
    {
        ap[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t=0;
    cin>>t;
    while (t)
    {
        t--;
        solve();
    }
    return 0;
}
