#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>

// Define M_PI if it's not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double f(int n, double s) {
    double R = s / (2 * sin(M_PI / n));
    double r = sqrt(R * R - s * s / 4);
    double h = sqrt(s * s - R * R);
 
    return s * r * h * n / 6;
}

inline void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double x = f(3, a) + f(4, b) + f(5, c);
    printf("%.12lf\n", x);
    /*
    double x = f(3, a) + f(4, b) + f(5, c);
    cout << fixed << setprecision(20);
    cout << x << endl;
    */
}

int main() {
    solve();
    return 0;
}
