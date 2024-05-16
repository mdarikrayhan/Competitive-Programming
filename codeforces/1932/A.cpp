#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int cnt = 0;int ans = 0;
		for(int i = 1;i < n;i++)
		{
			if(s[i]=='@') ans++;
			if(s[i]=='*' && s[i-1]=='*') break;
		}

		cout << ans << endl;
	}
}