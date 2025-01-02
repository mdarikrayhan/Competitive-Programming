#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; 
	cin >> T;

	while(T--) {
		int mx,xr,i;
		cin >>mx>>xr;
		int bef=mx, x=xr;

		while(bef%4) bef--;
		for(i= bef; i<mx; i++)
			x^= i;
			cout <<mx+ (x>0)+(x==mx) <<endl;

	}
}