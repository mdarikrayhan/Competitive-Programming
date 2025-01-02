#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using ll=long long;

ll a,b,c,n;
string s;


void solve()
{
	char  q[1000];
	cin>>n>>a>>b>>c>>s;
	for(int i=0;i<n;i++)
	{
		q[i]='0';
	}
	
	
	ll cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R')
		{
			if(b) 
			{
			   q[i]='P';
			   cnt++;
			   b--;
			}
			
		}
		if(s[i]=='P')
		{
			if(c){
				cnt++;
				q[i]='S';
				c--;
			}
		}
		if(s[i]=='S')
		{
			if(a) 
			{
				cnt++;
				q[i]='R';
				a--;
			}
		}
	}

	if(cnt<(n+1)/2)
	{
		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		if(q[i]!='P'&&q[i]!='R'&&q[i]!='S')
		{
			if(a) q[i]='R',a--;
			else if(b) q[i]='P',b--;
			else if(c) q[i]='S',c--;
		}
	}

	for(int i=0;i<n;i++) cout<<q[i];
	cout<<'\n';

 
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}

