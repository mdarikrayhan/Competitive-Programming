// LUOGU_RID: 160195856
#include<bits/stdc++.h>
#define ll long long
#define pc putchar
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
int pstk[40];
inline void write(int x){
	if(!x)return putchar('0'),void();
	if(x<0)putchar('-'),x=-x;
	int len=0;for(;x;x/=10)pstk[++len]=x%10;
	while(len)putchar(pstk[len--]+'0');
}
const int Maxn=2e5+5;
int n,a[Maxn];
struct Tree{int data,mn;}t[Maxn<<2];
int V[Maxn];
void build(int x,int l,int r){
	if(l==r)return void(t[x]={0,0});
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
void change(int x,int l,int r,int d,int p){
	if(l==r){t[x].data+=p;t[x].mn+=p;return;}
	int mid=l+r>>1;
	if(mid>=d)change(x<<1,l,mid,d,p);
	else change(x<<1|1,mid+1,r,d,p);
	t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn);
	t[x].data=t[x<<1].data+t[x<<1|1].data;
}
int cnt[Maxn];
int ok;
void dfs(int x,int l,int r,int R,ll&d,ll&z){
	if(!R)return;
	if(ok)return;
	if(t[x].mn-1>=d&&r<=R){
		z+=1ll*t[x].data-1ll*(d+1)*(r-l+1);
		return;
	}
	if(l==r){d+=1ll-1ll*(t[x].data-d);if(d>n)ok=1;return;}
	int mid=l+r>>1;
	if(mid<R)dfs(x<<1|1,mid+1,r,R,d,z);dfs(x<<1,l,mid,R,d,z);
}
inline bool check(int x){
	ll d=0,z=0;
	ok=0;dfs(1,1,n,x-1,d,z);
	if(z+cnt[0]-d>=1){
		cnt[0]-=V[x];cnt[x]=V[x];
		change(1,1,n,x,V[x]);
		return true;
	}
	return false;
}
inline void solve(){
	n=read();
	int ans=1;build(1,1,n);
	for(int i=0;i<=n+1;i++)V[i]=cnt[i]=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		V[a[i]]++;
		if(a[i]>=ans||!a[i])cnt[0]++;
		else change(1,1,n,a[i],1),cnt[a[i]]++;
		if(i==1)write(max(1,a[i])),pc(' ');
		else{
			while(check(ans))ans++;
			write(ans-1);pc(' ');
		}
	}
	pc('\n');
}
int main(){
	int T=read();
	while(T--)solve();
	return 0;
}
/*
1
6
4 3 0 0 0 0
*/