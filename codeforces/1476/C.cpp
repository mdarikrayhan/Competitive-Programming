// LUOGU_RID: 159219605
// Problem: C. Longest Simple Cycle
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1476/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<unordered_set>
#include<deque>
#include<bitset>
#include<functional>
#pragma GCC optimize(2) //O(2)
 
const int inf=1e9+5201314;
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);	// NO  devc++
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> PII;
const int N=4e6+10;
 
int a[N],b[N],c[N];
 
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	
	int res=0;
	int sum=0,last=0;
	for(int i=2;i<=n;i++)
	{
		sum=a[i]-1+abs(b[i]-c[i])+2;	//	当前所围成的小循环节；
		if(b[i]==c[i])
		{
			;
		}
		else 		//	 要在 此处取最大，不然不对； 
		{
			sum=max(sum,a[i]-1+2+last-abs(b[i]-c[i]));	//与上一个连起来；
		}
		last=sum;		//	要把 其，最大的值 赋给last，才可以；
		res=max(res,sum);
//不能这样写	sum+= abs(a[i-1]-c[i])+abs(1-b[i])+2 ;   当c[i]==a[i-1],b[i]=1 时，错的；		
		//cout<<res<<endl;
	}
	
	cout<<res<<endl;
}
 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 		//  scanf("%lld",&t);
	cin>>t;
	
	while(t--) solve(); 
	
	return 0;
}