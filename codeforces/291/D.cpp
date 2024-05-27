#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,k,a[N],sum[N],t[N];
inline int get_(int x,int expt)
{
	int l=1,r=n,ans=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]+x<=expt)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
//		cout<<"doing"<<l<<" "<<r<<"\n";
	}
	return ans;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		a[i]=1;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int tmp=get_(a[j],n-j);
			cout<<tmp<<" ";
//			a[j]+=a[tmp];
			t[j]=a[tmp];
		}
		for(int j=1;j<=n;j++)
		{
			a[j]+=t[j];
		}
//		cout<<"\narr:";
//		for(int j=1;j<=n;j++)
//		{
//			cout<<a[j]<<" ";
//		}
		cout<<"\n";
	}
	return 0;
}
/*
1 1 1 1 0
4 4 4 5 5
->
2 2 2 1 0
3 4 5 5 5
->
4 3 2 1 0
*/
/*
1 1 1 1 1 1 0
6 6 6 6 6 7 7
->
2 2 2 2 2 1 0
5 5 5 6 7 7 7
->
4 4 4 3 2 1 0
5 6 7 7 7 7 7
->
6 5 4 3 2 1 0
*/
/*
1 1 1 1 1 1 1 1 |1 0       0
9 9 9 9 9 9 9 9 10 10
->
2 2 2 2 2 2 2 |2 1 0  +1     1
8 8 8 8 8 8 9 10 10 10
->
4 4 4 4 4 |4 3 2 1 0  +2       3
6 6 7 8 9 10 10 10 10 10
->
8 |8 7 6 5 4 3 2 1 0 +4         7 
9 10 10 10 10 10 10 10 10 10
->
9 8 7 6 5 4 3 2 1 0 
*/
	   	    	  		      			  		