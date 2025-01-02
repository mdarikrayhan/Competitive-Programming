#include <bits/stdc++.h>
#define int long long
#define MAX_SIZE   105
#define all(v) v.begin() , v.end()
#define all2(v,i,n) v+i , v + i + n
#define rep(i,a) for (int i = 0 ; i < a ; i++)
#define repd(i,a) for (int i = a -1 ; i >= 0 ; i--)
#define sz(v) v.size()
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define MASK(i) (1LL <<(i))
#define bit(n,i) ((n >> i) & 1)
#define set_on(x,i) ((x) | MASK(i))
#define set_off(x,i)((x) & ~MASK(i))
#define el '\n'
#define sp ' '
#define FA forever alone
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}
using namespace std;
const int maxn = 400;
const int MOD = 1e9 + 7;
int n , m , a[maxn];
void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void sub(int &x, const int &y) {
    x -= y;
    if (x < 0) x += MOD;
}
struct Matrix {
	int m, n; // m = số hàng, n = số cột
	int d[MAX_SIZE][MAX_SIZE];

	Matrix(int _m = 0, int _n = 0) {
		m = _m; n = _n;
		memset(d, 0, sizeof d);
	}

	Matrix operator + (const Matrix &a) const { // phép cộng ma trận
		Matrix res(m, n);
		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
			res.d[i][j] = d[i][j] + a.d[i][j];
			if (res.d[i][j] >= MOD) res.d[i][j] -= MOD;
		}

		return res;
	}

	Matrix operator * (const Matrix &a) const { // phép nhân ma trận
		int x = m, y = n, z = a.n;
		Matrix res(x, z);
		for (int i = 0; i < x; i++) for (int j = 0; j < y; j++)
			for (int k = 0; k < z; k++)
				res.d[i][k] = (res.d[i][k] + 1LL * d[i][j] * a.d[j][k]) % MOD;
		return res;
	}

	Matrix operator ^ (long long k) const { // phép luỹ thừa ma trận
		Matrix res(n, n);
		for (int i = 0; i < n; i++) res.d[i][i] = 1;
		Matrix mul = *this;
		while (k > 0) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}
		return res;
	}
};
signed main () {
    cin >> n >> m;
    for (int i = 0; i < n ; i++ ) cin >> a[i];
    Matrix transition(n , n);
    for (int k = 0 ; k < n ; k++ )
        for (int j = 0 ; j < n ; j++ )
            if(__builtin_popcountll(a[j] ^ a[k]) % 3 == 0) transition.d[k][j]++;
    Matrix res(1 , n);
    for (int j = 0 ; j < n ; j++ ) res.d[0][j] = 1;
    res = res * (transition ^ (m - 1));
    int sum = 0;
    for (int j= 0 ; j < n ; j++ ) add(sum , res.d[0][j]);
    cout << sum;
    return (0^0);
}
