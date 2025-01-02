#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
const int N=1e5+10;
int a[N],b[N],s[N];
int n,k,x,l=1,ans;
void solve()
{
    cin>>n>>k;
    vector<PII>v;
    multiset<int>se;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	se.insert(a[i]);
    	while(*se.crbegin()-*se.cbegin()>k)
    		se.erase(se.find(a[l++]));
    	if(i-l+1>ans)
    	{
    		v.clear();
    		ans=i-l+1;
    		v.push_back({l,i});
    	}
    	else if(i-l+1==ans)
    	v.push_back({l,i});
    }
    cout<<ans<<" "<<v.size()<<endl;
    for(auto x:v)
    cout<<x.first<<" "<<x.second<<endl;
}
int main()
{
    IOS;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}