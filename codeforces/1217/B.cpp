// LUOGU_RID: 159210742
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define endl '\n'
#pragma GCC optimize(2)
using namespace std;
const int N=110;
int a[N],b[N];
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    int mx0=0,mx1=0;
    for(int i=1;i<=n;i++) 
    {
        mx0=max(mx0,a[i]);
        mx1=max(mx1,a[i]-b[i]);
    }
    if(mx0>=m)
    {
        cout << 1 << endl;
        return;
    }
    if(mx1<=0)
    {
        cout << -1 << endl;
        return;
    }
    cout << (m-mx0+mx1-1)/mx1+1 << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}