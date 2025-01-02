//Abdul Mateen

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define set_precision(n) cout << fixed << setprecision(n);

typedef long long ll;
typedef unsigned long long ull;

ll power(ll a, ll b){
    ll res = 1;
    while (b>0){
        if (b&1)    res = (res*a);
        a = (a*a);
        b = b >> 1;
    }
    return res;
}

// No of leading 0 bits - __builtin_clz(x)
// bitmasks method can be used for num of subsequences

// ll *ptr = lower_bound(a, a+n, 5) // For arrays, for vector use auto it;
// 	cout << *ptr << endl; // gives val
// 	cout << ptr-a << endl; // gives indx


// void addedge(vector <ll> adj[], ll u, ll v){
// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
// }

// ll bfs(vector <ll> adj[], ll s, ll vis[], ll cost[]){
// 	ll ans = cost[s];
// 	vis[s] = 1;
// 	queue <ll> q;
// 	q.push(s);
// 	while (q.empty() == false){
// 		ll t = q.front();
// 		ans = min(ans, cost[t]);
// 		q.pop();
// 		for (auto i: adj[t]){
// 			if (vis[i] == 0){
// 				vis[i] = 1;
// 				q.push(i);
// 			}
// 		}
// 	}
// 	return ans;
// }

void subs(string s, int i, string curr, vector <vector<ll>> &v){
	if (i == s.size()){
		vector <ll> vv;
		for (ll j=0; j<curr.size(); j++){
			vv.push_back(ll(curr[j]-'0'));
		}
		v.push_back(vv);
		return;
	}
	subs(s, i+1, curr+s[i], v);
	subs(s, i+1, curr, v);
}

bool isprime(ll n){
	if (n == 1)	return false;
	if (n == 2 || n == 3)	return true;
	if (n%2 == 0 || n%3 == 0)	return false;
	for (ll i=5; i*i <= n; i+=6){
		if (n%i == 0 || n%(i+2) == 0)	return false;
	}
	return true;
}

ll log_a_to_base_b(ll a, ll b)
{
    return (a > b - 1)
            ? 1 + log_a_to_base_b(a / b, b)
            : 0;
}

void solve(){
	string s;
	cin >> s;
	ll n = s.size();
	bool fg1 = false, fg2 = false;
	for (ll i=0; i<n; i++){
		if(s[i] == '0' && !fg1){
			fg1 = true;
			cout << 1 << " " << 1 << endl;
		}
		else if (s[i] == '0' && fg1){
			cout << 3 << " " << 1 << endl;
			fg1 = false;			
		}
		else if(s[i] == '1' && !fg2){
			fg2 = true;
			cout << 4 << " " << 3 << endl;
		}
		else if (s[i] == '1' && fg2){
			cout << 4 << " " << 1 << endl;
			fg2 = false;			
		}
	}
} 


int main(){ 
    ios::sync_with_stdio(false); cin.tie(NULL);
    set_precision(10);
    ll t=1;
    // cin >> t;	
    while (t--){
        solve();
    }
    return 0;
}