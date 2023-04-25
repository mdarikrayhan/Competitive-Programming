#include<bits/stdc++.h>
using namespace std;
const int N=500500,INF=1e9;
int n,m,a[N],b[N],c;
inline void upd_(int i,int x){i<=m?(c-=!!b[i],b[i]+=x,c+=!!b[i]):0;}
inline void upd(int x,int y){
	for(int i=1;i*i<=x;++i)
		if(x%i==0){
			upd_(i,y);
			if(i*i!=x)
				upd_(x/i,y);
		}
}
void solve(){
	scanf("%d%d",&n,&m),c=0;
	for(int i=1;i<=m;++i)
		b[i]=0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=INF;
	for(int l=1,r=0;l<=n;upd(a[l],-1),++l){
		while(r<n&&c<m)
			++r,upd(a[r],1);
		if(c==m)
			ans=min(ans,a[r]-a[l]);
	}
	printf("%d\n",ans==INF?-1:ans);
}
int main(){
	int T;
	for(scanf("%d",&T);T--;solve());
}