#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0, depth = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; ++i)
		if (str[i] == '(')
		{
			cout << depth % 2;
			++depth;
		}
		else if (str[i] == ')')
		{
			--depth;
			cout << depth % 2;
		}
	cout << '\n';
	return 0;
}
