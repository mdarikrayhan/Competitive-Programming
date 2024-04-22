#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+10,mod = 1e9+7;
ll s[N];
ll a[N];
ll l[N][2],r[N][2];
int check(int x)
{
     for(int i=30;i>=0;i--)
     {
          if((x>>i)&1) return i;
     }
}
void slove()
{
    ll sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=0;i<=30;i++)
    {
        l[i][1]=l[i][0]=0;
        r[i][1]=r[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=30;j++)
        {
            l[j][0]=1;
            if((s[i]>>j)&1) r[j][1]++;
            else r[j][0]++;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int x=check(a[i]);
        sum+=l[x][1]*r[x][1];
        sum+=l[x][0]*r[x][0];
        for(int j=0;j<=30;j++)
        {
            if((s[i]>>j)&1) r[j][1]--;
            else r[j][0]--;
        }
        for(int j=0;j<=30;j++)
        {
            if((s[i]>>j)&1) l[j][1]++;
            else l[j][0]++;
        }
    }
    cout<<sum<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)
    slove();
    return 0;
}