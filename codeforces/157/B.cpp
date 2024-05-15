#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>

using namespace std;

const double p = 3.1415;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	double sum = 0;
	if (n & 1) {
        sum += a[n - 1] * a[n - 1] * p;
	}
	for (int i = 0; i < n - 1; ++i) {
        if (!(i & 1)) {
            sum += p * (a[i] * a[i] - a[i + 1] * a[i + 1]);
        }
	}
	cout << fixed << setprecision(4) << sum;
}

