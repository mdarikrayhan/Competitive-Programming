#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n % 2) cout << n / 2 + 1;
	else cout << n / 2;
	return 0;
}