#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll __int128
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ull unsigned long long 
#define i128 __int128
using namespace std; 
const int N = 2e5 + 7, mod = 998244353;
ll p, q;
ll pw[30];
ll pres[30];
int dig[N];
ll rd() {
	long long w;
	cin >> w;
	return w;
}
inline ll abs(ll w) {
	return w > 0 ? w : -w;
}
mt19937_64 orz;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	p = rd();
	q = rd();
//	p = orz(), q = -orz();
//	p = -55553298528923589LL;
//	q = 555523888888888LL;
	pw[0] = 1;
	L(i, 1, 29)pw[i] = pw[i - 1] * 10; 
	L(i, 0, 29)pres[i] = pw[i];
	L(i, 1, 29)pres[i] += pres[i - 1];
	cout << "0";
	while((p - q) % 9) {
		cout << "+1-0";
		p -= 1;
		q += 1;
	}
	while(p != q){
		ll v = p - q;
		int h = 0;
		R(i, 29, 0) if(abs(v) + 1 >= pw[i]) {
			h = i;
			break;
		}
		L(i, 0, h) dig[i] = 0;
		R(i, h, 0) if(i > h - i) {
			ll move = pw[i] - pw[h - i];
			if(v >= 0) {
				int k = min(v / move, (ll)8);
				v -= move * k;
				dig[i] = 1, dig[h - i] = k + 1;
			} else {
				int k = min(-v / move, (ll)8);
				v += move * k;
				dig[i] = k + 1, dig[h - i] = 1;
			}
		}
		ll c1 = 0, c2 = 0;
		R(i, h, 0) c2 *= 10, c2 += dig[i];
		L(i, 0, h) c1 *= 10, c1 += dig[i];
		p -= c1, q -= c2;
		cout << "+";
		L(i, 0, h) cout << (int)dig[i];
	}
	if(p < 0) {
		cout << "+0";
		p = -p;
		R(i, 29, 0) {
			ll k = p / pres[i];
			p -= pres[i] * k;
			while(k > 0) {
				int w = min(k, (ll)9);
				cout << "-";
				L(j, 0, i) cout << w;
				k -= w;
			}
		}
		cout << "-0";
	} else {
		R(i, 29, 0) {
			ll k = p / pres[i];
			p -= pres[i] * k; 
			while(k > 0) {
				int w = min(k, (ll)9);
				cout << "+";
				L(j, 0, i) cout << w;
				k -= w;
			}
		}
	}
	return 0;
}