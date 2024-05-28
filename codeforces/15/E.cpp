// LUOGU_RID: 160411545
#include <bits/stdc++.h>
#define open ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)//,freopen("1.in","r",stdin),freopen("1.out","w",stdout)
#define void inline void
#define int register unsigned
#define ll long long
using namespace std;constexpr unsigned N=2e5+1,p=1000000009;
inline unsigned ll pw(int ll a,int ll b){int ll s=1;for(;b;b>>=1,a=a*a%p)b&1?s=s*a%p:0;return s;}
signed main(){open;int ll n,ans=0,cnt=1,now;cin>>n;n>>=1;
	for(int i=2;i<=n;++i)now=(pw(2,i)-3+p)%p,ans=(ans+4ll*now%p*cnt%p)%p,(cnt*=now)%=p;
	cout<<(10ll+8ll*ans%p+2ll*ans%p*ans%p)%p;
}
