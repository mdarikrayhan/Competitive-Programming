// LUOGU_RID: 158363068
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
const LL N=200005;
LL n,m,a[N],b[N],qz[N];
int main(){
	n=rd();for(LL i=1;i<=n;++i)a[i]=rd();for(LL i=1;i<=n;++i)b[i]=rd();
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	for(LL i=1;i<=n;++i)qz[i]=qz[i-1]+b[i];
	for(LL i=1,j=0;i<=n;++i){
		while(j<n&&b[j+1]<=a[i])++j;
		m+=a[i]*j-qz[j]+(qz[n]-qz[j])-a[i]*(n-j);
	}
	for(LL i=1;i<=n;++i)m-=abs(a[i]-b[i])*(n-1);
	cout<<m;return 0;
}