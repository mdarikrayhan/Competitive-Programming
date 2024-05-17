#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();

    int mismatch_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++mismatch_count;
        }
    }

    if (mismatch_count % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    string p = s;
    int half_mismatches = mismatch_count / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (half_mismatches > 0) {
                p[i] = s[i];
                --half_mismatches;
            } else {
                p[i] = t[i];
            }
        } else {
            p[i] = s[i];
        }
    }

    cout << p << endl;
    return 0;
}
	 		  			 		  		 	 							 		 	