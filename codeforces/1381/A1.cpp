// Problem: A1. Prefix Flip (Easy Version)
// Contest: Codeforces - Codeforces Round #658 (Div. 1)
// URL: https://codeforces.com/contest/1381/problem/A1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long 

using namespace std;

const int N = 4000;

char a[N];
char b[N];
int ans[N];
char temp[N];

void solve()
{
	int n;
	cin>>n;
	
	for (int i = 1 ; i <= n ; ++ i)cin>>a[i];
	for (int i = 1 ; i <= n ; ++ i)cin>>b[i];
	
	int cnt = 0;
	
	for (int j = n ; j >= 1 ; j --)
		if (a[j] == b[j])continue;
		else
		{
			if (a[1] == b[j])
			{
				ans[cnt ++] = 1;
				if (a[1] == '1')a[1] = '0';
				else a[1] = '1';
			}
			
			ans[cnt ++] = j;
			for (int i = 1 ; i <= j ; i ++)
				if (a[i] == '1')a[i] = '0';
				else a[i] = '1';
			//00100
			
			for (int i = 1 ; i <= j ; i ++)
				temp[i] = a[i];
			
			for (int i = j ; i >= 1 ; i --)
				a[i] = temp[j - i + 1];	
				
		}
	cout<<cnt<<" ";
	for (int i = 0 ; i < cnt ; i ++)
		cout<<ans[i]<<" ";
	puts("");		
	
}

signed main()
{
	int T;
	cin>>T;
	while(T --)
	{
		solve();
	}
	return 0;
} 
