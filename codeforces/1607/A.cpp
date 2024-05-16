#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <stack>
#include <climits>
#include <ctype.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
	string alphabet,word;
	cin >> alphabet >> word;
	map<char, ll> mp;
	for (ll i = 0; i < alphabet.size(); ++i)
	{
		if (!mp.count(alphabet[i])) mp[alphabet[i]] = i;

	}
	ll answer = 0;
	for (ll i = 0; i < word.size() - 1; ++i)
	{
		if (mp.count(word[i]) && mp.count(word[i + 1]))
		{
			answer += abs(mp[word[i]] - mp[word[i+1]]);
		}
	}
	cout << answer << endl;
}

signed main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}