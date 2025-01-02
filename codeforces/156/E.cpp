#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 10011;
INT a[NN];
int n, m;
char s[NN];
int t[NN];

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int mod[]=  {300690390,2044926619,1808691197,2073080791};
int id[]=   {0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,2,2,3,2,3,3,3,3,2,2};
map<pii, int> mp[17];
int d, len;
INT c;
int b[NN];

inline int decode(int *b, int ans = 0) {
	for(int i=0; i<len; i++) ans = ans * (d+1) + b[i];
	return ans;
}

int calc(int now, int id) {
	if(mp[d].count({now, id})) return mp[d][{now, id}];
	int re=0;
	for(int i=0; i<len; i++) {
		re = re * d + b[i];
		if(b[i] == d) {
			int ans = 1;
			for(int j=0; j<d; j++) {
				b[i] = j;
				ans = (INT)ans *  calc(decode(b), id) % mod[id];
			}
			return b[i]=d, mp[d][{now, id}] = ans;
		}
	}
	return re < n ? (a[re] % mod[id]) : 1;
}

inline int query() {
	scanf("%d %s %I64d", &d, s, &c);
	int l=0;
	int now=1;
	while(now<n) now*=d, l++;
	len = strlen(s);
	for(int i=max(0, len-l), j=0; s[i]; i++, j++) b[j] = (s[i] >= 'A' ? s[i] - 'A' + 10 : s[i] == '?' ? d : s[i]- '0'), len=j;
	len ++;
	if(n==1) len=1;
	int val = decode(b);
	for(int i=0; i<25; i++) {
		int now = calc(val, id[i]);
		if((c + now) % prime[i] == 0) return prime[i];
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> n;
	for(int i=0; i<n; i++) scanf("%I64d", a+i);
	cin >> m;
	while(m--) printf("%d\n", query());
}