#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int flag1, flag2;
	flag1 = 0;
	flag2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A') 
		{
			flag1++;
		}
		else if(s[i]=='D')
		{
			flag2++;
		}
	}
	if (flag1 == flag2)
	{
		cout << "Friendship";
		return 0;
	}
	int Man;
	Man = max(flag1, flag2);
	if (Man == flag1)
	{
		cout << "Anton";
		return 0;
	}
	else if (Man == flag2)
	{
		cout << "Danik";
		return 0;
	}
}