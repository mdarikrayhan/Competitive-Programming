// LUOGU_RID: 160516241
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define endl '\n'
#pragma GCC optimize(2)
using namespace std;

const int N=200010;
int l[N],r[N],res[N];
std::vector<int> v;
int f(int x){return lower_bound(v.begin(),v.end(),x)-v.begin();}
int n;

void calc()
{
    v.clear();
    for(int i=1;i<=n;i++)
    {
        v.push_back(l[i]);
        v.push_back(r[i]+1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int len=v.size();
    std::vector<int> in[len+7],out[len+7];
    for(int i=1;i<=n;i++)
    {
        in[f(l[i])].push_back(i);
        out[f(r[i]+1)].push_back(i);
    }
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        cnt+=(int)out[i].size();
        for(auto t:in[i]) res[t]+=cnt;
    }

}

void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++) res[i]=0;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        cin >> l[i] >> r[i];
        mx=max(mx,r[i]);
    }
    calc();
    for(int i=1;i<=n;i++)
    {
        l[i]=mx-l[i];
        r[i]=mx-r[i];
        swap(l[i],r[i]);
        // cout << i << ' ' << l[i] << ' ' << r[i] << endl;
    }
    calc();
    // for(int i=1;i<=n;i++) cout << i << ' ' << res[i] << endl;
    int ans=1e18;
    for(int i=1;i<=n;i++) ans=min(ans,res[i]);
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}