#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int mod=1e9+7,N=100105;
#define x first
#define y second
int p[N],q[N],nxt[N];
char s[N];
int fpow(int x,int y,int mod) {
	int res=1;
	while (y) { if (y&1) res=1ll*res*x%mod; x=1ll*x*x%mod,y>>=1; } 
	return res;
}
int inv(int a) { return a<=1?a:(int)(mod-(ll)mod/a*inv(mod%a)%mod); }
pii operator + (const pii &a,const pii &b) {
	int x=((ll)a.x*fpow(10,b.y,mod)%mod+b.x)%mod,y=(a.y+b.y)%(mod-1);
	return mp(x,y);
}
pii calc2(int a,int b,int alen,int blen,int n) {
	int A=p[n],INV=inv(A-1);
	int B=fpow(A,(mod+blen-alen)%(mod-1),mod);
	int Ans=1ll*INV*INV%mod*(B-A)%mod;
	Ans=(Ans+1ll*B*a%mod*INV)%mod;
	Ans=((Ans-1ll*b*INV)%mod+mod)%mod;
	B=1ll*(blen-alen+1)*n%(mod-1)+mod-1;
	return mp(Ans,B%(mod-1));
}
pii calc(int S,int E) {
	for (int i=S; i<E; i++) {
		if (s[i]=='(') {i=nxt[i];continue;}
		if (s[i]=='+') return calc(S,i)+calc(i+1,E);
	}
	if (s[E-1]==')') {
		int mid=0,val=0;
		for (int i=S; i<E; i++) {
			if (s[i]=='(') {
				pii a=calc(i+1,E-1); int b=fpow(10,a.y,mod),ansx;
				if (b==1) ansx=1ll*a.x*val%mod;
				else {
					int c=1ll*(fpow(b,mid,mod)-1)*inv(b-1)%mod;
					ansx=1ll*a.x*c%mod;
				}
				int ansy=1ll*mid*a.y%(mod-1);
				return pii((mod+ansx)%mod,ansy);
			}
			mid=(mid*10ll+s[i]-'0')%(mod-1);
			val=(val*10ll+s[i]-'0')%mod;
		}
	}
	int Ans=0,Anslen=0;
	for (int i=S; i<E; i++) {
		if (s[i]=='-') {
			int L=i-S,LL=E-i-1,b=0,blen=0;
			for (i++; i<E; i++) {
				b=(b*10ll+s[i]-'0')%mod;
				blen=(blen*10ll+s[i]-'0')%(mod-1);
			}
			if (L==LL) return calc2(Ans,b,Anslen,blen,L);
			pii res=calc2(Ans,(mod-1+p[L])%mod,Anslen,(mod-2+q[L])%(mod-1),L);
			for (i=L+1; i<LL; i++)
				res=res+calc2(p[i-1],(p[i]+mod-1)%mod,q[i-1],(q[i]+mod-2)%(mod-1),i);
			res=res+calc2(p[LL-1],b,q[LL-1],blen,LL);
			return res;
		}
		Ans=(Ans*10ll+s[i]-'0')%mod;
		Anslen=(Anslen*10ll+s[i]-'0')%(mod-1);
	}
	return mp(Ans,E-S);
}
int main() {
	scanf("%s",s);
	int n=strlen(s);
	for (int i=p[0]=1; i<N; i++) p[i]=p[i-1]*10ll%mod;
	for (int i=q[0]=1; i<N; i++) q[i]=q[i-1]*10ll%(mod-1);
	stack<int> sta;
	for (int i=0; i<n; i++) {
		if (s[i]=='(') sta.push(i);
		if (s[i]==')') nxt[sta.top()]=i,sta.pop();
	}
	printf("%d\n",calc(0,n).x);
	return 0;
}