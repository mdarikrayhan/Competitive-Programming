// LUOGU_RID: 159129170
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=300010,mod=998244353;
int n;
int ask(int x)
{
    if (x==n+1) return mod;
    cout<<"? "<<x<<endl;
    int y;
    cin>>y;
    return y;
}
void solve()
{
    cin>>n;
    int l=1,r=n;
    while (l<r)
    {
        int mid=l+r>>1;
        int x=ask(mid),y=ask(mid+1);
        if (x<y) r=mid;
        else l=mid+1;
    }
    cout<<"! "<<l<<endl;
}   
signed main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}