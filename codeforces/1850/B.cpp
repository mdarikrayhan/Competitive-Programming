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
		long long n;
		cin >> n;
		long long mn = -1;
		long long ind;
		for (int i = 0; i < n; i++)
		{
			long long a, b;
			cin >> a >> b;
			if (a <= 10)
			{
				if (b > mn)
				{
					mn = b;
					ind = i + 1;
			 }
		   }

		}
		cout << ind << endl;
	}
}