// LUOGU_RID: 160205871
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,K=30;
int f[N][K],n,k,a[N],cnt[N],temp;
int l=1,r=0;
void add(int x){
	x=a[x];
	if(cnt[x]) temp-=cnt[x]*(cnt[x]-1)/2ll;
	cnt[x]++;
	temp+=cnt[x]*(cnt[x]-1ll)/2ll;
}
void del(int x){
	x=a[x];
	if(cnt[x]) temp-=cnt[x]*(cnt[x]-1)/2ll;
//	cout<<temp<<" ";
	cnt[x]--;
	//cout<<temp<<endl;
	if(cnt[x]) temp+=cnt[x]*(cnt[x]-1)/2ll;
}
int query(int x,int y){
	while(l>x) add(--l);
	while(r<y) add(++r);
	while(l<x) del(l++);
	while(r>y) del(r--);
	return temp;
}
void dp(int l,int r,int nl,int nr,int k){
//	cout<<l<<" "<<r<<endl;
	if(l>r) return;
	int mid=l+r >>1;
	int kd=nl;
	for(int i=nl;i<=min(mid,nr);i++) {
	//	cout<<i<<" "<<mid<<" "<<query(i,mid)<<endl;
		if(f[i-1][k-1]+query(i,mid)<f[mid][k]){
			f[mid][k]=f[i-1][k-1]+query(i,mid);
			kd=i;
		}
	}
	dp(l,mid-1,nl,kd,k);
	dp(mid+1,r,kd,nr,k);
}
signed main(){
	cin>>n>>k;
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=k;i++) {
		dp(1,n,1,n,i);
	}
	cout<<f[n][k];
	return 0;
}