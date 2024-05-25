#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int answer = n;
    for (int i = 0; i < n; i++) {
        string subString = s.substr(0, i + 1);
        if (s.substr(i + 1, i + 1) == subString) {
            answer = min(answer, n - i);
        }
    }
    cout << answer << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    clock_t z = clock();
    int t = 1;
    //cin >> t;
    while (t--) solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << " ";
    return 0;
}
 		  	 	 		  				   			 		 	  	