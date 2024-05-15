// LUOGU_RID: 158838379
#include<bits/stdc++.h>
using namespace std;
string s;
int a,b;
int main()
{	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='-')
			a++;
		else
			b++;	
	}
	if(b==0)
		cout<<"YES";
	else if(a%b==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
} 