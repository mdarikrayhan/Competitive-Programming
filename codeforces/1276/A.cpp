#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "TemplateDebugging.cpp"
#else
#define debug(...)
#define debugv(...)
#endif

using namespace std;

#define int long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#define pb push_back
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb ler_bound

// en C puedes entrar lo que quieras.

const int MAXN = 1e5 + 1;
const int MOD = 998244353;

int dx[8] = {-1,0,1,0,0,-1,-1,-1};
int dy[8] = {0,1,0,-1,-1,-1,0,1};


main(){
    ios;

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        vector<int> v;
        for (int i = 0; i < n; i++){
        string x = "";
        string y = "";
        for(int j = i - 2; j <= i; j++){
            if(j >= 0 && j < n){
                x += s[j];
            }
        }
        
        for(int j = i; j <= i + 2; j++){
            if(j >= 0 && j < n) {
                y += s[j];
            }
        }

        if(x == "two" && y == "one"){
            v.pb(i + 1);
            i += 2;
        }

        else if(x == "two" && y != "one"){
            v.pb(i);
        }
        else if(x == "one"){
            v.pb(i);
        }
    }

        cout << v.size() << endl;
        for(auto i : v) cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}
