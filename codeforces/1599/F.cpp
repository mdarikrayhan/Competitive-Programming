// LUOGU_RID: 160483015
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const LL N=200005,p=1000000007;
LL qp(LL x,LL y){LL z=1;for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;return z;}
LL n,m,C[12][12],a[N],b[N][12],c[N][12];
int main(){
	n=rd();m=rd();
	for(LL i=1;i<=n;++i)a[i]=(rd()+1145)%p;c[0][0]=1;
	for(LL i=0;i<=10;++i){
		for(LL j=1;j<=n;++j)b[j][i]=(b[j-1][i]+qp(a[j],i))%p;
		for(LL j=1;j<=n;++j)c[j][i]=(c[j-1][i]+qp(j,i))%p;
	}
	for(LL i=0;i<=10;++i)for(LL j=C[i][0]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	for(LL x,y,z,o;m--;){
		x=rd();y=rd();z=rd();
		o=(b[y][1]-b[x-1][1]-(y-x+1)*(y-x)/2%p*z%p+p+p)%p*qp(y-x+1,p-2)%p;
		LL fl=1;
		for(LL i=2;i<=10;++i){
			LL w=(b[y][i]-b[x-1][i]+p)%p;
			LL d=0;
			for(LL j=0;j<=i;++j)d=(d+C[i][j]*qp(o,i-j)%p*qp(z,j)%p*c[y-x][j])%p;
			if(d!=w){fl=0;break;}
		}
		puts(fl?"Yes":"No");
	}
	return 0;
}