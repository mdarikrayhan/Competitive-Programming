#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'
#define x first
#define y second
#define int long long
typedef long long ll;
typedef pair<int,int>PII;
typedef tuple<int, int, int> PI3;

typedef unsigned long long ull;
const int N =3e5+10 , M = 998244353 ;
const ll INF = 0x3f3f3f3f3f3f3f,mod=1e9+7;
const int P=131;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,-1,0,1};
//int dxx[]= {-1,-1,0,1,1,1,0,-1};
//int dyy[]= {0,1,1,1,0,-1,-1,-1};
ll n,m,k;
ll a[N],b[N];
void solve() {
     cin>>n>>k;
     m=n/k;
     for(int i=1;i<=m;i++) cin>>a[i];
     for(int i=1;i<=m;i++) cin>>b[i];
     ll ans=1,ex=1;
     for(int i=1;i<=k;i++)ex*=10;
     for(int i=1;i<=m;i++){
     	if(b[i]==0){
     		ans=((ex-1)/a[i]-(ex/10-1)/a[i])%mod*ans%mod;
		 }else{
		 	ans=((ex-1)/a[i]-(((b[i]+1)*ex/10-1)/a[i]-(b[i]*ex/10-1)/a[i])+1)%mod*ans%mod;
		 }
	 }
	 cout<<ans<<endl;
       
}
signed main() {
	FAST;
	int t=1;
//	cin>>t;
	while (t--) solve();
	return 0;
}