#include<iostream>
#include<iomanip>
#include<sstream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<map>
#include<numeric>
#include<set>
#include <vector>
#define cancelo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	cancelo;
	long long t;
	cin >> t;
	while (t--)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a + b >= 10 or a + c >= 10 or b + c >= 10)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}