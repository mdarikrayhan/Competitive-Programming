// LUOGU_RID: 160374491
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int n,v,cnt,mx;
int x[200005];
int t[200005];
int f[200005];
int d[200005];
struct node{int a,b,init;}a[200005];

inline void in(int &n){
	n=0;
	char c=getchar();bool ok=c=='-';
	while(c<'0' || c>'9') c=getchar(),ok|=c=='-';
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	n=(ok?-n:n);
	return ;
}

signed main(){
	in(n);
	for(int i=1;i<=n;i++) in(x[i]),in(t[i]);
	in(v);
	for(int i=1;i<=n;i++){
		a[i].a=t[i]*v+x[i];
		a[i].b=t[i]*v-x[i];
		a[i].init=(a[i].a>=0)&&(a[i].b>=0);
	}
	sort(a+1,a+n+1,[](node a,node b){return a.a==b.a?a.b<b.b:a.a<b.a;});
	d[0]=-1e15;
	for(int i=1;i<=n;i++){
		if(a[i].init==0)continue;
		if(a[i].b>=d[cnt])d[++cnt]=a[i].b;
		else{
			int u=upper_bound(d+1,d+cnt+1,a[i].b)-d;
			d[u]=a[i].b;
		}
	}
	printf("%lld ",cnt);
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	cnt=mx=0;
	d[0]=-1e12;
	for(int i=1;i<=n;i++){
		if(a[i].b>=d[cnt])d[++cnt]=a[i].b;
		else{
			int u=upper_bound(d+1,d+cnt+1,a[i].b)-d;
			d[u]=a[i].b;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}