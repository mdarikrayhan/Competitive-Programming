// LUOGU_RID: 160053132
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const double eps=1e-9; 
int n,m;
double w;
inline void ipt(){
	scanf("%lld%lf%lld",&m,&w,&n);
}
inline void solve(){
	if(m>=n){
		printf("YES\n");
		int op=1;
		double avr=(double)m*w/n,cnt=avr;
		for(int i=1;i<=m;i++){
			if(cnt-w>eps){
				printf("%lld %.6lf ",i,w);
				cnt-=w;	
			}
			else if(cnt-w<-eps){
				printf("%lld %.10lf\n",i,cnt);
				++op;
				printf("%lld %.10lf ",i,w-cnt);
				cnt=avr-(w-cnt);
			}
			else {
				printf("%lld %.10lf\n",i,cnt);
				++op;
				cnt=avr;
			}
		}
	}
	else {
		if(__gcd(n-m,m)!=n-m){
			printf("NO\n");
			return ;
		}
		printf("YES\n");
		int p=m/(n-m);
		double avr=(double)m*w/n;
		for(int i=1;i<=m;i++)printf("%lld %.10lf\n",i,avr);
		for(int i=1;i<=n-m;i++){
			for(int j=(i-1)*p+1;j<=i*p;j++)printf("%lld %.10lf ",j,w-avr);
			printf("\n");
		}
	}
}
signed main(){
	ipt();	
	solve();
	return 0;
} 