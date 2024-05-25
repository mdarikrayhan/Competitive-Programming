#include<bits/stdc++.h>
using namespace std;
int n, a[1000005];
int main() {
	cin >> n;
	for (int i = 1; i <= n / 2; i++) a[i] = a[n - i + 1] = i * 2 - 1;
	for (int i = 1; i <= n / 2; i++) a[i + n] = a[n * 2 - i] = i * 2;
	for (int i = 1; i <= n * 2; i++)
		if (a[i] != 0) cout << a[i] << ' ';
		else cout << n << ' ';
}