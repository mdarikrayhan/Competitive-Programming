#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		int ans=1e9;
		for(char c='a';c<='z';c++)
		{
			int now=0;
			for(int i=0;i<s.size();)
			{
				if(s[i]==c)
				{
					i++;
				}
				else
				{
					int len=0;
					while(i<s.size()&&s[i]!=c)i++,len++;
					now=max(now,32-__builtin_clz(len));
				}
			}
			ans=min(ans,now);
		}
		cout<<ans<<"\n";
	}
}
