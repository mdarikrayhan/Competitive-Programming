#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int n,m,a[N],b[N],pa,pb;
bool chk(int o){
	long long now=0,mx=0,mx2=0;
	int i=n-1,j=m,y=0,x=0;
	while(x<n&&a[x+1]+b[j]<o)++x;
	for(;~i;--i){
		while(y<m&&a[i+1]+b[y+1]<o)++y;
		now+=m-y-j;
		while(j&&n-x-i>0){
			now+=n-x-i,--j;
			if(j)while(x<n&&a[x+1]+b[j]<o)++x;}
		mx=max(mx,now);
		if(pa<=i||pb<=j)mx2=max(mx2,now);}
	return mx!=mx2;}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=m;++i)cin>>b[i];
	int a1=a[1],b1=b[1],l=1,r=a1+b1,x;
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	pa=lower_bound(a+1,a+n+1,a1)-a,pb=lower_bound(b+1,b+m+1,b1)-b;
	while(l<r){
		x=(l+r+1)>>1;
		if(chk(x))l=x;else r=x-1;
    }
	cout<<l;}