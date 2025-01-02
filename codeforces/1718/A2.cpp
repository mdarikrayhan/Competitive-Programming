// LUOGU_RID: 160178548
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],ans;
map<int ,bool> ma;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		ma.clear();
		ma[0]=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=n;
		int now=0;
		for(int i=1;i<=n;i++) {
			now^=a[i];
			if(ma[now]) {
				ma.clear();
				ma[0]=1;
				now=0;
				ans--;
			} else {
				ma[now]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 