#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,m,d[N],h[N],ans;
bool check(int i) {
	if (abs(d[i]-d[i+1])<abs(h[i]-h[i+1])) return 0;
	ans=max((h[i+1]+h[i]+(d[i+1]-d[i]))/2,ans);
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",d+i,h+i);
	}
	ans=max(d[0]-1+h[0],n-d[m-1]+h[m-1]);
	rep(i,0,m-1) {
		if (!check(i)) {
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	printf("%d\n",ans);
}
