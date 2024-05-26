// LUOGU_RID: 160370670
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void fio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int N=105;
int a[N];
signed main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=10,ans=0,ans2=0;
	for (int i=1;i<=n;i++){
		cnt+=a[i];
		if (cnt>720){
			break;
		}
		ans=i;
		if (cnt>360){
			ans2+=cnt-360;
		}
	}
	cout<<ans<<' '<<ans2;
	return 0;
}
