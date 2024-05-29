// LUOGU_RID: 160369409
#include<bits/stdc++.h>
using namespace std;
#define SIZE 1<<18
char ibuf[SIZE],*is=ibuf,*it=ibuf;
#define getchar() (is==it&&(it=(is=ibuf)+fread(ibuf,1,SIZE,stdin),is==it)?EOF:*is++)
template<typename Type>
inline void read(Type &a){
	Type x=0;int y=0,ch=getchar();
	while(!isdigit(ch)&&(ch^EOF))y|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	a=y?-x:x;
}
char obuf[SIZE],*op=obuf;
inline void putch(const char &c){
	if(op-obuf==SIZE)fwrite(obuf,1,op-obuf,stdout),op=obuf;
	*op++=c;
}
template<typename Type>
inline void write(Type x){
	if(x<0)putch('-'),x=-x;
	static int s[35],top;top=0;
	do s[top++]=x%10,x/=10;
	while(x);
	while(top)putch(s[--top]+'0');
	putch('\n');
}
#define int long long
#define N 200010
int a[N],s[N],n,q,tree[N<<2],tag[N<<2];
#define mid ((l+r)>>1)
#define pushup(num) tree[num]=max(tree[num<<1],tree[num<<1|1])
inline void build(int l,int r,int num){
	if(l==r)return(void)(tree[num]=a[l]-s[l-1]);
	build(l,mid,num<<1);
	build(mid+1,r,num<<1|1);
	pushup(num);
}
inline void maketag(int l,int r,int num,int k){
	tree[num]+=k;
	tag[num]+=k;
}
inline void pushdown(int l,int r,int num){
	if(tag[num]){
		maketag(l,mid,num<<1,tag[num]),
		maketag(mid+1,r,num<<1|1,tag[num]),
		tag[num]=0;
	}
}
inline void add(int wl,int wr,int l,int r,int num,int k){
	if(wl<=l&&r<=wr)return maketag(l,r,num,k);
	pushdown(l,r,num);
	if(wl<=mid)add(wl,wr,l,mid,num<<1,k);
	if(wr>mid)add(wl,wr,mid+1,r,num<<1|1,k);
	pushup(num);
}
int pos;
inline void query(int l,int r,int num){
	if(~pos)return;
	if(l==r){
		if(!tree[num])pos=l;
		return;
	}
	pushdown(l,r,num);
	if(tree[num<<1]>=0)query(l,mid,num<<1);
	if(tree[num<<1|1]>=0)query(mid+1,r,num<<1|1);
}
signed main(){
	read(n);read(q);
	for(int i=1;i<=n;++i)read(a[i]),s[i]=s[i-1]+a[i];
	build(1,n,1);
	for(int i=1,x,y;i<=q;++i){
		read(x);read(y);
		int dlt=y-a[x];
		a[x]=y;
		add(x,x,1,n,1,dlt);
		if(x<n)add(x+1,n,1,n,1,-dlt);
		pos=-1;
		query(1,n,1);
		write(pos);
	}
	fwrite(obuf,1,op-obuf,stdout);
	return 0;
}