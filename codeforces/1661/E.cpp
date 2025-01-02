#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,bb[500005],dx[]={0,1,1,1,1,2,1,1},l,r;
char a[4][500005];
struct tree{
	int l,r,cnt,maxl,maxr;
	friend tree operator+(const tree&a,const tree&b){
		tree c;
		if(a.l==-1&&a.r==-1)return b;
		c.l=a.l,c.r=b.r;
		if(a.maxl==a.r-a.l+1)c.maxl=a.maxl+b.maxl;
		else c.maxl=a.maxl;
		if(b.maxr==b.r-b.l+1)c.maxr=a.maxr+b.maxr;
		else c.maxr=b.maxr;
		c.cnt=a.cnt+b.cnt;
		int now=0;
		for(int i=1;i<=3;i++)if((bb[a.r]&(1<<(i-1)))&&(bb[b.l]&(1<<(i-1))))now++;
		if(now==0)return c;
		if(bb[a.r]==5&&bb[b.l]==7){
			int nw=(!(a.maxr==a.r-a.l+1))&&(bb[a.r-a.maxr]==7);
			if(nw)c.cnt--;
			else c.cnt-=2;
			return c;
		}
		if(bb[a.r]==7&&bb[b.l]==5){
			int nw=(!(b.maxl==b.r-b.l+1))&&(bb[b.l+b.maxl]==7);
			if(nw)c.cnt--;
			else c.cnt-=2;
			return c;
		}
		if(bb[a.r]==5&&bb[b.l]==5){
			int nw1=(!(a.maxr==a.r-a.l+1))&&(bb[a.r-a.maxr]==7),nw2=(!(b.maxl==b.r-b.l+1))&&(bb[b.l+b.maxl]==7);
			if(nw1&&nw2)c.cnt--;
			else c.cnt-=2;
			return c;
		}
		c.cnt--;return c;
	}
	friend void operator+=(tree&a,const tree&b){
		a=a+b;
	}
}tr[2000005];
void build(int u,int l,int r){
	if(l==r){
		tr[u]={l,r,dx[bb[l]],bb[l]==5,bb[l]==5};
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
tree query(int u,int l,int r){
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
	int mid=tr[u].l+tr[u].r>>1;
	tree ans;ans.l=ans.r=-1;
	if(l<=mid)ans+=query(u<<1,l,r);
	if(r>mid)ans+=query(u<<1|1,l,r);
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n;
	for(int i=1;i<=3;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)bb[i]=(a[1][i]-'0')*4+(a[2][i]-'0')*2+a[3][i]-'0';
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>l>>r;
		tree ans=query(1,l,r);
		cout<<ans.cnt<<"\n";
	}
}
