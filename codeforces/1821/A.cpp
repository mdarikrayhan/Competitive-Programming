#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> s;
		int res=1;
		if(s[0]=='?') res*=9;
		for(int i=1;i<s.size();i++)
		{
		    if(s[i]=='?') res*=10;
		}
		if(s[0]=='0') res=0;
		cout << res <<endl; 
	}
	
	return 0;
}























































































