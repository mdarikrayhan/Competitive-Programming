#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) x*2
#define rs(x) x*2+1
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second 
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1005,mo=1e9+7,inf=1e9+7,bs=19491001;
const double eps=1e-8;
inline void read(int &p){
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	p=x*w;
}
int TT;
struct edge{
	int to,nxt;
}e[N];
int fir[N],np,ans[N],cnt[N];
int n,Q;
int a[N];
struct node{
	int l,k,id;
};
vector<node>qu[N];
vector<int>q[N];
struct seg{
	int t[4*N];
	void pushup(int x){
		t[x]=t[ls(x)]+t[rs(x)]; 
	}
	void modify(int x,int le,int ri,int p,int v){
		if(!p)return;
		if(le==ri){
			t[x]+=v;
			return;
		}
		int mid=(le+ri)>>1;
		if(p<=mid)modify(ls(x),le,mid,p,v);
		else modify(rs(x),mid+1,ri,p,v);
		pushup(x);
	}
	int getp(int x,int le,int ri,int v){
		if(le==ri)return le;
		int mid=(le+ri)>>1;
		if(t[ls(x)]>=v)return getp(ls(x),le,mid,v);
		else return getp(rs(x),mid+1,ri,v-t[ls(x)]); 
	}
	int query(int x,int le,int ri,int ql,int qr,int v){
		assert(v>=0);
		if(ql<=le&&qr>=ri){
			if(t[x]>=v)return -getp(x,le,ri,v);
			else return t[x];
		}
		int mid=(le+ri)>>1;
		int res1=0,res2=0;
		if(ql<=mid)res1=query(ls(x),le,mid,ql,qr,v);
		if(res1<0)return res1;
		if(qr>mid){
			res2=query(rs(x),mid+1,ri,ql,qr,v-res1);
			if(res2<0)return res2;
		}
		return res1+res2;
	}
}T;
void add(int x,int y){
	e[++np]=(edge){y,fir[x]};
	fir[x]=np;
}
void dfs(int x){
	T.modify(1,1,n,cnt[a[x]],-1);
	T.modify(1,1,n,cnt[a[x]]+1,1);
	cnt[a[x]]++;
	q[cnt[a[x]]].push_back(a[x]);
	rep(i,0,(int)qu[x].size()-1){
		int res=T.query(1,1,n,qu[x][i].l,n,qu[x][i].k);
		if(res<0){
			int nnum=-res;
			while(q[nnum].size()&&cnt[q[nnum].back()]!=nnum)
			    q[nnum].pop_back();
			if(q[nnum].size())ans[qu[x][i].id]=q[nnum].back();
			else ans[qu[x][i].id]=-1;
		}
		else ans[qu[x][i].id]=-1;
	}
	for(int i=fir[x];i;i=e[i].nxt){
		int j=e[i].to;
		dfs(j);
	}
	cnt[a[x]]--;
	T.modify(1,1,n,cnt[a[x]],1);
	T.modify(1,1,n,cnt[a[x]]+1,-1);
	q[cnt[a[x]]].push_back(a[x]);
}
void solve(){
	read(n),read(Q),np=0;
	rep(i,0,n)
		fir[i]=cnt[i]=0,qu[i].clear(),q[i].clear();
	rep(i,1,n)
	    read(a[i]);
	rep(i,2,n){
		int x;
		read(x),add(x,i);
	}
	rep(i,1,Q){
		int x,l,k;
		read(x),read(l),read(k);
		qu[x].push_back((node){l,k,i}); 
	}
	dfs(1);
	rep(i,1,Q)
	    printf("%d ",ans[i]);
	puts("");
}
int main(){
//	freopen("check.in","r",stdin);
//	freopen("check.out","w",stdout);
	read(TT);
	while(TT--)
	    solve();
	return 0;
}