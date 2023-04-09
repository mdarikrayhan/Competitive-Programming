#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+5;
typedef long long ll;
ll n,l,r,a[N],p[N],b[N],mmin=INT_MAX,mmax=0;
set<ll> s;
int main(){
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]+p[i];
		mmin=min(mmin,b[i]);
		mmax=max(mmax,b[i]);
	}
	if(mmax-mmin>r-l){
		puts("-1");
	}
	else{
		ll u=l-mmin;
		for(int i=1;i<=n;i++){
			printf("%lld ",b[i]+u);
		}
	}
	return 0;
}
 	 	  	 				 		      		 	 	 	