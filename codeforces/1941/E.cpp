// LUOGU_RID: 160147034
#include<bits/stdc++.h>
#define int long long
using namespace std;//不用填butbftftvrcdrtdcdtdtrcttrcx
const int N=2e5+5,INF=0x3f3f3f3f3f3f3f3f;
int n,m,num,d,a[N],f[N],s[N<<2],ans[N],T;//utftfvyvy5v4tsc4dtehrurfxq
void change(int k,int l,int r,int x,int v){
	if(l==r&&l==x) {
        s[k]=v;
		return;
	}
	if(x<l||x>r) return;
	int mid=(l+r)/2;
	if(l<=x&&x<=mid)change(k*2,l,mid,x,v);
	if(mid+1<=x&&x<=r)change(k*2+1,mid+1,r,x,v);
	s[k]=min(s[k*2],s[k*2+1]);
}
int ask(int k,int l,int r,int x,int y){
	if(y<l||x>r)return INF;
	if(x<=l&&r<=y)return s[k];
	int mid=(l+r)/2;
	return min(ask(k*2,l,mid,x,y),ask(k*2+1,mid+1,r,x,y));
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>num>>d;
		for(int i=1;i<=n;i++){
			for(int i=1;i<=m;i++)cin>>a[i];
			f[1]=1;
			change(1,1,m,1,1);
			for(int i=2;i<=m;i++){
				f[i]=ask(1,1,m,max(i-d-1,1ll),max(i-1,1ll))+a[i]+1;
				change(1,1,m,i,f[i]);
			}
			ans[i]=f[m];
		}
		for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
		int sum=INF;
		for(int i=1;i+num-1<=n;i++)sum=min(sum,ans[i+num-1]-ans[i-1]);
		cout<<sum<<'\n';	
	}
	return 0;
}