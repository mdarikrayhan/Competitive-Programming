#include<bits/stdc++.h>
using namespace std;
#define muslimfat ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() {
    muslimfat
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n * n / 2 << endl;
    }
    else {
        cout << n * n / 2 + 1 << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == j % 2) {
                cout << "C";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}
