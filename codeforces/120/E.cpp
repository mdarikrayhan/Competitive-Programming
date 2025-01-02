#include<bits/stdc++.h>
#define Alex ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
#define LD long double
using namespace std;
const int QAQ = 0;
const int base = 131;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 2e6+10;
const int inf = 0x3f3f3f3f3f3f3f;
int n;
signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	Alex;
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n;
		if(n % 2 == 1) cout<<0<<'\n';else cout<<1<<'\n';
    }
    return QAQ;
}  
