// LUOGU_RID: 158978043
#include <iostream>
using namespace std;

const int N=3e5+5;
typedef long long ll;
int n,k; ll f[N],g[N],x[N],y[N];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	for(int i=1;i<=n;i++) scanf("%d",y+i);
	for(int i=1;i<=n;i++){
		f[i]=max(0ll,f[i-1]+x[i]-k*y[i]),g[i]=max(0ll,g[i-1]+y[i]-k*x[i]);
		if(f[i]>k||g[i]>k) return puts("NO"),0;
	} return puts("YES"),0;
}