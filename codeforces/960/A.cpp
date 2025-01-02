// LUOGU_RID: 158813883
#include<bits/stdc++.h>
using namespace std;
string a;
int st[114],l;

int main()
{
	cin>>a;
	while(a[l])
	{
		st[a[l]-'a']++;
		if(a[l]<a[l-1]) 
		{
			cout<<"NO";return 0;
		}
		l++;
	}
	if(st[0]==0||st[1]==0)
	  cout<<"NO";
	else if(st[2]==st[0]||st[2]==st[1])
	  cout<<"YES";
	else
	  cout<<"NO";  
	
	
	return 0;
}