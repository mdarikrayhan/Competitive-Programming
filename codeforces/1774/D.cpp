#include<cstdio>
#include<vector>
using namespace std;
const int o=1e6+10;
int T,n,m,cnt[o],s,ans,x[o],y[o],z[o];vector<int> a[o],v1,v2;
int main(){
	for(scanf("%d",&T);T--;s=ans=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			a[i].resize(m+1);cnt[i]=0;
			for(int j=1;j<=m;++j) scanf("%d",&a[i][j]),cnt[i]+=a[i][j],s+=a[i][j];
		}
		if(s%n){printf("-1\n");continue;}
		s/=n;
		for(int i=1;i<=m;++i){
			v1.clear();v2.clear();
			for(int j=1;j<=n;++j) if(cnt[j]>s&&a[j][i]) v1.push_back(j);
			for(int j=1;j<=n;++j) if(cnt[j]<s&&!a[j][i]) v2.push_back(j);
			for(int j=0,s1=v1.size(),s2=v2.size();j<s1&&j<s2;++j) x[++ans]=v1[j],y[ans]=v2[j],z[ans]=i,--cnt[v1[j]],++cnt[v2[j]];
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;++i) printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}