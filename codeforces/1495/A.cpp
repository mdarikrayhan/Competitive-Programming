#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int T,n,a[N],b[N],tot1,tot2,x,y;
int32_t main(){
cin>>T;
while (T--){
cin>>n;
tot1=tot2=0;
for (int i=1;i<=2*n;i++){
cin>>x>>y;
if (!x)a[++tot1]=abs(y);
else b[++tot2]=abs(x);
}
sort(a+1,a+n+1);
sort(b+1,b+n+1);
double ans=0;
for (int i=1;i<=n;i++)ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
printf("%.10lf\n",ans);
}
return 0;
}