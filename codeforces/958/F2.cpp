#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int A[maxn],B[maxn],C[maxn];
int main(){
	int n,m,ok,ans,sum,cnt,q,p;
	scanf("%d%d",&n,&m);
	ans=n;cnt=ok=sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&B[i]);sum+=B[i];
		if(!B[i])cnt++;
	}p=q=1;
	while(q<=n){
		C[A[q]]++;
		if(C[A[q]]==B[A[q]])cnt++;
		if(cnt==m)ok=1;
		if(ok){
			while(C[A[p]]>B[A[p]])C[A[p]]--,p++;
			ans=min(q-p+1,ans);
		}q++;
	}if(ok)printf("%d",ans-sum);else printf("-1");
	return 0;
} 