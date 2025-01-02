#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ((x)&(-x))
#define endl '\n'
#define sc scanf
#define pt printf
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define ls k+k
#define rs k+k+1
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int N = 2e5 + 10;
void UraykevoliQwQ()
{
	int n;cin>>n;
	ll X1=1e9,Y1=1e9,X2=0,Y2=0;
	ll S=0;
	for(int i=1;i<=n;i++)
	{
		ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		X1=min({x1,x2,X1});
		X2=max({x1,x2,X2});
		Y1=min({y1,y2,Y1});
		Y2=max({y1,y2,Y2});
		S+=abs(x1-x2)*abs(y1-y2);
	}
	if(abs(X1-X2)*abs(Y1-Y2)==S&&abs(X1-X2)==abs(Y1-Y2))
	{
		YES;
	}
	else NO;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	UraykevoliQwQ();
	return 0;
}