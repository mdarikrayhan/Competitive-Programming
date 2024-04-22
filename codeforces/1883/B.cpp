 #include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef ONLINE_JUDGE
#define debug(...) 42
#define debug_array(x,y) 42
#else
#include "deBUG.h"
#endif

bool palindrome(string s) {
    string temp = s;
    ranges :: reverse(temp);
    return  temp == s;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    for(int testCase=1; testCase <= T; testCase++) {
    
        int n, k;
        bool flag = false;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char,int>mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int odd = 0;
        for(auto x : mp) {
            if(x.second & 1) odd++;
        }
        if(k <= n and k >= max(0, odd - 1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        
        
        

    }
    return 0;
}
