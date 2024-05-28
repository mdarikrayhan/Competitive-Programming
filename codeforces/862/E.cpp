#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
 
using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;

 set<ll> s;

ll findNearest(ll sum1){
	ll sum2 = 0;
    auto it = s.lower_bound(sum1);
    if (it == s.begin()) {
        sum2 = *it;
    } else if (it == s.end()) {
        it--;
        sum2 = *it;
    } else {
        ll a = *it;
        it--;
        ll b = *it;
        if (sum1-b < a-sum1) sum2 = b;
        else sum2 = a;
    }
    return sum2;	
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n + 1,0);
    vector<ll> b(m + 1,0);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] *= (i % 2 ? 1 : -1);
    }
    for(int i = 1; i <= m; i++){
    	cin >> b[i];
    	b[i] *= (i % 2 ? 1 : -1);
    }
    vector<ll> prefB(m + 1, 0);
    prefB[0] = 0;
    for(int i = 1; i <= m; i++){
    	prefB[i] = prefB[i - 1] + b[i];
    }
    for(int j = 0; j <= m - n; j++){
    	ll Sumj = prefB[n + j] - prefB[j];
        if(j % 2 == 0) s.insert(Sumj);
        else s.insert(-Sumj);  
    }
    ll sum1 = 0;
    for(int i = 1; i <= n; i++){
    	sum1 += a[i];
    }
    cout << abs(sum1 - findNearest(sum1)) << "\n";  	
    while(q--){
    	int l, r, x;
    	cin >> l >> r >> x;
    	if((l - r + 1) % 2){
    		if(l % 2){
    			sum1 += x;
    		    cout << abs(sum1 - findNearest(sum1)) <<"\n";
    		}
    		else{
    			sum1 -= x;
    		    cout << abs(sum1 - findNearest(sum1)) <<"\n";
    		}
    	}
    	else{
    		cout << abs(sum1 - findNearest(sum1)) << "\n";
    	}
    }
    
}