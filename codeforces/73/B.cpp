#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=2e5+5;
int n,aa[INF],p[INF],a2[INF],m,b[INF];
string s1[INF],s2[INF],A;
multiset <int> s;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>s1[i]>>aa[i],p[i]=i;
	cin>>m;
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=n;i++) s.insert(b[i]);
	cin>>A;
	for (int i=1;i<=n;i++) a2[i]=aa[i];
	
	int Max=*(--s.end());
	s.erase(s.find(Max));
	int la3=0;
	for (int i=1;i<=n;i++)
		if (s1[i]==A) a2[i]+=Max,la3=i;
	int ans1=1,ans2=1;
	for (int i=1;i<=n;i++)
		if (s1[i]>A) {
			auto it=s.upper_bound(a2[la3]-a2[i]);
			if (it==s.begin()) {ans1++;continue;}
			else {it--;s.erase(s.find(*it));}
		} else if (s1[i]<A) {
			auto it=s.lower_bound(a2[la3]-a2[i]);
			if (it==s.begin()) {ans1++;continue;}
			else {it--;s.erase(s.find(*it));}
		}
	s.clear();
	for (int i=1;i<=n;i++) s.insert(b[i]);
	for (int i=1;i<=n;i++) a2[i]=aa[i];
	Max=*(s.begin());
	s.erase(s.find(Max));
	a2[la3]+=Max;
	
	for (int i=1;i<=n;i++)
		if (s1[i]>A) {
			auto it=s.upper_bound(a2[la3]-a2[i]);
			if (it==s.end()) continue;
			else {s.erase(s.find(*it));ans2++;}
		} else if (s1[i]<A) {
			auto it=s.lower_bound(a2[la3]-a2[i]);
			if (it==s.end()) continue;
			else {s.erase(s.find(*it));ans2++;}
		}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}