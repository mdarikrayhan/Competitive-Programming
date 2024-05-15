#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

map<ll,ll> mp;

const ll mod = 1e9 + 7;

ll a[N],b[N];

bool check(string z)
{
	for(int i = 0,j = z.size() - 1;i < j;i++,j--)
	{
		if(z[i] != z[j]) return false;
	}
	
	return true;
}

void solve()
{
	string s;
	
	cin>>s;
	
	if(!check(s)) cout<<s<<endl;
	else
	{
		int u = 1;
		for(int i = 0 ; i  < (s.size() - 1) / 2;i++)
		{
			if(s[i] != s[i + 1])
			{
				u = 0;
				swap(s[i],s[i + 1]);
				break;
			}
		}
		if(u == 1) cout<<"-1"<<endl;
		else cout<<s<<endl;
	}
} 

int main()
{

	int t;
	
	scanf("%d",&t);
	
	while(t--)
	{
		solve();
	}
}

