#include <iostream>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a * b / gcd(a, b);
}
int main()
{
    unsigned long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (b * d * f > e * a * c || a == 0 && b * d != 0 || c == 0 && d != 0) {
        cout << "Ron";
    }
    else
    {
        cout << "Hermione";
    }
}
