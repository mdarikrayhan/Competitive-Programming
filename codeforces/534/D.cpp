#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    int n;
    cin >> n;
    vector <int> a[n];
    
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x].push_back(1 + i);
    }
    int i = 0;
    vector <int> c;

    while(int(c.size()) < n) {
        if(!a[i].empty()) {
            c.push_back(a[i].back());
            a[i].pop_back();
            ++i;
            continue;
        } 

        if(i < 3) {
            cout << "Impossible\n";
            return 0;
        } else {
            i -= 3;
        }
    }

    cout << "Possible\n";
    for(auto &i: c) {
        cout << i << " ";
    }
    return 0;
}
