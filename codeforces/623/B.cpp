// LUOGU_RID: 160423331
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
int n,A,B,a[N];

ll d[N];
inline ll calc(int x){
	bool fl=false;
	for(int i=1;i<=n;i++){
		int t=a[i]%x;
		d[i]=!t?0:t==1||t==x-1?B:-1;
		fl|=d[i]==-1;
	}
	if(!fl){
		ll sum=0,mx=0,res=0;
		for(int i=1;i<=n;i++){
			sum+=d[i]-A;res+=d[i];
			if(sum<0)sum=0;mx=max(mx,sum);
		}
		return res-mx;
	}
	int l=1,r=n;while(~d[l])l++;while(~d[r])r--;
	ll res=(r-l+1ll)*A;for(int i=1;i<l;i++)res+=d[i];for(int i=r+1;i<=n;i++)res+=d[i];
	ll s=0,mx=0;
	for(int i=l-1;i;i--)mx=max(mx,s+=d[i]-A);
	res-=mx;s=mx=0;
	for(int i=r+1;i<=n;i++)mx=max(mx,s+=d[i]-A);
	return res-mx;
}
basic_string<int>p;
inline void get(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0){
		p+=i;while(x%i==0)x/=i;
	}if(x>1)p+=x;
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	get(a[1]-1);get(a[1]);get(a[1]+1);
	get(a[n]-1);get(a[n]);get(a[n]+1);
	ll res=1e18;
	for(int x:p)res=min(res,calc(x));
	printf("%lld\n",res);
	return 0;
}