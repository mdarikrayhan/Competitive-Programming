#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int n,k;
double ans,f[N];
struct stuff{
	int x,w,c;
	bool operator<(const stuff&z)const{return x<z.x;}
}c[N];
double calc(int j,int i){return 1.0*(c[i].c+c[j].c)*(c[i].x-c[j].x)/200*k;}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>c[i].x>>c[i].w>>c[i].c;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) f[i]=max(f[i],f[j]+calc(j,i));
		f[i]-=c[i].w;ans=max(ans,f[i]);
	}
	printf("%.12lf\n",ans);
	return 0;
}