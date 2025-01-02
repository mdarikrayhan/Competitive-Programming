#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string ansl;
	string ansr;
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	int n = s.length();
	deque<char> a,b;
	for(int i=0;i<(n+1)/2;i++)
	{
		a.pb(s[i]);
	}
	for(int i=0;i<n/2;i++)
	{
		b.pb(t[i]);
	}
	bool mode=0;
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			if(!a.empty()&&a[0]>=b[0])
			{
				mode=1;
			}
			if(mode)
			{
				ansr+=b.back();
				b.pop_back();
			}
			else
			{
				ansl+=b[0];
				b.pop_front();
			}
		}
		else //P1's turn
		{
			if(!b.empty()&&a[0]>=b[0])
			{
				mode=1;
			}
			if(mode)
			{
				ansr+=a.back();
				a.pop_back();
			}
			else
			{
				ansl+=a[0];
				a.pop_front();
			}
		}
	}
	reverse(ansr.begin(),ansr.end());
	ansl+=ansr;
	cout<<ansl<<'\n';
}