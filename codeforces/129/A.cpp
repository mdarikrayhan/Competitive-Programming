#include <bits/stdc++.h>
using namespace std;

int n,a;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while (t--) {
		cin>>n;
		int b=0,c=0;
		for(int i=0;i<n;i++){
			cin>>a;
			if(a&1) b++;
			else c++;
		}
		if(b&1)
			cout<<b;
		else
			cout<<c;
	}
	return 0;
}
