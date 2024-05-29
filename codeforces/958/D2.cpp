#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod=1e9+7;
const int maxn=30000;
ll M[6][6],a[6];
map<ull,int> Map;
int n,d,col;
int fpow(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod; y>>=1;
	}
	return res;
}
void Gauss(ll *a) {
    for (int i=1; i<=d; i++)
        if (a[i]) {
	        if (!M[i][i]) {
	            ll val=fpow(a[i],mod-2);
	            for (int j=i; j<=d; j++) a[j]=a[j]*val%mod;
	            for (int j=1; j<=d; j++) M[i][j]=a[j];
	            break;
	        } else {
	            ll val=mod-a[i];
	            for (int j=i; j<=d; j++) a[j]=(a[j]+val*M[i][j]%mod)%mod;
	        }
	    }
}
int main() {
//	freopen("2.in","r",stdin);
    int T; scanf("%d%d",&T,&d);
    while(T--) {
        memset(M,0,sizeof(M));
        scanf("%d",&n);
        for (int k=1; k<=n; k++) {
            for (int i=1; i<=d; i++) scanf("%lld",&a[i]),a[i]=(a[i]+mod)%mod;
            Gauss(a);
        }
        for (int i=1; i<=d; i++)
            if (M[i][i])
                for (int j=1; j<i; j++)
                    if (M[j][i]) {
                        ll val=mod-M[j][i];
                        for (int k=1; k<=d; k++) M[j][k]=(M[j][k]+val*M[i][k]%mod)%mod;
                    }
        ull val=0;
        for (int i=1; i<=d; i++) for (int j=1; j<=d; j++) val=val*114514+M[i][j];
        if (!Map[val]) Map[val]=(++col);
        printf("%d ",Map[val]);
    }
    return 0;
}