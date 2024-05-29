// LUOGU_RID: 160400445
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
const int maxn = 1e6 + 10;
const int mod = 998244353, G = 3;

namespace IO {
void openfile() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
}
void Min(int& x, int y) {
	x = (x < y) ? x : y;
}
void Max(int& x, int y) {
	x = (x > y) ? x : y;
}
int add(int x, int y) {
	return (x + y) >= mod ? (x + y - mod) : (x + y);
}
int sub(int x, int y) {
	return (x < y) ? (x + mod - y) : (x - y);
}
void Add(int& x, int y) {
	x = (x + y) >= mod ? (x + y - mod) : (x + y);
}
void Sub(int& x, int y) {
	x = (x < y) ? (x - y + mod) : (x - y);
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int& x, int y) {
	x = 1ll * x * y % mod;
}
int qpow(int x, int y = mod - 2) {
	int ans = 1;
	while (y > 0) {
		if (y & 1)
			ans = 1ll * x * ans % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return ans;
}
inline int read() {
	int x = 0, f = 0;
	char c = getchar();
	while (!isdigit(c))
		f |= c == '-', c = getchar();
	while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	if (f)
		x = -x;
	return x;
}
}  // namespace IO
using namespace IO;

const int invG = qpow(G);
int tr[maxn << 1], tf;
ull invn;
void tpre(int n) {
	if (n == tf)
		return;
	invn = qpow(n), tf = n;
	for (int i = 0; i < n; i++)
		tr[i] = ((tr[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0));
}
void NTT(int* g, int op, int n) {
	tpre(n);
	static ull f[maxn << 1], w[maxn << 1];
	w[0] = 1;
	for (int i = 0; i < n; i++)
		f[i] = g[tr[i]];
	for (int len = 1; len < n; len <<= 1) {
		ull tG = qpow(op ? G : invG, (mod - 1) / (len << 1));
		for (int i = 1; i < len; i++)
			w[i] = mul(w[i - 1], tG);
		for (int k = 0; k < n; k += (len << 1))
			for (int p = 0; p < len; p++) {
				int tt = w[p] * f[k | p | len] % mod;
				f[k | p | len] = f[k | p] + mod - tt;
				f[k | p] += tt;
			}
		if (len == (1 << 10))
			for (int i = 0; i < n; i++)
				f[i] %= mod;
	}
	if (!op)
		for (int i = 0; i < n; i++)
			g[i] = f[i] % mod * invn % mod;
	else
		for (int i = 0; i < n; i++)
			g[i] = f[i] % mod;
}
void px(int* f, int* g, int n) {
	for (int i = 0; i < n; i++)
		f[i] = 1ll * f[i] * g[i] % mod;
}

#define Poly vector<int>
Poly operator+(const Poly& A, const Poly& B) {
	Poly C = A;
	C.resize(max(A.size(), B.size()));
	for (int i = 0; i < B.size(); i++)
		Add(C[i], B[i]);
	return C;
}
Poly operator-(const Poly& A, const Poly& B) {
	Poly C = A;
	C.resize(max(A.size(), B.size()));
	for (int i = 0; i < B.size(); i++)
		Sub(C[i], B[i]);
	return C;
}
Poly operator*(const int x, const Poly& A) {
	Poly C;
	C.resize(A.size());
	for (int i = 0; i < A.size(); i++)
		C[i] = mul(x, A[i]);
	return C;
}
int lim;
Poly operator*(const Poly& A, const Poly& B) {
	static int a[maxn << 1], b[maxn << 1];
	cpy(a, &A[0], A.size()), cpy(b, &B[0], B.size());
	Poly C;
	C.resize(min(lim, (int)(A.size() + B.size() - 1)));
	int n = 1;
	for (; n < (A.size() + B.size() - 1); n <<= 1)
		;
	NTT(a, 1, n), NTT(b, 1, n);
	px(a, b, n), NTT(a, 0, n);
	cpy(&C[0], a, C.size());
	clr(a, n), clr(b, n);
	return C;
}
void pinv(const Poly& A, Poly& B, int n) {
	if (n == 1)
		B.push_back(qpow(A[0]));
	else if (n & 1) {
		pinv(A, B, --n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			Add(ans, mul(A[n - i], B[i]));
		Mul(ans, qpow(mod - A[0]));
		B.push_back(ans);
		// F[n] = -1/G[0]*(sum_{i=1}^{n-1}F[i]G[n-i]),G(A),F(B)
	}
	else {
		pinv(A, B, n / 2);
		Poly sa;
		sa.resize(n);
		cpy(&sa[0], &A[0], n);
		B = 2 * B - B * B * sa;
		B.resize(n);
		// R(x) = 2R*(x) - R*(x)^2F(x)(mod x^n)
	}
}
Poly pinv(const Poly& A) {
	Poly C;
	pinv(A, C, A.size());
	return C;
}

int inv[maxn], fac[maxn], ifac[maxn];
void Init() {
	fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for (int i = 2; i <= lim; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = mul(mod - mod / i, inv[mod % i]);
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
}
Poly dao(const Poly& A) {
	Poly C;
	C.resize(A.size() - 1);
	for (int i = 0; i < C.size(); i++)
		C[i] = mul(i + 1, A[i + 1]);
	return C;
}
Poly ints(const Poly& A) {
	Poly C;
	C.resize(A.size());
	for (int i = A.size() - 1; i; i--)
		C[i] = mul(inv[i], A[i - 1]);
	C[0] = 0;
	return C;
}
Poly ln(const Poly& A) {
	return ints(dao(A) * pinv(A));
}
void pexp(const Poly& A, Poly& B, int n) {
	if (n == 1)
		B.push_back(1);
	else if (n & 1) {
		pexp(A, B, n - 1), n -= 2;
		int ans = 0;
		for (int i = 0; i <= n; i++)
			Add(ans, 1ll * (i + 1) * A[i + 1] % mod * B[n - i] % mod);
		B.push_back(1ll * ans * inv[n + 1] % mod);
	}
	else {
		pexp(A, B, n / 2);
		Poly lnB = B;
		lnB.resize(n), lnB = ln(lnB);
		for (int i = 0; i < lnB.size(); i++)
			lnB[i] = sub(A[i], lnB[i]);
		lnB[0]++;
		B = lnB * B;
		B.resize(n);
	}
}
Poly pexp(const Poly& A) {
	Poly C;
	pexp(A, C, A.size());
	return C;
}
Poly qpow(const Poly& A, int k) {
	Poly B = ln(A);
	k %= (mod - 1);
	for (int i = 0; i < A.size(); i++)
		Mul(B[i], k);
	B = pexp(B);
	return B;
}
int n, k, ans;
signed main() {
	openfile();
	Poly F, G, S, C;
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k, lim = maxn - 1, Init();
	for (int i = 0, num = 1; i <= k; i++) {
		F.push_back((i & 1) ? sub(0, ifac[i]) : ifac[i]);
		G.push_back(mul(qpow(i, k), ifac[i]));
		C.push_back(num), Mul(num, mul(n - i, inv[i + 1]));
	}
	S = F * G;
	for (int j = 0; j <= k; j++) {
		Add(ans, 1ll * S[j] * C[j] % mod * fac[j] % mod * qpow(n + 1, n - j) % mod);
	}
	cout << ans << endl;
	return 0;
}
