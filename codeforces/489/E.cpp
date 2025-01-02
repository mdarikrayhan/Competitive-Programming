// LUOGU_RID: 160306024
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
ll x[N],b[N],p[N],a[N],st[N],n,l,c;
double dis[N];
bool check(double y){
	for(ll i=1;i<=n;i++) dis[i]=1e18;//no
	for(ll i=0;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			double tp=dis[i]+sqrt(abs(x[i]+l-x[j]))-y*b[j];//+,no di
			if(tp<dis[j]) dis[j]=tp,p[j]=i;
		}
	}
	return dis[n]<=0;
}
int main(){
	scanf("%lld%lld",&n,&l);
	for(ll i=1;i<=n;i++){
	scanf("%lld%lld",&x[i],&b[i]); }
	double l=0,r=1e3;
	while(r-l>=1e-12){
		double mid=(l+r)/2;//ll
		if(check(mid)){
			for(ll i=1;i<=n;i++) a[i]=p[i];
			r=mid;
		}else l=mid;
	}
	for(ll i=n;i;i=p[i]) st[++c]=i;
	for(ll i=c;i;i--) printf("%lld ",st[i]);
	return 0;
}