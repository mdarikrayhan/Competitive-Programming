#include<bits/stdc++.h>
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define ULL unsigned long long
#define int  long long
#define x first
#define y second 

#define rs u << 1 | 1
#define ls u << 1
using namespace std;
const int eps = 1e-6;
const int N = 1e6+10,M = 1010 ,mod =1e9+7;
int mul(int a,int k)
{
	int res = 0 ;
	while(k)
	{
		if(k&1) res = (res + a) % mod ;
		k>>= 1;
		a = (a+a)%mod;
	}
	return res ;
}
int qmi(int a,int k)
{
    int res = 1;
    while(k)
    {
        if(k&1) res = mul(res,a)%mod;
        k>>=1;
        a = mul(a,a)%mod;
    }
    return res;
}
//vector<int> prime;
// vector<bool> st(N) ;
// void get(int n)
// {	
// 	for(int i = 2;i<=n;i++)
// 	{
// 		if(!st[i]) prime.push_back(i) ;
// 		for(int j = 0;prime[j]<=n/i;j++)
// 		{
// 			st[i*prime[j]] = true;
// 			if(i%prime[j]==0) break ;
// 		}
// 	}
// }
int n,m,k,x,y,z,q;
string str;

void solve()
{
	cin >> n >> str;

	if(str.back() == 'B' ) cout <<"B"<<endl;
	else if(str.back() == 'A' ) cout <<"A" <<endl;

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin>>T;
	
	while(T --)
	{
		solve();
	}        
	return 0;	
} 
//gcd(a+b,c)⩾gcd(a,b,c)
//gcd(a,b) == gcd(a,b%a)
// int mx = 0 ,pre = 0;
// for(int i = 1;i<=n;i++)
// {
// 	pre = max(pre+a[i],0ll) ;
// 	mx = max(mx,pre) ;
// }
//预处理因子(nlnn)
// void init()
// {
// 	for(int x = 1;x<=1e5+1;x++)
// 	{
// 		for(int j = x;j<=1e5+1;j+=x)
// 		{
// 			v[j].push_back(x) ;
// 		}
// 	}
// }
//a + b = a^b + 2*(a&b)

