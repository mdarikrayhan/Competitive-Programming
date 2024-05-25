#include<bits/stdc++.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define all(s) s.begin(),s.end()
#define xx first
#define yy second
#define inf 0x3f3f3f3f3f3f3f3f
#define N 1000005
#define mod 1000000007//998244353
#define double long double
#define lowbit(x) ((x)&(-x))
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define pll pair<int,int> 
#define __lcm(a,b) (a/__gcd(a,b)*b)
const double pi=acos(-1);
const int P=233333;
const int PP=1313131;
const int mod1=1000001011;
const int mod2=(1ll<<31)-1;
using namespace std;
int arr[N];
int add[N];
pll query(int p,int n)
{
	fflush(stdout);
	cout<<"? ";
	for(int i=1;i<=n;i++)
	{
		cout<<(i==p?2:1)<<" ";
	}
	int x;cin>>x;
	fflush(stdout);
	cout<<"? ";
	for(int i=1;i<=n;i++)
	{
		cout<<(i==p?1:2)<<" ";
	}
	int y;cin>>y;
	fflush(stdout);
	return {x,y};
}
void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) add[i]=0;
	for(int i=n;i;i--)
	{
		pll ret=query(i,n);
		int x=ret.xx,y=ret.yy;
		if(x!=i)
		{
			if(x==0) add[i]=-1;
			else add[i]=x;
		}
		if(y!=i) add[y]=i;
	}
	int now=0,cnt=0;
	while(now!=-1)
	{
		arr[add[now]]=++cnt;
		now=add[now];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
signed main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)
    {
    	solve();
	}
    return 0;
}
/*
1
5
1
2
2
0
0
1
5
4
3
5




*/