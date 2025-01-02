// LUOGU_RID: 101675856
//starch qwq
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,x,y,f[N][25];
double pi=acos(-1),len[N],a[N],l,r=2e9,ans;
struct seg{
	double l,r;
}s[N];
bool ok(double mid){
	for(int i=1;i<=n;i++){
		double t=acos(mid/len[i]);
		s[i]={a[i]-t,a[i]+t};
		if(s[i].l<0) s[i].l+=2*pi,s[i].r+=2*pi;
		s[i+n]={s[i].l+2*pi,s[i].r+2*pi};
	}
	k=2*n,sort(s+1,s+1+k,[](seg x,seg y){return x.l<y.l;});
	for(int i=k,j=k;i>=1;i--){
		while(j&&s[j].l>s[i].r) j--;
		f[i][0]=j+1;
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i<=k;i++) f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=n;i++){
		int x=i;
		for(int j=20;j>=0;j--) if(m>>j&1) x=f[x][j];
		if(!x||x>=i+n) return 1;
	}
	return 0;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x,&y),a[i]=atan2(y,x),
		len[i]=sqrt(1ll*x*x+1ll*y*y),r=min(r,len[i]);
	while(l+1e-10<r){
		double mid=(l+r)/2;
		if(ok(mid)) ans=l=mid;
		else r=mid;
	}
	printf("%.10lf\n",ans);
	return 0;
}