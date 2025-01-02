/*===========moparak===========*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include <iomanip> 
#include<queue>
#include<map>
#include<set>
//#include <bits/stdc++.h>
#define el '\n'
#define fast ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
const int N = 1e5 + 9;
ll v[N];
vector<set<char>>adj; string ans;
vector<int>vis;
void dfs(int node)
{
	ans += (node + 'a'); vis[node] = true;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			dfs(it);
		}
	}
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s; ans = "";
		vis = vector<int>(26);
		adj = vector<set<char>>(26, set<char>());
		if (s.size() == 1)
		{
			yes;
			cout << s[0];
			for (char i = 'a'; i <= 'z'; i++)
			{if(i!=s[0])
				cout << i;
			}
			cout << el;
		}
		else
		{
			for (int i = 1; i < s.size(); i++)
			{
				adj[s[i] - 'a'].insert(s[i - 1] - 'a');
				adj[s[i-1] - 'a'].insert(s[i ] - 'a');
			}
			int cnt1 = 0; int cnt2 = 0; int flag = 0; char st;
			for (int i = 0; i < 26; i++)
			{
				
				 if (adj[i].size() > 2)
					cnt2++;
				else if (adj[i].size() == 1)
				{
					 st = ('a' + i); flag = 1; cnt1++;
				}
			}
			
			if (cnt2||cnt1!=2)
			{
				no;
			}
			else
			{
				dfs(st - 'a');
				yes;
				cout << ans ;
				for (char i = 'a'; i <= 'z'; i++)
				{
					if (!vis[i - 'a'])
						cout << i;
				}
				
				cout << el;
			}
		}
	}
}