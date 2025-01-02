// LUOGU_RID: 158041667
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
 
using namespace std;
const int N = 1000005;
typedef long long ll;
 
int n;
ll a[N], b[N];
 
void init () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
}
 
ll solve () {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1 || a[i] * 2 < b[i]) ans--;
		else {
			ll k = b[i] / 2;
			ans += (k * (b[i] - k));
		}
	}
	return ans;
}
 
int main () {
	init();
	cout << solve() << endl;
	return 0;
}