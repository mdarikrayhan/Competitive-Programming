// LUOGU_RID: 159651852
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[300001],ans,x,y;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ans+=a[i]/2;
		if(a[i]&1){
			if(i&1) x++;
			else y++;
		}
	}
	ans+=min(x,y);
	cout << ans << '\n';
	return 0;
}