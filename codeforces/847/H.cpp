/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define i64 long long
const int inf = 1e18 ;
const int MOD = 998244353;
const int Maxn = 1e5 + 5;
int dx[]{0,0,-1,1},dy[]{-1,1,0,0};
int n;
int a[Maxn];
int L[Maxn], R[Maxn];
int bestL[Maxn], bestR[Maxn];
int res = inf;
void solve(){
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] ;
	for(int i = 1 ; i <= n ; i ++){
		bestL[i] =  bestL[i - 1] ;
		L[i] = max(a[i],L[i - 1] + 1) ;
		bestL[i] += L[i] - a[i] ;
	}
	for(int i = n ; i > 0 ; i --){
		bestR[i] = bestR[i + 1] ;
		R[i] = max(a[i],R[i + 1] + 1) ;
		bestR[i] += R[i]  - a[i] ;
	}
	for(int i = 0 ; i <= n ; i ++){
		int curr = bestR[i + 1] + bestL[i] ;
		curr += (R[i + 1] == L[i]) ;
		res = min(res,curr) ;
	}
	cout << res << '\n' ;
}
int32_t main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tc = 1 ;
//	cin >> tc ;
	while(tc--){
		solve() ;
	}
	return 0;
}