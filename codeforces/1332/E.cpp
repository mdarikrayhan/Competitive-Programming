// Time: 22-05-2024 12:49:11
// Problem: E. Height All the Same
// Contest: Codeforces - Codeforces Round 630 (Div. 2)
// URL: https://codeforces.com/contest/1332/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms


/********************* بسم الله الرحمن الرحيم ***********************/
 /******************** ٱلْحَمْدُ لِلَّٰهِ رَبِّ ٱلْعَالَمِينَ *************************/
/******************* Prophet Muhammad صلى الله عليه وسلم ************/
   /*********************** وَقُل رَّبِّ زِدْنِي عِلْمًا **************************/

#ifdef ONLINE_JUDGE
	#pragma GCC optimize("Ofast")
	#pragma GCC optimize("O3,unroll-loops")
	#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#else

#endif

// #include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define in binary_search
#define ll long long
#define ld long double
#define Hey ios::sync_with_stdio(false);
#define Welcome cin.tie(NULL), cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;

int power(int a,int b)
{
	a%=mod;
	int ans=1,x=a;
	while (b)
	{
		if (b&1)
			ans*=x,ans%=mod;
		x*=x;
		x%=mod;
		b>>=1;
	}
	return ans;
}

void solve()
{
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	r++;
	if (n*m%2)
		cout<<power(r-l,n*m)<<endl;
	else
	{
		if (l%2!=r%2)
		{
			if (l+1==r)
			{
				cout<<1<<endl;
				return;
			}
			int a=(r-l)/2,b=r-l-a;
			int c=b*power(a,mod-2)%mod;
			int ans=power(c-1,n*m)+power(c+1,n*m);
			ans*=power(2,mod-2);
			ans%=mod;
			cout<<ans*power(a,n*m)%mod<<endl;
		}
		else
			cout<<power(2,n*m-1)*power((r-l)/2,n*m)%mod<<endl;
	}
}

signed main()
{
	Hey! Welcome // S'up
	
	int t = 1;
	cout<<fixed<<setprecision(20);
	while (t--)
		solve();
	
	return 0;
}