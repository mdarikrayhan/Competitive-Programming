#include "bits/stdC++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,r;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x,x=__builtin_ffs(x)-1;
		r=max(*min_element(all(a))-1,0);
		for (int x:a) r+=(x>0);
		cout<<r<<'\n';
	}
}