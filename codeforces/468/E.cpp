// LUOGU_RID: 158281976
#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 1 << 6, M = 1e5 + 7, mod = 1e9 + 7;
int n, m, a[N][N], fac[M], ns;
int x[N], y[N], w[N];
int arra[N], atot, arrb[N], btot;
int cnta[N], cntb[N];
unordered_map < ll, int > mp[N], cp[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(a, -1, sizeof(a));
	fac[0] = 1;
	L(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	L(i, 1, m) {
		cin >> x[i] >> y[i] >> w[i], (w[i] += mod - 1) %= mod;
		arra[++atot] = x[i];
		arrb[++btot] = y[i];
	}
	sort(arra + 1, arra + atot + 1), atot = unique(arra + 1, arra + atot + 1) - arra - 1;
	sort(arrb + 1, arrb + btot + 1), btot = unique(arrb + 1, arrb + btot + 1) - arrb - 1;
	L(i, 1, m) 
		x[i] = lower_bound (arra + 1, arra + atot + 1, x[i]) - arra, y[i] = lower_bound(arrb + 1, arrb + btot + 1, y[i]) - arrb, 
		a[x[i]][y[i]] = w[i], ++cnta[x[i]], ++cntb[y[i]];
	mp[0][0] += 1;
	while (1) {
		int o = -1;
		L(i, 1, btot) if(cntb[i] && (o == -1 || cntb[o] > cntb[i])) o = i;
		if(o == -1) 
			break ;
		L(i, 1, atot) if(a[i][o] != -1 && cnta[i]) {
			cnta[i] = 0;
			ll cle = ((1LL << btot) - 1) << 1, msk = 0;
			vi S;
			L(j, 1, btot) if(a[i][j] != -1) {
				S.push_back(j);
				cntb[j] -= 1, msk |= 1LL << j;
				if(!cntb[j]) cle ^= 1LL << j;
			}
			L(z, 0, m) 
				for (auto u : mp[z]) {
					(cp[z][u.first & cle] += u.second) %= mod;
					for (const int &t : S) if(!(u.first >> t & 1)) 
						(cp[z + 1][(u.first | (1LL << t)) & cle] += (ll) u.second * a[i][t] % mod) %= mod; 
				}
			L(z, 0, m) swap (mp[z], cp[z]), cp[z].clear ();
		}
	}
	L(z, 0, m) for (auto u : mp[z]) (ns += (ll) u.second * fac[n - z] % mod) %= mod; 
	cout << ns << '\n';
	return 0;
} 
//123123123