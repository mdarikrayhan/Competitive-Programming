#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        string s;
        cin >> s;
 
        int l = 0;
        int r = n - 1;
        forn(i, n - 1)
            if (s[i] == 'L')
                l++;
            else
                r--;
        assert(l == r);
 
        vector<int> b(n);
        b[n - 1] = a[l] % m;
 
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'L')
                b[i] = (b[i + 1] * a[--l]) % m;
            else
                b[i] = (b[i + 1] * a[++r]) % m;
        }
        assert(l == 0);
        assert(r == n - 1);
 
        forn(i, n)
            cout << b[i] << " ";
        cout << endl;
    }
}