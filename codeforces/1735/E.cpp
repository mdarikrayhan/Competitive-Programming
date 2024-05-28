// LUOGU_RID: 159212729
#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=1e3+5;
int T,n,a[N],b[N];
vector<int>g,h;multiset<int>S;
inline void sol()
{
	g.clear();
	for(int i=1;i<=n;i++) g.push_back(abs(a[1]-b[i])),g.push_back(a[1]+b[i]);
	for(int k:g)
	{
		S.clear();for(int i=1;i<=n;i++) S.insert(b[i]);
		bool ok=1;h.clear();
		for(int i=n;i;i--)
		{
			if(S.find(a[i]+k)!=S.end()) h.push_back(-a[i]),S.erase(S.find(a[i]+k));
			else if(S.find(a[i]-k)!=S.end()) h.push_back(a[i]),S.erase(S.find(a[i]-k));
			else if(S.find(k-a[i])!=S.end()) h.push_back(a[i]),S.erase(S.find(k-a[i]));
			else{ok=0;break;}
		}
		if(ok)
		{
			cout<<"YES\n";
			sort(h.begin(),h.end());int mn=min(h[0],0);
			for(int i:h) cout<<i-mn<<" ";cout<<"\n";
			cout<<-mn<<" "<<k-mn<<"\n";return;
		}
	}
	cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) cin>>b[i];sol();
	}
	return 0;
}