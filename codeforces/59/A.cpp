#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;
int main()//小写islower 大写isupper
{
	string s;
	int flag1 = 0;
	int flag2 = 0;
	int Max=0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (islower(s[i]))
		{
			flag1++;
		}
		else if (isupper(s[i]))
		{
			flag2++;
		}
	}
	Max = max(flag1, flag2);
	if (Max == flag1)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (isupper(s[i]))
			{
				s[i] += 32;
			}
		}
	}
	else if(Max==flag2)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (islower(s[i]))
			{
				s[i] -= 32;
			}
		}
	}
	cout << s;
}