#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Delta(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    
    // حالة خاصة: a = b = c = 0
    if (a == 0 && b == 0 && c == 0) {
        cout << -1 << endl;
        return;
    }

    // حالة خاصة: a = b = 0 و c ≠ 0
    if (a == 0 && b == 0) {
        cout << 0 << endl;
        return;
    }

    // حالة خاصة: a = 0
    if (a == 0) {
        cout << 1 << endl;
        cout << fixed << setprecision(10) << -c / b << endl;
        return;
    }
   
    // حساب المميز
    double delta = Delta(a, b, c);
    
    // حالة المميز = 0
    if (delta == 0) {
        cout << 1 << endl;
        cout << fixed << setprecision(10) << -b / (2 * a) << endl;
        return;
    }

    // حالة المميز > 0
    if (delta > 0) {
        cout << 2 << endl;
        double root1 = (-b - sqrt(delta)) / (2 * a);
        double root2 = (-b + sqrt(delta)) / (2 * a);
        cout << fixed << setprecision(10) << min(root1, root2) << endl;
        cout << fixed << setprecision(10) << max(root1, root2) << endl;
        return;
    }

    // حالة المميز < 0
    cout << 0 << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    
    while(t--)
        solve();

    return 0;
}
