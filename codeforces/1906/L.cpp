// LUOGU_RID: 160527108
#include<bits/stdc++.h>
#define il inline
#define ui unsigned int
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long db
#define pii pair<int,int>
#define vi vector<int>
#define fir first
#define sec second
#define gc getchar
#define pc putchar
#define mst(arr,val) memset(arr,val,sizeof arr)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pct __builtin_popcount
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3f;
il int rd() {int x=0,f=1; char ch=gc(); while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=gc();} while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc(); return x*f;}
il ll rdll() {ll x=0; int f=1; char ch=gc(); while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=gc();} while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc(); return x*f;}
il void wr(int x) {if(x<-2147483647) return (void)printf("-2147483648"); if(x<0) {pc('-'),wr(-x); return;} if(x<10) {pc(x+'0'); return;} wr(x/10),pc(x%10+'0');}
il void wrll(ll x) {if(x<-9223372036854775807) return (void)printf("-9223372036854775808"); if(x<0) return pc('-'),wrll(-x); if(x<10) return (void)pc(x+'0'); wrll(x/10),pc(x%10+'0');}
il void wr(int x,char *s) {wr(x),printf("%s",s);}
il void wrll(ll x,char *s) {wrll(x),printf("%s",s);}
int n,m,t,l,r;
void prt(string s,int x) {while(x--) cout<<s;}
void QwQ() {
	n=rd(),m=rd(); if(n==m||m<n>>1) puts("-1"),exit(0);
	t=n-m,l=n-(t<<1)>>2,r=n-(l+t<<1)>>1,prt("()",l),prt("(",t),prt(")",t),prt("()",r);
}
signed main() {
	int T=1; while(T--) QwQ();
}
