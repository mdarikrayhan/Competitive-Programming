// LUOGU_RID: 157392161
#include<bits/stdc++.h>
#define ll long long
#define pir pair<ll,ll>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
const ll maxn=2e6+10;
ll n,m,flg;
struct oper {ll p,r,x,y;} q[maxn];
bool cmp(oper a,oper b) {return a.r<b.r;}
ll xl, xr, yl, yr;
ll sx[maxn], sy[maxn];
int main(){
	scanf("%lld%lld",&n,&m); flg=(n==200000);
	for(ll i=1;i<=n;i++){ ll t,x,y;
		scanf("%lld%lld%lld",&t,&x,&y);
		if((x^y^t)&1){
			puts("NO"); return 0;
		}
		ll tx=(x+y+t)/2, ty=(y-x+t)/2;
		ll p=t/m, r=t%m;
		q[i]=(oper){p,r,tx,ty};
	}
	++n, q[n]=(oper){0,0,0,0};
	++n, q[n]=(oper){-1,m,0,0};
	sort(q+1,q+1+n,cmp);
	xl=yl=-8e18, xr=yr=8e18;
//	if(flg) puts("2");
	for(ll i=2;i<=n;i++){
		ll x=q[i].x-q[i-1].x, y=q[i].y-q[i-1].y, k=q[i].p-q[i-1].p, d=q[i].r-q[i-1].r;
		if(k==0){
			if(x<0||x-d>0||y<0||y-d>0) {puts("NO"); return 0;}
		} else{
			if(k>0){
				xl=max(xl,(ll)(ceil((x-d)*1.0L/k)));
				xr=min(xr,(ll)(floor(x*1.0L/k)));
				yl=max(yl,(ll)(ceil((y-d)*1.0L/k)));
				yr=min(yr,(ll)(floor(y*1.0L/k)));
			} else{ k=-k, x=-x, y=-y;
				xl=max(xl,(ll)(ceil(x*1.0L/k)));
				xr=min(xr,(ll)(floor((x+d)*1.0L/k)));
				yl=max(yl,(ll)(ceil(y*1.0L/k)));
				yr=min(yr,(ll)(floor((y+d)*1.0L/k)));
			}
		}
	}
//	if(flg) printf("3 %lld %lld %lld %lld",xl,xr,yl,yr);
	if(xl>xr||yl>yr) {puts("NO"); return 0;}
	memset(sx,-1,sizeof sx), memset(sy,-1,sizeof sy);
	for(ll i=1;i<=n;i++){
		sx[q[i].r]=q[i].x-q[i].p*xl;
		sy[q[i].r]=q[i].y-q[i].p*yl;
	}
	for(ll i=0;i<m;i++){
		ll j=i+1;
		while(sx[j]==-1) ++j;
		for(ll k=i+1;k<j;k++){
			if(sx[k-1]<sx[j]) sx[k]=sx[k-1]+1;
			else sx[k]=sx[k-1];
			if(sy[k-1]<sy[j]) sy[k]=sy[k-1]+1;
			else sy[k]=sy[k-1];
		} i=j-1;
	}
	for(ll i=1;i<=m;i++){
		ll dx=sx[i]-sx[i-1], dy=sy[i]-sy[i-1];
		if(dx&&dy) putchar('U');
		else if(!dx&&!dy) putchar('D');
		else if(dy) putchar('L');
		else putchar('R');
	}
	return 0;
}