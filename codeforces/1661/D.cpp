// LUOGU_RID: 160091372
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 300010;
int add[N],b[N];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i ++){
		cin>>b[i];
	}
	int now = 0,cnt = 0,ans = 0;
	for(int i = n;i>=k;i --){
		now -= cnt;
		int tmp = ((b[i] - now) + k - 1)/k;
		if(b[i] - now <= 0)tmp = 0;
		if(i - k > 0)add[i - k] -= tmp;
		now += tmp * k,ans += tmp,cnt += tmp;
		cnt += add[i];
	}
	for(int i = k-1;i>=1;i --){
		now -= cnt;
		b[i] -= now;cnt += add[i];
	}
	int res = 0;
	for(int i = k-1;i >= 1;i --){
		if(b[i] > 0)res = max(res,(b[i] + (i-1))/i);
	}
	cout << ans + res << endl;
	return 0;
}