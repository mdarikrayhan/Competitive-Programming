#include <iostream>
#include <ctype.h>
using namespace std;

int n;
string s, ans;

string work(string s)
{
	while(s.size() < 4) s = '0' + s;
	return s;
}

int main()
{
	cin >> n;
	while(n--)
	{
		cin >> s, ans = "";
		int cnt = 0, now = 0;
		for(int i = 0; i <= s.size() - 1; i++)
			if(s[i] == ':')
				cnt++;
		if(s.size() == 2) cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
		else
		{
			for(int i = 0; i <= s.size() - 1; i++)
				if(s[i] == ':')
					if(i == 0)
					{
						i++, cnt = 9 - cnt;
						for(int j = 1; j <= cnt; j++)
							ans += "0000:";
					}
					else
					{
						if(i == s.size() - 1) cnt = 9 - cnt;
						else cnt = 8 - cnt;
						for(int j = 1; j <= cnt; j++)
							ans += "0000:";
						if(i == 0) i++;
					}
				else
				{
					string now = "";
					now += s[i];
					while(i <= s.size() - 2 && s[i + 1] != ':') now += s[++i];
					now = work(now), ans += now + ':', i++;
				}
			cout << ans.substr(0, ans.size() - 1) << endl;
		}
	}

	return 0;
}
   				 		  		 	 						 					 	