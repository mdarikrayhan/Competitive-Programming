// LUOGU_RID: 157328188
#include<bits/stdc++.h>
#define int long long
#define mid (lt+rt>>1)
using namespace std;
const int cxk=1e5+5;
int a[cxk],ans,n;
void run(int lt,int rt)
{
	for(int i=lt;i<rt;i++)
		if(a[i]>a[i+1])
			goto a;
	ans=max(ans,rt-lt+1);
	a:
	if(lt==rt)
		return;
	run(lt,mid);
	run(mid+1,rt);
}
signed main()
{//
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	run(1,n);
	cout<<ans;
}
