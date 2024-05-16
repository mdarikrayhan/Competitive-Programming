// LUOGU_RID: 159046752
// Problem: B. Nezzar and Lucky Number
// Contest: Codeforces - Codeforces Round 698 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1478/B
// Memory Limit: 512 MB
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
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> PII;
const int N=4e6+10;



void solve()
{
	int q,d; cin>>q>>d;
	
	while(q--)
	{
		int x; cin>>x;
		if(x>=10*d)
		{
			cout<<"YES\n";
			continue;
		}
		
		bool st=false;
		while(x>0)
		{
			if( x%10==d )
			{
				st=true;
				break;
			}
			x-=d;
		}
		if(st)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
}

signed main()
{
	int t=1; //std::cin>>t;
	scanf("%lld",&t);
	while(t--) solve(); 
	
	return 0;
}
