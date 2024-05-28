// LUOGU_RID: 159261061
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 200005;

LL n,m,k,p;
LL to[N],h[N],dv[N],fir[N],a[N];
LL val[5005];

LL chk(LL x){
	LL sum = 0,td;
	for(LL i = 1;i <= n;i ++){
		to[i] = h[i] + a[i] * m - x;
		fir[i] = -1; dv[i] = 0;
		if(to[i] <= 0) continue;
		dv[i] = (to[i] - 1) / p;
		fir[i] = to[i] - dv[i] * p;
		sum += (dv[i] + 1);
	} if(sum > m * k) return 0; 
	
	for(LL i = 1;i <= m;i ++) val[i] = 0;
	for(LL i = 1;i <= n;i ++){
		to[i] = h[i];
		for(LL j = 1;j <= m;){
			while(to[i] >= p && dv[i]){
				to[i] -= p; dv[i] --;
				val[j] ++;
			}
			if(to[i] >= fir[i] && fir[i] != -1){
				to[i] -= fir[i]; fir[i] = -1;
				val[j] ++;
			}
			if(fir[i] == -1 && !dv[i]) break;
			
			td = ((fir[i] == -1 ? p : fir[i]) - to[i] - 1) / a[i];
			to[i] += a[i] * (td + 1); j += (td + 1);
		}
	} sum = 0;
	for(LL i = m;i >= 1;i --){
		sum += val[i];
		if(sum > k * (m - i + 1)) return 0;
	} return 1;
}

int main(){
	ios::sync_with_stdio(false);
	LL mxa = 0,l,r,mid,ans;
	cin >> n >> m >> k >> p;
	for(LL i = 1;i <= n;i ++){
		cin >> h[i] >> a[i];
		mxa = max(mxa,a[i]);
	}
	
	l = mxa,r = 0x3f3f3f3f3f3f3f3f;
	while(l <= r){
		mid = (l + r) >> 1;
		if(chk(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}