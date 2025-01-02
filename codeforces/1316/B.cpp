#include<bits/stdc++.h>
using namespace std;

string generate(int k, string& s) {
    int n = s.size();
    string pre = s.substr(k-1, n-k+1);
    string suf = s.substr(0, k-1);
    if(n%2==k%2) reverse(suf.begin(), suf.end());
    return pre+suf;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ansk = 1;
        // abcd
        // bcda 2
        // cdab 3
        // dcba 4
        for(int k = 2; k<=n; k++) {
            if(generate(ansk, s) > generate(k, s)) {
                ansk = k;
            }
        }
        cout << generate(ansk, s) << endl;
        cout << ansk << endl;
    }
}