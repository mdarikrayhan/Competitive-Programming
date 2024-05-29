#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXB=2600;
const ull fac[8]={0,3,5,17,257,641,65537,6700417}; 
int tot=7,flag;
map<ull,int> Map;
ull nim[256][256];
ull mul(ull x,ull y,int len=(1<<5)) {
    if (!x || !y) return 0;
    if (x==1 || y==1) return x*y;
    if (len<=4 && nim[x][y]) return nim[x][y];
    ull Xa=x>>len,Xb=x^(Xa<<len),Ya=y>>len,Yb=y^(Ya<<len);
    ull a=mul(Xb,Yb,len>>1),b=mul(Xa^Xb,Ya^Yb,len>>1);
	ull c=mul(Xa,Ya,len>>1),d=mul(c,1ull<<len-1,len>>1);
    ull ans=((a^b)<<len)^a^d;
    if (len<=4) nim[x][y]=ans;
    return ans;
}
ull Pow(ull x,ull y) {
	ull res=1;
	while (y) {
		if (y&1) res=mul(res,x);
		x=mul(x,x),y>>=1;
	}
	return res;
}
ull Ord(ull x) {
	ull res=(ull)-1;
	for (int i=tot; i>=1; i--) if (Pow(x,res/fac[i])==1) res/=fac[i];
	return res;
}
int BSGS(ull a,ull b,int lim,ull ord) {
	Map.clear();
	int B=ceil(sqrt(lim));
	ull P=1;
	for (int i=0; i<B; i++) {
		if (Map.find(P)==Map.end()) Map[P]=i;
		P=mul(P,a);
	}
	P=1; ull w=Pow(a,ord-B%ord);
	for (int i=0; i<B; i++) {
		ull t=mul(P,b);
		if (Map.find(t)!=Map.end()) return Map[t]+i*B;
		P=mul(P,w);
	}
	return -1;
}
ull Solve(int Y,ull a,ull b,ull n) {
	if (a==b) return n==1?0:1;
	if (Y>tot) return flag=0,0;
	if (n%fac[Y]) return Solve(Y+1,a,b,n);
	ull p=n/fac[Y],q=fac[Y];
	int val=BSGS(Pow(a,p),Pow(b,p),q,n);
	if (val==-1) return flag=0,0;
	return q*Solve(Y+1,Pow(a,q),mul(b,Pow(a,n-val)),p)+val;
}
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		ull a,b; scanf("%llu%llu",&a,&b);
		if (a==b) { puts("1"); continue;  }
		flag=1; ull ans=Solve(1,a,b,Ord(a));
		if (flag) printf("%llu\n",ans);
		else puts("-1");
	}
	return 0;
}