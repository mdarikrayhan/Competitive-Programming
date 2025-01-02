#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,m,a[200100],A[200100],id,x;
map<int,int>mp;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mp[a[i]]=i,A[i]=a[i];
	sort(a+1,a+n+1);
	while(m--){
		scanf("%d%d",&id,&x);
		id=lower_bound(a+1,a+n+1,A[id])-a;
		while(1){
			int r=upper_bound(a+1,a+n+1,a[id]+x)-a-1;
			x-=a[r]-a[id];
			int l=lower_bound(a+1,a+n+1,a[r]-x)-a;
			x-=a[r]-a[l];
			if(l==r){
				printf("%d\n",mp[a[l]]);
				break; 
			}
			x%=2*(a[r]-a[l]);
			id=l;
		}
	}
	return 0;
}