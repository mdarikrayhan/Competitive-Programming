#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	
	int s = n - 1;
	while (n --) {
	    int a;
	    cin >> a;
	    s += a;
	}
	
	if (s == x) {
	    cout << "YES";
	} else {
	    cout << "NO";
	}

	return 0;
}