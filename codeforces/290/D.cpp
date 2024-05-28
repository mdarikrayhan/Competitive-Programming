#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int n; cin >> n;

    for(auto &i : s) {
        int d = (i >= 'a' ? i - 'a' : i - 'A');
        if(d < n) d += 'A';
        else d += 'a';
        i = d;
    }
    cout << s << '\n';

    return 0;
}
