#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <stack>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <list>
using namespace std;
#define ll long long
#define pt pair<ll, ll>
#define pty pair<ll, pair<ll, ll>>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const ll M = 1000000007;
const ll MOD = 998244353;
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
template<typename T> void swap(T& x,T& y){T temp=x;x=y;y=temp;return;}
ll gcd(ll x,ll y){if(y==0) return x;return gcd(y,x%y);}
ll lcm(ll x, ll y) { return (x * y) / (gcd(x, y)); }

// # ifndef ONLINE_JUDGE
// # include "debug.h"
// #else
// #define dbg::print(...) 1
// #define imie(...) 1;
// #endif

void solve(){
	string s;	cin>>s;
	ll m;	cin>>m;
	string l,r;	cin>>l>>r;
	map<ll,vector<ll> > pos;
	for (ll i=0; i<s.length();i++){
		ll ind = s[i] - '0';
		pos[ind].push_back(i);
	}
	ll prev = 0;
	for (ll i=0; i<m; i++){
		ll low = l[i] - '0';
		ll high = r[i] - '0';
		ll tmp = -1;
		for (ll j=low; j<=high; j++){
			auto iter = lower_bound(pos[j].begin(), pos[j].end(),prev);
			if (iter == pos[j].end()){
				cout<<"YES"<<"\n";
				return;
			}
			ll ind_tmp = iter - pos[j].begin();
			tmp = max(tmp,pos[j][ind_tmp]);
		}
		prev = tmp + 1;
	}
	cout<<"NO"<<"\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;   
	cin >> T;
	//T = 1;
	while (T--)
	{
		solve();
	}
}