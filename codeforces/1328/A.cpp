// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int remainder = a % b;

        int moves = (remainder == 0) ? 0 : b - remainder;

        cout << moves << endl;
    }

    return 0;
}