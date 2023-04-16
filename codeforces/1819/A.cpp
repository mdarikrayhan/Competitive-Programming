#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,a[o],m,m_,l,r;bool vis[o];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=0;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]<=n) vis[a[i]]=1;
		}
		for(m=0;vis[m];++m);
		if(n==m){printf("No\n");continue;}
		if(!vis[m+1]){printf("Yes\n");continue;}
		for(int i=1;i<=n;++i) if(a[i]==m+1) r=i;
		for(int i=n;i;--i) if(a[i]==m+1) l=i;
		for(int i=l;i<=r;++i) a[i]=m;
		for(int i=0;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i) if(a[i]<=n) vis[a[i]]=1;
		for(m_=0;vis[m_];++m_);
		printf((m_==m+1)?"Yes\n":"No\n");
	}
	return 0;
}
