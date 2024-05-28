#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define Mp make_pair
using namespace std;
typedef long long ll;

#define MAXV 7000
#define MAXN 100000
int n, q;
bitset<MAXV+5> fact[MAXV+5], mult[MAXV+5];
bitset<MAXV+5> pow_valid; int pbuc[MAXV+5];
bitset<MAXV+5> a[MAXN+5];
int main() {
	FOR(i,1,MAXV) pow_valid[i] = 1;
	FOR(i,2,MAXV) {
		if( i * i > MAXV ) break;
		FOR(k,1,MAXV/i/i) pow_valid[k*i*i] = 0;
	}
	pbuc[0] = 0; FOR(i,1,MAXV) if( pow_valid[i] ) pbuc[++pbuc[0]] = i;
	FOR(i,1,MAXV) {
		FOR(k,1,MAXV/i) fact[k*i][i] = 1;
		FOR(j,1,pbuc[0]) {
			if( pbuc[j] * i > MAXV ) break;
			mult[i][pbuc[j]*i] = 1;
		}
	}
	scanf("%d %d", &n, &q);
	while( q-- ) {
		int opt; scanf("%d", &opt);
		switch(opt) {
			int x, y, z, v;
			case 1:
				scanf("%d %d", &x, &v);
				a[x] = fact[v];
				break;
			case 2:
				scanf("%d %d %d", &x, &y, &z);
				a[x] = a[y] ^ a[z];
				break;
			case 3:
				scanf("%d %d %d", &x, &y, &z);
				a[x] = a[y] & a[z];
				break;
			case 4:
				scanf("%d%d", &x, &v);
				printf("%d", (a[x]&mult[v]).count()%2);
				break;
		}
	}
	return 0;
}