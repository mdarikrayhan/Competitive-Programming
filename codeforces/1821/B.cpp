#include <bits/stdc++.h>
 
using namespace std;
void sove()
{
	int  n;
	cin>>n;
	vector<int>v(n),s(n);
	for(auto &it:v)cin>>it;  for(auto &it:s)cin>>it;
	int l=0,r=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=v[i])
		{
			l=r=i;
			break;
		}
	}
	while(l>0&&s[l-1]<=s[l])l--;	while(r<n-1&&s[r+1]>=s[r])r++; cout<<l+1<<" "<<r+1<<"\n";
}
int main ()
{
	int t;
	cin>>t;
	while(t--)sove();
}