#include <bits/stdc++.h>

#define ll long long
#define en "\n"
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
#define rep(i, a, b) for(ll i = a; i <= b; ++i)
#define per(i, a, b) for(ll i = a; i >= b; --i)
#define kaizokuO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define r0 return 0
#define all(v) v.begin(), v.end()
#define gcd(a,b) __gcd(a,b);
#define lcm(a,b) (a*b)/ __gcd(a, b)
#define bitt(x) __builtin_popcount(x)
#define flsh fflush(stdout)
#define ext exit(0)
#define inp freopen("input.txt","r",stdin)
#define outp freopen("output.txt","w",stdout)

using namespace std;

//const ll mod = 1e9 + 7;
//const ll mod = 998244353;
//const ll mod = 26101991;
//const double pi = 3.14159;
//ll C[1003][1003];
/*void nCr(){
    for(ll i = 0; i <= 1000; i++) C[i][0] = 1;
    for(ll i = 1; i <= 1000; i++) C[i][i] = 1;
    for(ll i = 1; i <= 1000; i++){
        for(ll j = 1; j <= 1000; j++){
            if(i != j) C[i][j] = (C[i-1][j]%mod + C[i-1][j-1]%mod)%mod;
        }
    }
}*/
 
 
/*const int MAX_N = 1e5+5;
pair<pii, pii> st[10*MAX_N]; //binary tree
ll ar[2*MAX_N];
pair<pii,pii> merge(pair<pii, pii> a, pair<pii, pii> b){
	if(a.fi.fi==b.fi.fi) return {{a.fi.fi,a.fi.se+b.fi.se}, {max(a.se.fi, b.se.fi), a.se.fi == b.se.fi ? a.se.se+b.se.se : (a.se.fi<b.se.fi?b.se.se:a.se.se)}};
	return {{max(a.fi.fi, b.fi.fi),a.fi.fi<b.fi.fi?b.fi.se:a.fi.se}, {max(min(a.fi.fi, b.fi.fi), max(a.se.fi,b.se.fi)), a.fi.fi < b.fi.fi ? (a.fi.fi > b.se.fi ? a.fi.se : (a.fi.fi==b.se.fi?a.fi.se+b.se.se:b.se.se)) : (b.fi.fi > a.se.fi ? b.fi.se : (b.fi.fi==a.se.fi?b.fi.se+a.se.se:a.se.se))}};
}
void build(ll l, ll r, ll node){
	if(l==r) st[node] = {{ar[l], 1LL},{(ll) -1,0LL}};
	else{
		int m = (l+r)/2;
		build(l,m,node*2);
		build(m+1,r,node*2+1); 
		st[node] = merge(st[node*2], st[node*2+1]);
	}
}
void update(ll id, ll v, ll l, ll r, ll node){
	if(l==r) st[node] = {{v, 1LL},{(ll) -1, 0LL}};
	else{
		int m = (l+r)/2;
		if(id <= m) update(id,v,l,m,node*2);
		else update(id,v,m+1,r,node*2+1);
		st[node] = merge(st[node*2], st[node*2+1]);
	}
}
pair<pii, pii> query(ll A, ll B, ll l, ll r, ll node){
	if(r < A || l > B) return {{-1,0},{-1,0}};
	if(A <= l && r <= B) return st[node];
	int m = (l+r)/2;
	return merge(query(A,B,l,m,node*2), query(A,B,m+1,r,node*2+1));
}*/

void solve(){
	string s; cin >> s;

	bool turn = 1;
	ll idx = 0;
	ll len = s.length();
	string ans = "";
	while(idx < len){
		ll sm = 1;
		for(ll i = idx+1; i < len; ++i){
			if(s[i] == s[i-1]) sm++;
			else break;
		}
		if(sm==1){
			ans += s[idx];
			turn = 1;
		} else if(sm == 2){
			if(turn) {ans += s[idx]; ans += s[idx+1];}
			else ans += s[idx];
			turn ^= 1;
		} else if(sm >= 3){
			if(turn) {ans += s[idx]; ans += s[idx+1];}
			else ans += s[idx];
			turn ^= 1;
		}
		idx += sm;
	}
	cout << ans << en;
	
}

int main() {
    kaizokuO;

    ll t = 1; //cin >> t;
    while(t--){
        solve();
    }
}