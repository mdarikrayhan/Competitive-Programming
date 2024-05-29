#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
string s;

int n;

void solve()
{
	cin>>n;
	cin>>s;
	int r1=0,b1=0;
	int r2=0,b2=0;
	for(int i=0;i<n;i++)
	{
		if(i%2!=0)
		{
			if(s[i]=='r') r1++;
			else b1++;
		}
		else
		{
			if(s[i]=='r') r2++;
			else b2++;
		}
	}
	
	int sum1=min(r1,b2)+abs(r1-b2);
	int sum2=min(r2,b1)+abs(r2-b1);
	cout<<min(sum1,sum2)<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	int T=1;
	while(T--)
	{
		solve();
	}
	
	return 0;
}

 			  		  	 		    		  	  	