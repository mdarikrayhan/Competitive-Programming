// LUOGU_RID: 159785753
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<random>
using namespace std;
random_device __RD; mt19937 Rand(__RD());
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Rep(i,j,k) for(int i=j;i>=k;i--)
#define ls(c) c<<1
#define rs(c) c<<1|1
#define int long long
#define lowbit(x) ((x)&(-x))
template<typename type>
inline void read(type &x){
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag^=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
template<typename type>
inline void write(type x){
    x<0?x=-x,putchar('-'):0;
    static short Stack[50],top(0);
    do Stack[++top]=x%10,x/=10;while(x);
    while(top) putchar(Stack[top--]|48);
}
inline char read(char &ch){return ch=getchar();}
inline char write(const char &ch){return putchar(ch);}
template<typename type,typename ...T>
inline void read(type &x,T&...y){read(x),read(y...);}
template<typename type,typename ...T>
inline void write(type x,T...y){write(x),putchar(' '),write(y...),sizeof...(y)^1?0:putchar('\n');}
const int N=2e5+5,Mod=1e9+7;
int n,m,a[N],f[N];
struct node{
	int l,r,v;
}q[N];
vector<pair<int,int> > v[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
struct seg{
	int l,r,Max,add;
}t[N<<2];
inline void push_up(int c){
	t[c].Max=max(t[ls(c)].Max,t[rs(c)].Max); 
}
inline void push_down(int c){
	if(t[c].add){
		t[ls(c)].add+=t[c].add;
		t[rs(c)].add+=t[c].add;
		t[ls(c)].Max+=t[c].add;
		t[rs(c)].Max+=t[c].add;
		t[c].add=0;
		return;
	}
}
inline void build(int c,int l,int r){
	t[c].l=l;t[c].r=r;t[c].Max=0;t[c].add=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(ls(c),l,mid);
	build(rs(c),mid+1,r);
	push_up(c);return;
}
inline void update(int c,int l,int r,int k){
	if(l<=t[c].l&&r>=t[c].r){
		t[c].Max+=k;t[c].add+=k;
		return;
	}push_down(c);int mid=(t[c].l+t[c].r)>>1;
	if(l<=mid) update(ls(c),l,r,k);
	if(r>mid) update(rs(c),l,r,k);
	push_up(c);return;
}
int query(int c,int l,int r){
	if(l<=t[c].l&&r>=t[c].r) return t[c].Max;
	push_down(c);int mid=(t[c].l+t[c].r)>>1,res=0;
	if(l<=mid) res=max(res,query(ls(c),l,r));
	if(r>mid) res=max(res,query(rs(c),l,r));
	return res;
}inline void change(int c,int l,int r,int k){
	if(l<=t[c].l&&r>=t[c].r){
		t[c].Max=k;t[c].add=0;
		return;
	}push_down(c);int mid=(t[c].l+t[c].r)>>1;
	if(l<=mid) change(ls(c),l,r,k);
	if(r>mid) change(rs(c),l,r,k);
	push_up(c);return;
}
signed main(){
	read(n,m);
	For(i,1,n) read(a[i]);
	For(i,1,m) read(q[i].l,q[i].r,q[i].v),v[q[i].r].push_back(make_pair(q[i].l,q[i].v));
	sort(q+1,q+m+1,cmp);build(1,0,n);
	For(i,1,n){
		update(1,0,i-1,-a[i]);
		for(auto j:v[i]){
			update(1,0,j.first-1,j.second);
		}
		f[i]=max(f[i-1],query(1,0,i-1));
		change(1,i,i,f[i]);
//		cout<<f[i]<<' ';
	}//cout<<endl;
	write(f[n]);
	return 0;
}
