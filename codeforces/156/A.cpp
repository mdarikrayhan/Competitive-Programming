#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;cin >> a >> b;int la = a.size();int lb = b.size();
    int s = INT_MAX;

    for (int i = -lb; i < la; i++) {
        int c = 0;
        for (int j = 0; j < lb; j++) {
            if (i + j >= 0 && i + j < la && a[i + j] == b[j]) {
                c++;
            }
        }
        int changes = lb - c;
        s = min(s, changes);
    }
    cout << s << endl;
    return 0;
}
