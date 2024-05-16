#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int p=n/3,sy=n%3;
	if(sy==0){
		cout<<p<<" "<<p+1<<" "<<p-1<<endl;
	}
	else if(sy==1){
		cout<<p<<" "<<p+2<<" "<<p-1<<endl;
	}
	else {
		cout<<p+1<<" "<<p+2<<" "<<p-1<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}