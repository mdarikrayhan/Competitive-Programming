#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

struct FFT{
	using cd = complex<double>;
	const double PI = acos(-1);

	void fft(vector<cd> & a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * PI / len * (invert ? -1 : 1);
			cd wlen(cos(ang), sin(ang));
			for (int i = 0; i < n; i += len) {
				cd w(1);
				for (int j = 0; j < len / 2; j++) {
					cd u = a[i+j], v = a[i+j+len/2] * w;
					a[i+j] = u + v;
					a[i+j+len/2] = u - v;
					w *= wlen;
				}
			}
		}

		if (invert) {
			for (cd & x : a)
				x /= n;
		}
	}

	vector<int> multiply(vector<int> const& a, vector<int> const& b) {
		vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		fa.resize(n);
		fb.resize(n);

		fft(fa, false);
		fft(fb, false);
		for (int i = 0; i < n; i++)
			fa[i] *= fb[i];
		fft(fa, true);

		vector<int> result(n);
		for (int i = 0; i < n; i++)
			result[i] = round(fa[i].real());
		return result;
	}
};

struct DSU{
	vector<int> par, sz;
	DSU(int n){
		par.resize(n);
		iota(par.begin(), par.end(), 0);
		sz.resize(n);	
	}


	int Find(int u){
		return u = par[u] == u ? u : Find(par[u]);
	}

	void Union(int u, int v){
		u = Find(u);	
		v = Find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}	

};

const int mxN = 125000;
int f[mxN][6][6];

void sieunhan283(){
	string s, t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();
	
	for(int i = 0; i < m / 2; ++i)
		swap(t[i], t[m - i - 1]);

	FFT fft;

	for(int i = 0; i < 6; ++i) for(int j = 0; j < 6; ++j){
		if(i == j) continue;
		vector<int> a(n), b(m);
		for(int k = 0; k < n; ++k)
			a[k] = s[k] - 'a' == i;
		for(int k = 0; k < m; ++k)
			b[k] = t[k] - 'a' == j;

		vector<int> conv = fft.multiply(a, b);
		for(int k = m - 1; k < n; ++k)
			f[k - m + 1][i][j] = conv[k] > 0;
	}

	for(int k = 0; k < n - m + 1; ++k){
		DSU dsu(6);
		set<int> st;
	   	for(int i = 0; i < 6; ++i) for(int j = 0; j < 6; ++j){	
			if(i == j) continue;
			if(f[k][i][j]) 
				dsu.Union(i, j), st.insert(i), st.insert(j);
		}
		int cnt = 0;
		for(int i = 0; i < 6; ++i)
			if(st.find(i) != st.end() && dsu.par[i] == i)
				++cnt;

		cout << (int) st.size() - cnt << ' ';
	}
	cout << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		sieunhan283();
		eprintf("----------------------\n");
	}
	eprintf("Output:\n");
	write_output();	

	return 0;
}

