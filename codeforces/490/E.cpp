#include <bits/stdc++.h>
using namespace std;

void fill_smallest(string &s, int ind) {
    for (int i = ind; i < s.length(); i++) {
        if (s[i] == '?') {
            if (i == 0) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }
}

bool can_beat(string &x, string &y, int ind) {
    for (int i = ind; i < x.length(); i++) {
        if (x[i] != '?') {
            if (x[i] < y[i]) {
                return false;
            } else if (x[i] > y[i]) {
                return true;
            }
        } else {
            if (y[i] < '9') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s[n];
    int prev_len = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i].length() < prev_len) {
            possible = false;
        }
        prev_len = s[i].length();
    }

    if (possible) {
        fill_smallest(s[0], 0);
        for (int i = 1; i < n; i++) {
            if (s[i].length() > s[i - 1].length()) {
                fill_smallest(s[i], 0);
                continue;
            }
            bool beat = false;
            for (int j = 0; j < s[i].length(); j++) {
                if (s[i][j] != '?') {
                    if (s[i][j] < s[i - 1][j]) {
                        break;
                    } else if (s[i][j] > s[i - 1][j]) {
                        fill_smallest(s[i], j);
                        beat = true;
                        break;
                    }
                } else {
                    if (can_beat(s[i], s[i - 1], j + 1)) {
                        s[i][j] = s[i - 1][j];
                    } else if (s[i - 1][j] == '9') {
                        continue;
                    } else {
                        s[i][j] = s[i - 1][j] + 1;
                        fill_smallest(s[i], j + 1);
                        beat = true;
                        break;
                    }
                }
            }
            if (!beat) {
                possible = false;
                break;
            }
        }
    }
    if (possible) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << s[i] << "\n";
        }
    } else {
        cout << "NO\n";
    }

}