// Problem: B. Arrays Sum
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/problemset/problem/1408/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int a[N];

void solve()
{
	int n,k; cin>>n>>k;
	set<int>s;
	for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]);
	
	if(k==1)
	{
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1]) 
			{
				cout<<-1<<endl;
				return ;
			}
		cout<<1<<endl;
	}
	else 
	{
		int res=1;
		int n=s.size()-k;
		if(n<0)
		{
			cout<<1<<endl;
			return;
		}
		k--;
		cout<< n/k+(n%k!=0)+1<<endl; 
	}
	
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 		//  scanf("%lld",&t);
	cin>>t;
	
	while(t--) solve(); 
	
	return 0;
}

		 	 		   		 		 	    		 	 		