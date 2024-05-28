// LUOGU_RID: 159840559
#include<bits/stdc++.h>
#define int long long
#define up(i,l,r) for(int i=l; i<=r; ++i)
#define dn(i,r,l) for(int i=r; i>=l; --i)

using namespace std;

const int N=2005, P=998244353;

int n, k, b[N], l[N], r[N], f[2][N][N], Ans, A[N][N];

void Add(int &a,int b) { a=(a+b%P)%P; }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	up(i,1,n) cin >> b[i], l[i]=max(l[i-1],b[i]-k), r[i]=min(n,b[i]+k);
	up(i,1,n) if(l[i]>r[i]) { cout << 0; return 0; }
	up(i,0,n) {
		A[i][0]=1;
		up(j,1,i) Add(A[i][j],A[i][j-1]*(i-j+1));
	}
	int now=0, nxt=1; f[now][0][0]=1;
	up(i,1,n) {
		up(j,l[i],r[i]) up(k,0,i-1) {
			Add(f[nxt][j][k+1],f[now][j][k]);
			Add(f[nxt][j][k],f[now][j][k]*(j+k));
		}
		up(j,l[i-1],r[i]) up(k,1,i) Add(f[now][j+1][k-1],f[now][j][k]*k);
		up(j,max(l[i]-1,0ll),r[i]-1) up(k,0,i) Add(f[nxt][j+1][k],f[now][j][k]);
		up(j,max(l[i-1]-1,0ll),max(r[i-1],r[i])+1) up(k,0,i) f[now][j][k]=0;
		swap(now,nxt);
	}
	up(j,l[n],r[n]) up(k,0,n) Add(Ans,f[now][j][k]*A[n-j][k]);
	cout << Ans;
	return 0;
}