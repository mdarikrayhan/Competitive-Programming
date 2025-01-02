// <xy man> //
/*
---"Blessed Is He Who In The Name Of Charity && Good Will Shepherds----
--------------The Weak Through The Valley Of Darkness"-----------------
---------------Jules Winnfield - Pulp Fiction (1994)-------------------
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define Boost ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
using namespace __gnu_pbds;
template<class T>
using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void sudo(char *in = NULL, char *out = NULL)
{
	Boost;

	if (in)
		freopen(in, "r", stdin);

	if (out)
		freopen(out, "w", stdout);
}
long long nCr(long long n, long long r)
{
	long long res = 1;

	for (long long i = 1; i < r; ++i, --n)
		res *= n;

	return (res / tgamma(r + 1)) * n;
}
void solve()
{
	long long n;
	cin >> n;

	cout << nCr(n, 5) + nCr(n, 6) + nCr(n, 7);
}
int main()
{
	sudo();

	long long tc = 1;
	// cin >> tc;
	while (tc--)
	{
		solve();

		cout << (tc ? "\n" : "");
	}

	return 0;
}