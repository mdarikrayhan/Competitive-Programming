// LUOGU_RID: 159777005
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E5+5;
string s,t;
int n,m;
int rec[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s>>t;
	n=s.size();s='#'+s;
	m=t.size();t='#'+t;
	int j=1;
	for (int i=1,top=1;i<=n;i++) {
		if (s[i]==t[top]) rec[s[i]]=++top;
		if (s[i]==t[j]) j++;
		j=min(j,rec[s[i]]);
		if (j < 2) return cout<<"NO\n",0;
	}
	cout<<(j==m+1?"YES\n":"NO\n");
	return 0;
}