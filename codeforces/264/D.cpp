#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, t; cin >> s >> t;

    ll cc = 0;
    map<string, ll> mp;
    int pl = 0, pr = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (pr < t.size() && t[pr] != s[i]) {
            if (pr) ++mp[string(1,t[pr])+string(1,t[pr-1])];
            ++pr;
        }
        if (pr < t.size()) {
            if (pr) ++mp[string(1,t[pr])+string(1,t[pr-1])];
            ++pr;
        }


        if (i && (s[i-1] != s[i])) cc += pr-pl-mp[string(1,s[i-1])+string(1,s[i])];
        else cc += pr-pl;
        
        if (pl < t.size() && t[pl] == s[i]) {
            if (pl) --mp[string(1,t[pl])+string(1,t[pl-1])];
            ++pl;
        }
    }

    cout << cc << '\n';

}

    	     	 	    				  	 			 	