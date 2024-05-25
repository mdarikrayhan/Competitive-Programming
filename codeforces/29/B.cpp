#include<bits/stdc++.h>
using namespace std;

int main() 
{
    double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    double t = d / v;

    t = fmod(t, g + r);

    if (t < g) {
        cout << fixed << setprecision(8) << l / v << endl;
    } else {
        cout << fixed << setprecision(8) << l / v + (g + r - t) << endl;
    }

    return 0;
}
