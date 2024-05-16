#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define take(x) for(auto &it :x){cin>>it;}
template<class T, class U> T GCD(T a, U b) { return(!b ? a : GCD(b, a % b)); }
template<class T, class U> T LCM(T a, U b) { return a / GCD(a, b) * b; }

#pragma region Bitwise
#define On(n,k) (n | (1<<k))
#define Off(n,k) (n & ~(1<<k))
#define IsOn(n,k) ((n>>k) & 1)

int clearFromI_To_J(int n, int i, int j) {
	int mask = (-1 << (j + 1)) | (1 << i) - 1;
	return n & mask;
}

bool isPowerOfTwo(int n) {
	return !(n & (n - 1));
}
int flip(int n, int idx) {
	return n ^ (1 << idx);
}

int update(int n, int idx, int val) {
	n = Off(n, idx);
	return (n | (val << idx));
}

int lastZeroToOne(int n) {
	return n | (n + 1);
}

int LastOneToZero(int n) {
	return n & (n - 1);
}

int lastConsecutiveZeroesToOnes(int n) {
	return n | (n - 1);
}

int lastConsecutiveOnesToZeros(int n) {
	return n & (n + 1);
}

int clearLasti_thBits(int n, int i) {
	int mask = (~0) << i;
	int mask1 = -1 << i;
	return n & mask;

}

string getBinary(int x)
{
	string res = "";
	for (int i = 31; i >= 0; i--)
		res += to_string(IsOn(x, i));

	return res;
}

#pragma endregion


vector<ll>PrimeFactorization(ll n)
{
	vector<ll>v;
	for (ll i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			v.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		v.push_back(n);
	return v;
}
bool Is_Prime(ll n)
{
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
vector<ll>GetDivisors_Distinct(ll n)
{
	vector<ll>v;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0) {
			v.push_back(i);
			if (i != n / i)
				v.push_back(n / i);
		}
	}
	return v;
}
vector<ll>GetDivisorsOdd(ll n)
{
	vector<ll>v;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i % 2)
				v.push_back(i);
			if ((n / i) % 2 && n / i != i)
				v.push_back(n / i);
		}
	}
	return v;
}
void solve()
{
	vector<int>v(4);
	take(v);
	sort(v.begin(), v.end());
	if (v[3] == v[0] + v[1] + v[2] || v[3] + v[0] == v[2] + v[1])
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	IOS;
	/*int t;
	cin >> t;
	while (t--)
	{


		cout << '\n';

	}*/
		solve();
}

