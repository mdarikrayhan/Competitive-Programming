#include<bits/stdc++.h>
#define Alex ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define LD long double
#define int long long
using namespace std;
const int QAQ = 0;
const int base = 131;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 2e6+10;
int n,k,minn,sun,sum,l[555555],r[555555];
signed main()
{
	Alex;
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n>>k;
		minn = LLONG_MAX;
		sun = sum = 0;
		for(int i = 1;i <= n;i++) cin>>l[i];
		for(int i = 1;i <= n;i++)
		{
			cin>>r[i];
			sun = sun + (l[i] == r[i]);
			sum = sum + (r[i] - l[i] + 1);
			if(sum >= k)
			{
				minn = min(minn,r[i] - (sum - k) + (i << 1) - min(sun,sum - k));
			}
		}
		if(minn == LLONG_MAX) cout<<-1<<'\n';else cout<<minn<<'\n';
    }
    return QAQ;
}  

