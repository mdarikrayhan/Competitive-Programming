#include<bits/stdc++.h>
using namespace std;
int const M=500500;
int i,n,t,m1,m2,ans,a[M],A[M],B[M];
void solve(){
	for (i=1,t=0;i<=n;i++) A[i]=1<<30,t=(a[i]>a[t])?i:t;
	for (i=n,m1=m2=0;i>t;A[i]=m1,B[i--]=m2)
		if (m2<a[i]) m2=a[i];
		else if (m1<a[i]&&a[i]<a[t]) m1=a[i];
		else break;
	for (i=1,m1=m2=0;i<=t;i++)
		if (m1<a[i]&&a[i]<=a[t]) m1=a[i];
		else if (m2<a[i]) m2=a[i];
		else return ;
	for (;i<=n;ans+=(m1>A[i]&&m2<=B[i]),i++)
		if (m2<a[i]&&(m1<a[i]||a[i]<a[i+1])) m2=a[i];
		else if (m1>a[i]) m1=a[i]; else break;
}
int main(){ scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	solve();reverse(a+1,a+1+n);solve();
	return printf("%d\n",ans),0;
}