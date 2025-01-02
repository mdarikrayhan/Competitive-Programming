#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200*1000+100;
int n ,  m , p;
int a[maxn];
int b[maxn];
map<int,int> numb;
map<int,int> numa;
vector<int> ans;
int sum = 0;

void add(int x)
{
	int val = numa[x]+1;
	numa[x]=val;
	if(numb[x] >= val)
		sum++;
}

void remove(int x)
{
	int val = numa[x]-1;
	numa[x]=val;
	if(numb[x] > val)
		sum--;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;

	For(i,0,n)
		cin >> a[i];
	For(i,0,m)
	{
		cin >> b[i];
		numb[b[i]]++;
	}

	For(i,0,p)
	{
		numa.clear();
		sum = 0;

		for(int j = i ; j < i+(ll)p*(ll)m && j < n ; j+=p)  
			add(a[j]);

		for(int q = i ; (ll)q+(ll)p*(ll)(m-1) < n ; q+=p)
		{
			if(sum == m)
				ans.pb(q);
			if((ll)q+(ll)p*(ll)m < n)
			{
				add(a[q+p*m]);
				remove(a[q]);
			}
		}
	}
	sort(all(ans));
	cout << n(ans) << endl;
	For(i,0,n(ans))
		cout << ans[i]+1 << " " ;
	cout << endl;
	return 0;
}