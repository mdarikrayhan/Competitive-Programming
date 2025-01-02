// LUOGU_RID: 158534480
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int n,q;
const int N=2e5+10;
const ll INF=0x3f3f3f3f;
char ch[N];

struct mat{
	ll a[5][5];
	inline void init(){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i==j) a[i][j]=0;
				else a[i][j]=INF;
			}
		}
	}
	inline ll* operator[] (const int &x){ return a[x]; }
	inline mat operator* (mat &b) const{
		static mat c;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				c[i][j]=INF;
				for(int k=0;k<5;k++){
					c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
				}
			}
		}
		return c;
	}
} lvl[N];

struct NODE{
	int l,r;
	mat mt;
} tr[N<<2];

inline void pushup(NODE &root,NODE &zuo,NODE &you){
	root.mt=zuo.mt*you.mt;
}
inline void pushup(int u){
	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
	tr[u]=(NODE){l,r};
	if(l==r){
		tr[u].mt=lvl[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

mat query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r) return tr[u].mt;
	int mid=(tr[u].l+tr[u].r)>>1;
	mat ans;
	if(r<=mid) ans=query(u<<1,l,r);
	else if(l>mid) ans=query(u<<1|1,l,r);
	else{
		mat zuo=query(u<<1,l,r);
		mat you=query(u<<1|1,l,r);
		ans=zuo*you;
	}
	return ans;
}

int main(){
	scanf("%d%d%s",&n,&q,ch+1);
	for(int i=1;i<=n;i++){
		lvl[i].init();
		if(ch[i]=='2'){
			lvl[i][0][0]=1;
			lvl[i][0][1]=0;
		}
		else if(ch[i]=='0'){
			lvl[i][1][1]=1;
			lvl[i][1][2]=0;
		}
		else if(ch[i]=='1'){
			lvl[i][2][2]=1;
			lvl[i][2][3]=0;
		}
		else if(ch[i]=='6'){
			lvl[i][3][3]=1;
			lvl[i][4][4]=1;
		}
		else if(ch[i]=='7'){
			lvl[i][3][3]=1;
			lvl[i][3][4]=0;
		}
	}
	build(1,1,n);
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		mat ans=query(1,l,r);
		if(ans[0][4]>=INF) printf("-1\n");
		else printf("%d\n",ans[0][4]);
	}
	return 0;
}