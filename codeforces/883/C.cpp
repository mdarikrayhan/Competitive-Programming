#include<bits/stdc++.h>
using namespace std;
long long f,t,t0,a1,t1,p1,a2,t2,p2,ans=(1LL<<60);
int main(){
	cin>>f>>t>>t0>>a1>>t1>>p1>>a2>>t2>>p2;
	for(int i=0;t1*i<=t;++i){
		long long lef=f-i,ret=(i+a1-1)/a1*p1;
		if(t0<t2){
			if(lef*t0+t1*i<=t)ans=min(ans,ret);
			continue;
		}
		int lb=-1,ub=(t-t1*i)/t2;
		while(ub>lb+1){
			long long mid=(lb+ub)>>1;
			if(t1*i+t2*mid+max(0LL,(f-i-mid))*t0<=t) ub=mid;
			else lb=mid;
		}
		if(t1*i+t2*ub+max(0LL,(f-i-ub))*t0>t) continue;
		ret+=(ub+a2-1)/a2*p2;
		if(i%a1==0||ub%a2==0) ans=min(ans,ret);
	}
	if(ans>=(1LL<<60)) puts("-1");
	else cout<<ans;
	return 0;
}