#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const char nl = '\n';

void Solve(){
    string s;
    cin >> s;
    int a = 'a' - 1;

    for(auto x : s) {
        if(x > a + 1) {
            cout << "NO\n";
            return;
        } else if ( x == a + 1) {
            a ++;
        } 
    }
    cout << "YES\n";
}

int main() {
    int t = 1;
    while(t--) {
        Solve();
    }
	return 0;
}
