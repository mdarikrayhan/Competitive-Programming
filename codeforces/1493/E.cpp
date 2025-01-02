// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef		long long int			ll;
typedef		long double				ld;
typedef		pair<int, int>			pii;
typedef		pair<ll, ll>			pll;
typedef		complex<ld>				cld;

#define		all(x)					(x).begin(),(x).end()
#define		len(x)					((ll) (x).size())
#define		F						first
#define		S						second
#define		X						real()
#define		Y						imag()
#define		pb						push_back
#define		sep						' '
#define		endl					'\n'
#define		Mp						make_pair
#define		kill(x)					cout << x << '\n', exit(0)
#define		set_dec(x)				cout << fixed << setprecision(x);
#define		file_io(x,y)			freopen(x, "r", stdin); freopen(y, "w", stdout);

const int maxn = 2e6 + 7;
int n; string A, B, res;

string addx(string s) {
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			s[i] = '1';
			break;
		}
		else s[i] = '0';
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	cin >> A >> B;
	
	if (B == "0") {
		res = "0"; kill(res);
	}
	else if (A[0] != B[0]) {
		for (int i = 0; i < n; i++) res += B[0];
		kill(res);
	}
	
	int R = 0;
	while (A != B && R < 2) {
		A = addx(A); R++;
	}
	
	res = B;
	if (R >= 2) res[n - 1] = '1';
	cout << res << endl;
	
	return 0;
}
