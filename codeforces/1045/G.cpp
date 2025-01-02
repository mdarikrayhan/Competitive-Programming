// LUOGU_RID: 160088816
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7fffffff
#define eb emplace_back
#define pii pair<int,int>
#define mkpr make_pair
#define fir first
#define sec second
inline int read(){
    char ch=getchar();int x=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();return w==1?x:-x;
}
const int maxn=2e5+5;
int n,k,ans;
struct node{
	int x,d,q;
	int l,r;
}a[maxn];
int t[maxn],tot;
bool cmpd(node a,node b){return a.d>b.d;}
bool cmpq(node a,node b){return a.q<b.q;}
struct Fenwick_Tree{
	int c[maxn];
	int lowbit(int x){return x&(-x);}
	void update(int x,int k){while(x<=n){c[x]+=k;x+=lowbit(x);}}
	int query(int x){int res=0;while(x){res+=c[x];x-=lowbit(x);}return res;}
}tr;
void solve(int l,int r){
	if(l>=r) return;
	int m=(l+r)/2;
	solve(l,m);solve(m+1,r);
	int L=l,R=l-1;
	for(int i=m+1;i<=r;i++){
		while(L<=m&&a[i].q-a[L].q>k) tr.update(a[L].x,-1),++L;
		while(R<m&&a[R+1].q-a[i].q<=k) ++R,tr.update(a[R].x,1);
		ans+=tr.query(a[i].r)-tr.query(a[i].l-1);
	}
	for(int i=L;i<=R;i++) tr.update(a[i].x,-1);
	sort(a+l,a+r+1,cmpq);
}
signed main(){
	cin.tie(0),cout.tie(0);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].d=read(),a[i].q=read();
		t[++tot]=a[i].x;
	}
	sort(t+1,t+tot+1);
	tot=unique(t+1,t+tot+1)-t-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(t+1,t+tot+1,a[i].x-a[i].d)-t;
		a[i].r=upper_bound(t+1,t+tot+1,a[i].x+a[i].d)-t-1;
		a[i].x=lower_bound(t+1,t+tot+1,a[i].x)-t;
	}
	sort(a+1,a+n+1,cmpd);
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}