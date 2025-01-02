// LUOGU_RID: 159704577
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d,e;
	node(int a=0,int b=0,int c=0,int d=0,int e=0):a(a),b(b),c(c),d(d),e(e){}
}a[600001],b[600001];
int n,m,q,ans[600001],k[501][501];
char s[501];
bitset <501> f[501][501],g[501][501];
void calc(int l,int r,int L,int R){
	if(l>r||L>R) return;
	int mid=(l+r)/2,pl=L,pr=R;
	for(int i=l;i<=r;i++) for(int j=1;j<=m;j++) f[i][j].reset(),g[i][j].reset();
	for(int i=m;i>=1;i--) if(k[mid][i]) f[mid][i]=f[mid][i+1],f[mid][i][i]=1;
	for(int i=1;i<=m;i++) if(k[mid][i]) g[mid][i]=g[mid][i-1],g[mid][i][i]=1;
	for(int i=mid-1;i>=l;i--) for(int j=m;j>=1;j--) if(k[i][j]) f[i][j]=f[i+1][j]|f[i][j+1];
	for(int i=mid+1;i<=r;i++) for(int j=1;j<=m;j++) if(k[i][j]) g[i][j]=g[i-1][j]|g[i][j-1];
	for(int i=L;i<=R;i++){
		if(a[i].c<mid) b[pl++]=a[i];
		else if(a[i].a>mid) b[pr--]=a[i];
		else ans[a[i].e]=(f[a[i].a][a[i].b]&g[a[i].c][a[i].d]).any();
	}
	for(int i=L;i<pl;i++) a[i]=b[i];
	for(int i=R;i>pr;i--) a[i]=b[i];
	calc(l,mid-1,L,pl-1);
	calc(mid+1,r,pr+1,R);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) if(s[j]=='.') k[i][j]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++) scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d),a[i].e=i;
	calc(1,n,1,q);
	for(int i=1;i<=q;i++) printf(ans[i]?"Yes\n":"No\n");
	return 0;
}