#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fr(i,m,n) for (int i = m; i < n; i++)
#define frr(i,m,n) for (int i = m; i >= n; i--)
#define print(n) cout << n << endl
#define NA cout << "NO" << endl
#define HA cout << "YES" << endl
#define ain(a,n) fr(i,0,n) cin >> a[i]
#define aout(a,n) fr(i,0,n) cout << a[i] << " "
#define fastAF ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main () { fastAF;
    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        map <char,int> blah;
        fr(i,1,n) {
            if (i == n-1) blah[s[i]]++;
            if (s[i] != s[i-1]) {
                blah[s[i-1]]++;
            }
        } int flag = 0;
        for (auto i : blah) {
            if (i.second > 1) flag = 1;
        } if (flag) NA;
        else HA;
    }
}
 			  	 			 	  		   				  	  		