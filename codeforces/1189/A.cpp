#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 2e9 + 23;
ll inf = 1e18 + 23;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    string s; cin >> s;
    ll c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++){
        c1 += s[i] == '1';
        c0 += s[i] == '0';
    }
    if(c0 != c1){
        cout << 1 << "\n";
        cout << s << "\n";
        return 0;
    }
    cout << 2 << "\n";
    ll last = 0;
    for(int i = 0; i < n; i++){
        cout << s[i];
        c0 -= s[i] == '0';
        c1 -= s[i] == '1';
        if(c1 != c0){
            last = i;
            break;
        }
    }
    cout << " ";
    for(int i = last+1; i < n; i++){
        cout << s[i];
    }
    return 0;
}
			    	    	  			  	 		 	 	 	