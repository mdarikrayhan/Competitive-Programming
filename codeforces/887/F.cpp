#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,i,l,a[500001],cnt,f,j,m;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	l=1;
	for(i=2;i<=n;i++){
		if(a[i]<a[l]){l=i;cnt=0;continue;}else cnt++;
		if(cnt>=k){
			if(f)return puts("NO");
			f=1;
			for(j=l+1;j<=n;j++)if(a[l]>a[j]&&a[j]>a[m])m=j;
			if(!m)return puts("NO");
			swap(a[l+k],a[m]);
			l+=k;cnt=0;
		}
	}
	puts("YES");
}