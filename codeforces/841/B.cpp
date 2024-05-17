#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int a[N];

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 == 1) {
		cout << "First" << endl;
	} else {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 0) {
				cnt2++;
			} else {
				cnt1++;
			}
		}
		if (cnt1 == 0) {
			cout << "Second" << endl;
		} else {
			cout << "First" << endl;
		}
	}
}
			 	    		   	  	 	      		 	