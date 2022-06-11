#import<bits/stdc++.h>
using namespace std;
int i,t,x,y;
string s;
main()
{
	for(cin>>t;t--;)
	{
		cin>>s;
		for(i=x=y=0;s[i];i++)s[i]%7?x++:y++;
		cout<<(min(x,y)%2?"DA":"NET")<<endl;
	}
}