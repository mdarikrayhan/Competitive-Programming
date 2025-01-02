// LUOGU_RID: 159169137
#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
long double ans=1e18;
struct node{
	double x,y,z;
}a[N];
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j)
				continue;
			long double t=dis(a[1],a[i])+dis(a[1],a[j])+dis(a[i],a[j]);
			ans=min(ans,t/2);
		}
	}
	cout<<fixed<<setprecision(15)<<ans<<endl;
	return 0;
}
