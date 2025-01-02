#include <iostream>
using namespace std;
int n,h,a[400];
long long f[400][400];
int main (){
	cin>>n>>h;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=n;l>=1;l--)
        for(int r=l+1;r<=n;r++){
		for(int k=l;k<r;k++)
            f[l][r]=max(f[l][r],f[l][k]+f[k + 1][r]);
		if(a[l]+h>=a[r]-h) f[l][r]+=h-(a[r]-a[l]-1)/2;
	}
	cout<<1ll*n*h-f[1][n]<<'\n';
	return 0;
}
