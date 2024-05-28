// LUOGU_RID: 159194095
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
pair<int,int> a[maxn];
int pre[maxn];
signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n,i,num,ans=4e18,now=0,sum=0;
    int l1,r1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    cin>>num;
    sort(a+1,a+1+n);
    for(i=1;i<=num;i++)
    {
        now+=a[i].first*(i-1)-sum;
        sum+=a[i].first;
    }
    for(i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i].first;
    }
    ans=now;
    l1=1;
    r1=num;
    int l=1,r=num;
    while(r<n)
    {
        now+=(num-1)*(a[r+1].first+a[l].first)-2*(pre[r]-pre[l]);
        //cout<<now<<endl;
        if(now<ans)
        {
            ans=now;
            l1=l+1;
            r1=r+1;
        }
        l++;
        r++;
    }
    for(i=l1;i<=r1;i++)
    {
        cout<<a[i].second<<' ';
    }
    cout<<endl;
    return 0;
}
