#include<iostream>
using namespace std;
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
const int N = 1e5 + 10;
#include<algorithm>
typedef pair<int, int> PII;
typedef pair<char, int> PCI;
#define x first
#define y second
void db(int x) { cout << "debug  " << x << endl; }
int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int e[N], ne[N], idx, h[N];
void add(int a, int b) { e[idx] = b; ne[idx] = h[a]; h[a] = idx++; }
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string a; cin >> a; char b[200];
		for (int i = 0; i < a.size(); i++)b[i] = a[i];
		sort(b, b + a.size());
		if (a.size() == 1)cout << "YES" << endl;
		else
		{
			int pd = 1;
			for (int i = 1; i < a.size(); i++)
			{
				if (b[i] - b[i - 1] != 1) {
					pd = 0; break;
				}
			}
			if (pd)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}