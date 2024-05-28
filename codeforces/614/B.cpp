#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ull = unsigned long long;
using ll = long long;


//-1 -2 -3 -4
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int cnt = 0;string s, un="1";
	while (n--)
	{
		cin >> s;
		if (s[0] == '0')  return cout << 0, 0;
		bool beat = s[0] =='1';
		for (int i = 1; i < s.size(); i++)
		{
			beat &= s[i] == '0';
		}
		if (beat)cnt += s.size() - 1;
		else
			un = s;
	}
	cout << un;
	for (int i = 0; i < cnt; i++)cout << 0;
}