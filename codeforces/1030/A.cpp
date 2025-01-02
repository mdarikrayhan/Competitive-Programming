#include<iostream>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int one = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			one++;
	}

	if (one)
		cout << "HARD" << endl;
	else
		cout << "EASY" << endl;
}