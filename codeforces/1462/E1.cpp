#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=300010;
int w[N],s[N];
void init()
{
    for (int i=2;i<N;i++) s[i]=i*(i-1)/2; 
}
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+1+n);
    int ans=0;
    for (int i=3;i<=n;i++)
    {
        if (w[i]-w[i-2]>2) continue;
        int l=1,r=i-2;
        while (l<r)
        {
            int mid=l+r>>1;
            if (w[i]-w[mid]<=2) r=mid;
            else l=mid+1;
        }
        ans+=s[i-l];
    }
    cout<<ans<<"\n";
}   
signed main()
{
    init();
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}