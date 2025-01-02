#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool all = true, palindrome = true;
        int first = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[0]) {
                all = false;
                if (first < 0) {
                    first = i;
                }
            }
            if (s[i] != s[n - 1 - i]) {
                palindrome = false;
            }
        }
        if (!palindrome) {
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << s << endl;
        } else if (all) {
            cout << "No" << endl;
        } else {
            bool f = true;
            for (int i = first + 1; i < n && f; i++) {
                if (s[i - first - 1] != s[n - 1 - i]) {
                    f = false;
                }
            }
            if (!f) {
                cout << "Yes" << endl;
                cout << 2 << endl;
                cout << s.substr(0, first + 1) << " " << s.substr(first + 1) << endl;
            } else if (first == (n - 1) / 2) {
                // AbA
                cout << "No" << endl;
            } else if (first == 1) {
                // ababab...ababa
                cout << "No" << endl;
            } else {
                // AbAbAb...AbAbA -> Aba, A-bAbAb...AbA
                cout << "Yes" << endl;
                cout << 2 << endl;
                cout << s.substr(0, first + 2) << " " << s.substr(first + 2) << endl;
            }
        }
    }
    return 0;
}
