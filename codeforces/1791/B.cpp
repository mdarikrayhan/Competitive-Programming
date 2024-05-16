#include <iostream>

using namespace std;

void solve() {
    int n;
    int x = 0, y = 0;
    string s;
    cin >> n >> s;
    for (char ch: s) {
        if (ch == 'U')y++;
        else if (ch == 'R')x++;
        else if (ch == 'D')y--;
        else if (ch == 'L')x--;
        if (x == 1 && y == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}