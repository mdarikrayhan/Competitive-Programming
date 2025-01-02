#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

map<ll,ll> mp;

const ll mod = 1e9 + 7;

ll a[N],b[N];

void solve()
{
	int n;
	
	cin>>n;
	
	for(int i = 1; i <= n;i++)
	{
		cin>>a[i];
	}
	
	for(int i = 1; i <= n;i++)
	{
		cin>>b[i];
	}
	
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + n);
	
	int f = 1;
	
	for(int i = 1;i <= n;i++)
	{
		if(a[i] + 1 < b[i])
		{
			f = 0;
		}
		
		if(a[i] > b[i])
		{
			f = 0;
		}
	}
	
	if(f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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


