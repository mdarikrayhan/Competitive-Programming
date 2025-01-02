#ifndef ONLINE_JUDGE
#include "D:\File cua Wayzz\DSA\Debug Template\template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const ll oo = 1e18;
const int N = 2e5 + 10;

// loops
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ROF(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)

// others :>
#define nl " \n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TimeComplexity() cerr <<"\nTime Elapse: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"
//----------------------------------SOLUTION-----------------------------------//

ll n, k, b, c;
ll t[N], p[N], nw[N], cost[N];

void case1(){
	FOR(i, 1, n) p[i] = p[i-1] + t[i];
	ll res = oo;
	FOR(i, k, n){
		res = min(res, t[i] * k - (p[i] - p[i-k]));
	}
	cout << res * c;
}

ll case2(int r){
	// debug(r);
	FOR(i, 1, n){
		int inc1 = (r - t[i] % 5 + 5) % 5;
		cost[i] = inc1 * c;
		nw[i] = (t[i] + inc1 - r) / 5;
	}

	// debug(nw);
	// debug(cost);
	priority_queue<ll> pq;
	ll res = oo, tmp = 0;
	FOR(i, 1, n){
		pq.push(cost[i] - nw[i]*b);
		tmp += cost[i] - nw[i]*b;
		if(pq.size() > k){
			tmp -= pq.top();
			pq.pop();
		}
		if(pq.size() == k){
			res = min(res, k * b * nw[i] + tmp);
		}
	}
	return res;
}

void solve(){
	cin >> n >> k >> b >> c;
	FOR(i, 1, n) cin >> t[i];
	sort(t + 1, t + n + 1);
	if(b >= 5*c){
		case1();
	}
	else{
		ll res = oo;
		FOR(r, 0, 4){
			res = min(res, case2(r));
		}
		cout << res;
	}
}

int main(){
    IOS
	#define task "name"
	if (fopen (task".inp", "r")) {
		freopen (task".inp", "r", stdin);
		freopen (task".out", "w", stdout);
	}
    solve();
}