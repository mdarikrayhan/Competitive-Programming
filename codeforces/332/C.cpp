// Problem: C. Students' Revenge
// Contest: Codeforces - Codeforces Round 193 (Div. 2)
// Created: 2024-05-23 20:51:03
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, p, k;
	cin >> n >> p >> k;
	vector<array<ll,3>> a(n);
	for(int i=0; i<n; i++){
	    cin >> a[i][1] >> a[i][0];
	    a[i][0] *= -1;
	    a[i][2] = i;
	}
	sort(a.begin(), a.end());
	// cout << "initial order: ";
	// for(int i=0; i<n; i++){
	    // cout << a[i][2] << " \n"[i+1==n];
	// }
	// sort(a.begin(), a.end(), [](array<ll,3> x, array<ll,3> y){
	    // if(x[0] != y[0]) return x[0] < y[0];
	    // return x[1] > y[1];
	// });
	priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>> pq;
	pair<ll, ll> res{0, 0};
	for(int i=0; i<k; i++){
	    pq.push({a[i][1], a[i][0], a[i][2]});
	    res.first += a[i][1];
	    res.second -= a[i][0];
	}
	int ans = -1;
	vector<int> rmv;
	pair<ll, ll> cur(res);
	for(int i=0, j=k; i<n-p; i++, j++){
	    auto [hairs, sad, idx] = pq.top(); pq.pop();
	    // cout << "rmv " << idx << ", add " << a[j][2] << endl;
	    cur.first -= hairs;
	    cur.second += sad;
	    cur.first += a[j][1];
	    cur.second -= a[j][0];
	    pq.push({a[j][1], a[j][0], a[j][2]});
	    rmv.push_back(idx);
	    if(cur > res){
	        res = cur;
	        ans = i;
	    }
	}
	// cout << "ans: ";
	// cout << ans << endl;
	set<int> s;
	for(int i=0; i<=ans; i++) s.insert(rmv[i]);
	for(int i=0; i<n && p>0; i++){
	    if(s.count(a[i][2])) continue;
	    cout << a[i][2]+1 << ' ';
	    --p;
	}
	assert(p == 0);
	
}