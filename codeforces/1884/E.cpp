#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5,mod=1e9+7;
int T,n,pos;
long long a[N],b[N],l[N],r[N],Max,cnt,cost,num;
stack<pair<long long,int> >stk;
int main(){
	scanf("%d",&T);
	while(T--){
		Max=num=0,stk=stack<pair<long long,int> >();
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]),Max=max(Max,a[i]);
		for(int i=1;i<=n;++i){
			a[i]=a[i+n]=a[i+n+n]=Max-a[i];
			if(a[i]==0)pos=n+i;
		}
		for(int i=1;i<=n+n;++i)b[i]=b[i-1]+max(a[i]-a[i-1],0ll);
		for(int i=1;i<=n;++i){
			int siz=1;
			while(!stk.empty()&&stk.top().first>=a[pos+i]){
				long long x=stk.top().first;
				int y=stk.top().second;
				stk.pop();
				siz+=y,num=(num-(x-a[pos+i])*y%mod+mod)%mod;
			}
			r[i]=(r[i-1]+a[pos+i]+num*2)%mod,num+=a[pos+i];
			stk.push({a[pos+i],siz});
		}
		num=0,stk=stack<pair<long long,int> >();
		for(int i=1;i<=n;++i){
			int siz=1;
			while(!stk.empty()&&stk.top().first>=a[pos-i]){
				long long x=stk.top().first;
				int y=stk.top().second;
				stk.pop();
				siz+=y,num=(num-(x-a[pos-i])*y%mod+mod)%mod;
			}
			l[i]=(l[i-1]+a[pos-i]+num*2)%mod,num+=a[pos-i];
			stk.push({a[pos-i],siz});
		}
		for(int i=1;i<=n;++i){
			int p=((pos-i)%n+n)%n;
			cnt=b[i+n-1]-b[i]+a[i],cost=(l[p]+r[n-p-1])%mod;
			printf("%lld %lld\n",cnt,cost);
		}
	}
	return 0;
}
   	     		   	  		 	 	  			  	