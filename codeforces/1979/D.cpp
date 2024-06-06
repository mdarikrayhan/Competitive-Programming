#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> suf(n), pre(n);
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
    	if (s[i] == s[i + 1]) suf[i] = suf[i + 1] + 1;
    	else suf[i] = 1;
    }

    //the pos of a starting block at which it fails
    vector<int> fail(n, 0);
    for (int i = n - 1; i >= 0; i--){
    	fail[i] = i;
    	if (i == n - k && suf[i] == k) fail[i] = n;
    	if (suf[i] < k) continue;
    	if (i + k < n){
    		if (s[i] == s[i + k]) fail[i] = i + k;
    		else fail[i] = fail[i + k];
    	}
    }

    
    pre[0] = 1;
    for (int i = 1; i < n; i++){
    	if (s[i] == s[i - 1]) pre[i] = pre[i - 1] + 1;
    	else pre[i] = 1;
    }

    //ending pos of a 'good' block
    int R = -1;
    for (int i = k - 1; i < n; i += k){
    	if (pre[i] >= k){
    		if (i == k - 1) R = i;
    		else {
    			if (s[i] != s[i - k]) R = i;
    			else break;
    		}
    	}
        else break;
    }
    if (R == n - 1){
        cout << n << "\n";
        return;
    }

    for (int i = 0; i < n - 1; i++){
        //put first (i + 1) char to the back
        int y = fail[i + 1];
        //cout << i <<" "<< y << " "<< R << "~~~\n";
        if (y == n){
            if (R >= i && s.back() != s[i]){
                cout << i + 1 << "\n";
                return;
            }
        }
        else {
            if (n - y >= k) continue;
            if (y != i + 1 && s[y] == s[y - 1]) continue;
            if (suf[y] != n - y) continue;
            //cout << i <<" "<< y << " "<< R << " "<< suf[y] <<" "<< pre[i] << "~~~\n";
            if (suf[y] + pre[i] == k && s[y] == s[i] && R >= i - (k - (n - i - 1) % k) - 1){
                cout << i + 1 << "\n";
                return;
            }
        }
     
    }

    cout << "-1\n";
    return;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}