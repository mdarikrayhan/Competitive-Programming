#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int v[1010][1010]; int c[1010], n, m, a=0, b=0; cin>>n>>m;
	for(int i=0;i<n;i++){
		int x, y; cin>>x>>y;
		c[y]++, v[x][y]++;
	}
	for(int i=0;i<m;i++){
		int x, y; cin>>x>>y;
		if(v[x][y])
			b++,v[x][y]--;
		if(c[y])
			a++,c[y]--;
	}
	cout<<a<<" "<<b;
}