#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
long double x, y, x2, y2, r1, r2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y >> r1 >> x2 >> y2 >> r2;
    x -= x2;
    y -= y2;
    long double d = sqrt(x * x + y * y);
    if (r1 > r2) {
        swap(r1, r2);
    }
    if ((r1 + r2) * (r1 + r2) <= x * x + y * y) {
        cout << 0;
        return 0;
    }
    if (d + r1 <= r2) {
        cout << fixed << setprecision(9) << PI * r1 * r1;
        return 0;
    }
    long double a1 = acos((r1 * r1 + x * x + y * y - r2 * r2) / (2.0 * r1 * d));
    long double a2 = acos((r2 * r2 + x * x + y * y - r1 * r1) / (2.0 * r2 * d));
    long double A1 = a1 * r1 * r1;
    long double A2 = a2 * r2 * r2;
    cout << fixed << setprecision(9) << A1 + A2 - r1 * r1 * sin(a1 * 2) / 2.0 - r2 * r2 * sin(a2 * 2) / 2.0;
}