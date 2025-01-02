//Author: Kevin
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned ll
#define pb emplace_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int n,m;
int a[3030];
char ans[3030][3030];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	int sum=accumulate(a+1,a+m+1,0);
	int val=n*(n-1)-sum;
	for(int i=m+1;i<=n;i++)
		a[i]=val/(n-m);
	if(n!=m)
		for(int i=0;i<val%(n-m);i++)
			a[m+i+1]++;
	for(int i=1;i<n;i++)
		if(a[i]<a[i+1])
			die("no");
	if(accumulate(a+1,a+n+1,0)!=n*(n-1))
		die("no");
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)
	{
		sum1+=a[i];
		sum2+=(n+n-i-i);
		if(sum1>sum2) die("no");
	}
	cout<<"yes\n";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]="LX"[i==j];
	for(int i=1;i<=n;i++)
	{
		vector<pii> vec;
		for(int j=i+1;j<=n;j++)
		{
			vec.pb(a[j],j);
			vec.pb(a[j]-1,j);
		}
		srt(vec);
		for(int x=0;x<a[i];x++)
			ans[i][vec[x].second]='W';
		for(int x=a[i];x<sz(vec);x++)
		{
			a[vec[x].second]--;
			ans[vec[x].second][i]='W';
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(ans[i][j]=='W'&&ans[j][i]=='W')
				ans[i][j]=ans[j][i]='D';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ans[i][j];
		cout<<'\n';
	}
	return 0;
}