// LUOGU_RID: 159909619
#include <bits/stdc++.h>
using namespace std;
int n,cur=1,cnt=0;
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n/3*2+(n%3?1:0);i++)
	{
		if(i&1)
		{
			++cnt;
			if(cnt<=n)
				cout<<i<<" 1\n";
			++cnt;
			if(cnt<=n)
				cout<<i<<" 3\n";
		}
		else
		{
			++cnt;
			if(cnt<=n)
				cout<<i<<" 2\n";
		}
	}
	return 0;
}
//Skadi_H
