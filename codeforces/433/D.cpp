#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define sz(x) int( (x).size() )
#define inf int(~0U>>1)
#define INF ll(~0ULL>>1)
#define p(i) (1LL<<((i)-1))
#define w(x,i) ((x)&p(i))
#define rep(i,s,t) for (i=(s); i<=(t); i++)
#define dep(i,t,s) for (i=(t); i>=(s); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<double,double> PDD;
typedef pair<ld,ld> PFF;

typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<ld> VF;

template<class T>
inline void get(T &n) {
	char c = getchar();
	while (c!='-' && (c<'0' || c>'9')) c = getchar();
	n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
	while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
	n *= s;
}

const int maxn = 1010;
int n,m,q,a[maxn][maxn];
int u[maxn][maxn],d[maxn][maxn],l[maxn][maxn],r[maxn][maxn];

int main() {
    int i,j,k,t,tt;
	get(n); get(m); get(q);
	rep(i,1,n) rep(j,1,m) get(a[i][j]);
	rep(i,1,n) rep(j,1,m) {
		u[i][j] = a[i][j] ? u[i-1][j]+1 : 0;
		l[i][j] = a[i][j] ? l[i][j-1]+1 : 0;
	}
	dep(i,n,1) dep(j,m,1) {
		d[i][j] = a[i][j] ? d[i+1][j]+1 : 0;
		r[i][j] = a[i][j] ? r[i][j+1]+1 : 0;
	}
	while (q--) {
		int x,y;
		get(k); get(x); get(y);
		if (k==1) {
			a[x][y] ^= 1;
			rep(i,x,n) u[i][y] = a[i][y] ? u[i-1][y]+1 : 0;
			rep(j,y,m) l[x][j] = a[x][j] ? l[x][j-1]+1 : 0;
			dep(i,x,1) d[i][y] = a[i][y] ? d[i+1][y]+1 : 0;
			dep(j,y,1) r[x][j] = a[x][j] ? r[x][j+1]+1 : 0;
		}
		else {
			t = 0;
			i = j = y;
			dep(k,u[x][y],1) {
				for (; i>1 && u[x][i-1]>=k; i--);
				for (; j<m && u[x][j+1]>=k; j++);
				t = max(t,k*(j-i+1));
			}
			i = j = y;
			dep(k,d[x][y],1) {
				for (; i>1 && d[x][i-1]>=k; i--);
				for (; j<m && d[x][j+1]>=k; j++);
				t = max(t,k*(j-i+1));
			}
			i = j = x;
			dep(k,l[x][y],1) {
				for (; i>1 && l[i-1][y]>=k; i--);
				for (; j<n && l[j+1][y]>=k; j++);
				t = max(t,k*(j-i+1));
			}
			i = j = x;
			dep(k,r[x][y],1) {
				for (; i>1 && r[i-1][y]>=k; i--);
				for (; j<n && r[j+1][y]>=k; j++);
				t = max(t,k*(j-i+1));
			}
			printf("%d\n",t);
		}
	}

    return 0;
}
