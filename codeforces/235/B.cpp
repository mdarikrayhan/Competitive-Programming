// LUOGU_RID: 160143368
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
double p[100005],a[100005],b[100005],c[100005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++){
		a[i]=(a[i-1]+1)*p[i];
		b[i]=b[i-1]+(2*a[i-1]+1)*p[i];
	}
	double ans=b[n];
	printf("%.8lf",ans);
	return 0;
}