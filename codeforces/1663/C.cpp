#include <iostream>
using namespace std;
int main() {
    long long n, s = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s += x;
    }
    cout << s;
}