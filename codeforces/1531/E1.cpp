#include "bits/stdc++.h"
using namespace std;
const int M = 1'100;
int a[M];
int b[M];
int x[M];
int n = 16;
string s;
void restore(int l, int r) {
if (r - l <= 1)
return;
int m = (l + r) >> 1;
restore(l, m);
restore(m, r);
int i = l;
int j = m;
int k = l;
while (i < m && j < r) {
if (s.back() == '0') {
b[k++] = a[i++];
} else {
b[k++] = a[j++];
}
s.pop_back();
}
while (i < m) {
b[k++] = a[i++];
}
while (j < r) {
b[k++] = a[j++];
}
copy(b + l, b + r, a + l);
}
int main() {
cin >> s;
reverse(s.begin(), s.end());
iota(a, a + n, 0);
restore(0, n);
for (int i = 0; i < n; ++i)
x[a[i]] = i;
cout << n << "\n";
for (int i = 0; i < n; ++i)
cout << x[i] + 1 << " ";
cout << "\n";
return 0;
}