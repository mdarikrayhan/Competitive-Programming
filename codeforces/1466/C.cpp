#include<bits/stdc++.h>
using namespace std;
int t,A;
string s;
int main()
{
	cin>>t;
	while(cin>>s)
	{
		A=0;
		for(int i=1;i<s.size();i++)
			if(s[i-1]==s[i]||s[i-2]==s[i])
				A++,s[i]=0;
		cout<<A<<'\n';
	}
}