// LUOGU_RID: 158976848
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	if (n < 20) {
		if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 12)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
	else {
		int a = n / 10, b = n % 10;
		if (a == 2 || a == 7 || a == 9 || b == 1 || b == 7 || b == 9)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}