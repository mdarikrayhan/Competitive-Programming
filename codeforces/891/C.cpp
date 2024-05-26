#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace FreedomKing_qwq{};
using namespace FreedomKing_qwq;
const int xN=4e6+5,N=1e6+5,mN=2e3+5,mmN=40,mod=1e9+7;
namespace FreedomKing_qwq{
#define lowbit(_) (_&-_)
	struct Tree{
		int tree[N];
		inline void add(int x,int k){
			for(int i=1;i<=x;i+=lowbit(i)) tree[i]+=k;
			return;
		}
		inline int query(int x){
			int ans=0;
			for(int i=x;i>1;i-lowbit(i)) ans+=tree[i];
			return ans;
		}
	};
	struct Dset{
		int fa[N];
		inline void init(int x){
			for(int i=1;i<=x;i++) fa[i]=i;
			return;
		}
		inline int find(int x){
			return (fa[x]==x?x:fa[x]=find(fa[x]));
		}
		inline void update(int x,int y){
			x=find(x);y=find(y);
			fa[y]=x;
			return;
		}
	};
	//#define lc (p<<1)
	//#define rc (p<<1|1)
	inline int qread(){
#define qr qread()
		int x=0,c=getchar(),t=1;
		while(c<'0'||c>'9'){
			t^=(c=='-');
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+c-'0';
			c=getchar();
		}
		return (t?x:-x);
	}	
	inline void qwrite(int x){
#define qw(_) qwrite(_)
#define qws(_) qw(_),putchar(' ')
#define qwe(_) qw(_),putchar('\n')
		if(x<0) x=-x,putchar('-');
		if(x>9) qwrite(x/10);
		putchar(x%10+'0');
		return;
	}
	inline int qpow(int x,int p,int mod){
		x=(p?x:1);
		mod=(mod?mod:LONG_LONG_MAX);
		int t=1;
		while(p>1){
			if(p&1) t=(t*x)%mod;
			x=(x*x)%mod;
			p>>=1;
		}
		return (x*t)%mod;
	}
	inline int gcd(int x,int y){return (x%y==0?y:gcd(y,x%y));}
	inline int lcm(int x,int y){return (x/gcd(x,y)*y);}
	inline int max(int x,int y){return (x>y?x:y);}
	inline int min(int x,int y){return (x<y?x:y);}
	inline int abss(int x){return (x>=0?x:-x);}
}
struct edge{
	int u,v,w,id,fu,fv;
	bool operator <(const edge qwq)const{return w<qwq.w;}
}a[N];
Dset st;
inline bool cmp(edge x,edge y){return x.id<y.id;}
signed main(){
	int n=qr,m=qr;
	st.init(n);
	for(int i=1;i<=m;i++){
		int u=qr,v=qr,w=qr;
		a[i]={u,v,w,i,0,0};
	}
	sort(a+1,a+m+1);
	a[0].w=INT_MAX;
	for(int i=1;i<=m;){
		int j=i;
		do{
			a[j].fu=st.find(a[j].u);
			a[j].fv=st.find(a[j].v);
			j++;
		}while(j<=m&&a[j].w==a[j-1].w);
		while(i<j){
			while(st.find(a[i].u)==st.find(a[i].v)&&i<j) i++;
			if(i<j) st.update(a[i].u,a[i].v);
		}
	}
	sort(a+1,a+m+1,cmp);
	st.init(n);
	int T=qr;
	while(T--){
		int k=qr;
		vector<edge>e;
		for(int i=1;i<=k;i++){
			int x=qr;
			e.push_back({a[x].fu,a[x].fv,a[x].w,0,0});
		}
		sort(e.begin(),e.end());
		bool flag=true;
		for(int i=0,_size=e.size();i<_size&&flag;){
			if(e[i].u==e[i].v){
				flag=false;
				break;
			}
			st.update(e[i].u,e[i].v);
			int j=i+1;
			while(j<_size&&e[j].w==e[i].w){
				if(st.find(e[j].u)==st.find(e[j].v)){
					flag=false;
					break;
				}
				st.update(e[j].u,e[j].v);
				j++;
			}
			while(i<j){
				st.fa[e[i].u]=e[i].u;
				st.fa[e[i].v]=e[i].v;
				i++;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
		 	  	 		 		 		 			 	 		  			