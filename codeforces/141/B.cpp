#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int a, x, y;
	cin >> a >> x >> y;
	bool flag = true;
	if(x<0) {
		x = -x;
		flag = !flag;
	}
	if(y%a == 0) cout << -1;
	else{
		int t = y/a + 1;
		if(t&1 && t!=1) {
			if(x>=a || x == 0) cout << -1 ;
			else {
				int p = t+(t/2)+flag;
				if(t/2) p--;
				cout << p;
			}
		}
		else{
			if( x*1.0 >= (a/2.0)) cout << -1 ;
			else {
				int p = t+(t/2);
				if(t/2) p--;
				cout << p;
			}
		}
	}
	return 0;
}