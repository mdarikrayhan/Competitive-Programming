// LUOGU_RID: 159545304
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double nowv[105],ans,tot,lst;
signed main(){
	int n; cin>>n;
	double p[n+1]; for(int i=1;i<=n;i++) cin>>p[i],p[i]/=100,p[i]=1-p[i];
	tot=1;
	for(int i=1;i<=n;i++) nowv[i]=p[i],tot*=(1-p[i]);
	for(int i=n;i<=1000000;i++){
		ans+=(tot-lst)*i;
		lst=tot;
		double maxv=0;
		int maxp=0;
		for(int j=1;j<=n;j++){
			if((1-nowv[j]*p[j])/(1-nowv[j])>maxv){
				maxv=(1-nowv[j]*p[j])/(1-nowv[j]);
				maxp=j;
			}
		}
		if(nowv[maxp]==1) break;
		tot=tot/(1-nowv[maxp])*(1-nowv[maxp]*p[maxp]);
		nowv[maxp]*=p[maxp];
	}
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}
