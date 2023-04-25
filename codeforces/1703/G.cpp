#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,K,a[100005];
void sol(){
	scanf("%d%d",&n,&K);ll s=0,ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=n;i++){
		if(i)s+=a[i];ll res=s;
		for(int j=i+1,k=1;j<=n&&k<=30;j++,k++)
			res+=a[j]>>k;
		ans=max(ans,res-(ll)i*K);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}