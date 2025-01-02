// LUOGU_RID: 160015870
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int v[N],t[N],s[N];
int b[N],add[N];
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<=n;i++) cin>>t[i],s[i]=s[i-1]+t[i];
    for (int i=1;i<=n;i++)
    {
        if (v[i]>=s[n]-s[i-1]) b[i]++;
        else
        {
            int l=i,r=n;
            while (l<r)
            {
                int mid=l+r>>1;
                if (s[mid]-s[i-1]>v[i]) r=mid;
                else l=mid+1;
            }
            b[i]++,b[l]--;
            add[l]+=v[i]-(s[l-1]-s[i-1]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];
        cout<<b[i]*t[i]+add[i]<<" ";
    }
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}