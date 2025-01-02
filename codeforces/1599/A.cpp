// LUOGU_RID: 158289059
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],lft=0,rht=0;
bool res=true;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	cin>>s;
	k=1;
	for(i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1])
		{
			k++;
		}
	}
	j=n-k;
	reverse(a,a+j);
	k=0;
	for(i=0;i<n;i++)
	{
		if(i==0||s[i]!=s[i-1])
		{
			cout<<a[j]<<" "<<s[i]<<endl;
			if(s[i]=='L')
			{
				lft+=a[j];
			}
			else
			{
				rht+=a[j];
			}
			j++;
		}
		else
		{
			cout<<a[k]<<" ";
			if(s[i]=='L')
			{
				if(lft>rht+a[k])
				{
					cout<<"R\n";
					rht+=a[k];
				}
				else
				{
					cout<<"L\n";
					lft+=a[k];
				}
			}
			else
			{
				if(rht>lft+a[k])
				{
					cout<<"L\n";
					lft+=a[k];
				}
				else
				{
					cout<<"R\n";
					rht+=a[k];
				}
			}
			k++;
		}
	}
	return 0;
}