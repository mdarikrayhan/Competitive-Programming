#include <bits/stdc++.h>
using namespace std;
main(){
	int x=100, y[10] = {0, 1, 5, x, x, 2, x, x, 8, x};
	int t; 
	cin>>t; 
	while (t--) {
		int h,m; cin>>h>>m;
		int a1,a2; char t; cin>>a1>>t>>a2; 
		while (1){
			int b1=y[a2%10]*10+y[a2/10];
			int b2=y[a1%10]*10+y[a1/10];
			if (b1<h and b2<m){
				printf("%02d:%02d\n", a1, a2);
				break;
			}
			if (++a2==m) a2=0, a1=(a1+1)%h;
		}
	}
}