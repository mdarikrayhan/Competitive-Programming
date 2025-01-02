


#include <bits/stdc++.h>

using namespace std;

int n, a;

int main() {
    cin >> n;
    int last0 = -1, last1 = -1;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == 0) last0 = i;
        else last1 = i;
    }
    cout << min(last0 + 1, last1 + 1) << endl;
}