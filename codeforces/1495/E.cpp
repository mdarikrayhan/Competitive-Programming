// LUOGU_RID: 158415290
#include<bits/stdc++.h>
#define ll long long
#define db double
#define rep(i, x, n) for(ll i = x; i <= n; i++)
using namespace std;
inline ll read() {
	ll x = 0; bool op = 0;
	char c = getchar();
	while(!isdigit(c)) op |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return op ? -x : x;
}
const int N = 5e6 + 5;
const int M = 2e5 + 5;
const int Mod = 1e9 + 7;
ll n, m, seed = 0, base = 0, 
   t[N], a[N], ans[N],
   p[M], k[M], b[M], w[M];
ll rnd() {
	ll ret = seed;
	seed = (seed * base + 233) % Mod;
	return ret;
}
void Get(){
	n = read(); m = read();
	rep(i, 1, m)
		p[i] = read(), k[i] = read(), b[i] = read(), w[i] = read();
	rep(i, 1, m){
		seed = b[i]; base = w[i];
		rep(j, p[i - 1] + 1, p[i]){
			t[j] = rnd() % 2 + 1;
			a[j] = rnd() % k[i] + 1;
		}
	}
	return ;
}
int main(){
	Get();
	ll sum1 = 0, sum2 = 0;
	rep(i, 1, n){
		if(t[i] == 1) sum1 += a[i];
		else sum2 += a[i];
	}
	if(sum1 > sum2){
		swap(sum1, sum2);
		rep(i, 1, n) t[i] = 3 - t[i];
	}
	ll cnt = 0, cur = 1;
	if(t[1] != 1){
		a[1]--; ans[1]++;
		rep(i, 2, n)
			if(t[i] == 1) {cur = i; break;}
	}
	while(cnt || sum1){
		if(t[cur] == 1){
			ans[cur] += a[cur]; cnt += a[cur];
			sum1 -= a[cur]; a[cur] = 0;
		}
		else{
			ll d = min(a[cur], cnt);
			ans[cur] += d; cnt -= d; a[cur] -= d;
		}
		cur = (cur == n) ? 1 : cur + 1; 
	} 
	ll res = 1;
	rep(i, 1, n)
		res = (res * (((ans[i] ^ (i * i)) + 1) % Mod)) % Mod;
	printf("%lld\n", res);	
	return 0;
}
