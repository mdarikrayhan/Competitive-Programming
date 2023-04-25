#include<bits/stdc++.h>
using namespace std;
int n;
string s,t,ans;
//
int main()
{
	cin>>n>>s;
	ans=s;
	for(int i=1;i<=30;i++)
	{
		t=s;
		for(int j=i;j<n;j++)
			if(s[j-i]=='1')
				t[j]='1';
		if(t>ans)
			ans=t;
	}
	int cnt=0;
	while(ans[cnt]=='0'&&cnt<n-1)
		cnt++;
	cout<<ans.substr(cnt);
	return 0;
}
 			 	 	    			 		       	 		