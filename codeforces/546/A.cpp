#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int k, n, w;
	cin >> k >> n >> w;
	int sum = 0;
	for (int i = 1; i <= w; i++)
	{
		sum += i * k;
	}
	int temp;
	if (sum <= n)
	{
		cout << "0";
		return 0;
	}
	temp = sum - n;
	cout << temp;
	return 0;
}