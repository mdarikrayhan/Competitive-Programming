#include <bits/stdc++.h>
using namespace std;
int n,k,bit,inf=1e9;
int main(){
    cin>>n>>k;
	bit=1<<(n-1);
	vector<vector<int> >f(bit*2,{0,-inf,-inf,-inf});
	for(int i=1,a;i<=k;i++) {
		cin>>a;
		a=bit+(a-1)/2;
		f[a][3]=f[a][1];f[a][1]=f[a][2]=1;
	}
	for(int i=bit-1;i>0;i--)
		for(int x=0;x<4;x++)for(int y=0;y<4;y++)
				f[i][x|y]=max(f[i][x|y],f[2*i][x]+f[2*i+1][y]+(x|y));
	printf("%d\n",max({f[1][1],f[1][2],f[1][3],-1})+1);
	return 0;
}