#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;
#define pb  push_back
#define pf  push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
const ll mod = 998244353;
const ll gen = 3;
const int N = 1e5;
const ll INF = 1e18;
void add(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
}
ll binpow(ll a, ll n){
	ll res = 1;
	ll step = 1 << 30;
	while(step){
		res = (res * res) % mod;
		if(step & n) res = (res * a) % mod;
		step >>= 1;
	}
	return res;
}
void fft(vll &a){
	ll n = (ll)a.size();
	for(ll i = 0; i < n; i++){
		ll j = 0;
		ll x = i, y = n - 1;
		while(y > 0){
			j = (j << 1) + (x & 1);
			x >>= 1;
			y >>= 1;
		}
		if(i < j) swap(a[i], a[j]);
	}
	for(ll len = 1; len < n; len *= 2){
		ll root = binpow(gen, (mod - 1)/ (2 * len));
		for(ll i = 0; i < n; i+= 2 * len){
			ll w = 1;
			for(ll j = 0; j < len; j++){
				ll u = a[i + j];
				ll v = a[i+j+len] * w % mod;
				a[i + j] = u + v;
        		if(a[i + j] >= mod) a[i + j] -= mod;
				a[i+j+len] = u - v;
				if(a[i+j+len] < 0) a[i + j + len] += mod;
				w = w * root % mod;
			}
		}
	}
}
ll nn;
vll mult(vll a, vll b){
	a.resize(2 * nn), b.resize(2 * nn);
	fft(a); fft(b);
	for(ll i = 0; i < 2 * nn; i++){
		a[i] = a[i] * b[i] % mod;
	}
	reverse(++a.begin(), a.end());
	fft(a);
	ll inv = binpow(2 * nn, mod - 2);
	for(ll i = 0; i < 2 * nn; i++){
		a[i] = a[i] * inv % mod;
	}
	a.resize(nn);
	return a;
}
pair<vll, vll> get(ll n) {
  if (n == 1) {
    vll a(nn, 0);
    vll b(nn, 0);
    a[0] = 1;
    b[0] = 1; b[1] = 1;
    return {a, b};
  }
  if (n == 2) {
    vll a(nn, 0);
    vll b(nn, 0);
    a[0] = 1; a[1] = 1;
    b[0] = 1; b[1] = 3; b[2] = 1;
    return {a, b};
  }
  if (n % 2 == 1) {
    pair < vll, vll > p = get(n - 1);
    vll a = p.first;
    vll b = p.second;
    vll c(nn, 0);
    for(ll i = 0; i < nn; i++) {
      add(c[i], b[i]);
      if(i > 0) {
        add(c[i], b[i - 1]);
        add(c[i], a[i - 1]);
      }
    }
    return {b, c};
  }
  pair<vll,vll> p = get(n / 2);
  vll a = p.first;
  vll b = p.second;
  vll a2 = mult(a, a);
  vll b2 = mult(b, b);
  vll my_b(nn, 0);
  for(ll i = 0; i < nn; i++) {
    add(my_b[i], b2[i]);
    if(i > 0){
      add(my_b[i], a2[i - 1]);
    }
  }
  vll z(nn, 0);
  for(ll i = 0; i < nn; i++) {
    add(z[i], mod - a[i]);
    if (i + 1 < nn) {
      add(z[i], b[i + 1]);
      add(z[i], mod - a[i + 1]);
    }
  }
  vll z2 = mult(z, z);
  vll my_z(nn, 0);
  for(ll i = 0; i < nn; i++) {
    add(my_z[i], a2[i]);
    if (i > 0) {
      add(my_z[i], z2[i - 1]);
    }
  }
  vll aux(nn, 0);
  for(ll i = 0; i < nn; i++) {
    add(aux[i], my_b[i]);
    if (i > 0) {
      add(aux[i], mod - my_z[i - 1]);
    }
  }
  vll my_a(nn, 0);
  my_a[0] = aux[0];
  for(ll i = 1; i < nn; i++) {
    my_a[i] = aux[i];
    add(my_a[i], mod - my_a[i - 1]);
  }
  return {my_a, my_b};
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n, k; cin >> n >> k;
	nn = 4;
	while(nn <= k) nn *= 2;
	vll a = get(n+1).x;
	for(ll i = 1; i <= k; i++){
		cout << (i < nn ? a[i] : 0) << " ";
	}
	cout << '\n';
	return 0;
}