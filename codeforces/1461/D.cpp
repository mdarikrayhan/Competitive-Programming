#include <bits/stdc++.h>
using namespace std;
set<long long> S;
int t,n,q,a[100050];
long long s[100050];
 
void add(int l,int r) {
	int m=upper_bound(a+l,a+r+1,(a[l]+a[r])/2)-a;
	S.insert(s[r+1]-s[l]);
	if (m-1==r) return;
	add(m,r);
	add(l,m-1);
}
 
int main() {
	cin>>t;
	while (t--) {
		cin>>n>>q;
		for (int i=0; i<n; ++i)
			scanf("%d",a+i);
		sort(a,a+n);
		for (int i=0; i<n; ++i)
			s[i+1]=a[i]+s[i];
		add(0,n-1);
		while (q--) {
			int x; scanf("%d",&x);
			if (S.count(x)) cout<<"Yes\n";
			else cout<<"No\n";
		}
		S.clear();
	}
}