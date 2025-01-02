#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
vector<int>c;
int ask(int x)
{
	cout<<"? "<<x<<endl;
	int op;cin>>op;
	return op;
}
signed main()
{
	int T;scanf("%lld",&T);
	while(T--){
		int n;scanf("%lld",&n);
		c.clear();
		int l = 1, r = n - 1;
		while(l <= r){
			int mid = (l + r) >> 1;
			c.push_back(mid);
			l = mid + 1;
		}
		reverse(c.begin(), c.end());
		int st = 1, j = 1;
		for(int x : c)st += j * x, j *= -1;
		l = 1, r = n - 1;int ed = n;
		ask(st);
		while(l <= r){
			int mid = (l + r) >> 1;
			st += j * mid, j *= -1;
			if(ask(st))ed = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout<<"= "<<ed<<endl;
	}
	return 0;
}