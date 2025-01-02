#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int max_(int aa, int bb){
	return aa > bb ? aa : bb;
}
int min_(int aa, int bb){
	return aa < bb ? aa : bb;
}
int abs_(int aa){
	return aa > 0 ? aa : -aa;
}
const int N = 1e6 + 5;
int n, a[N], cnt, num, ans[N], tmp, tmp2, tmp3, t;
ll tt;
bool check(){
	a[n] = a[0];
	a[n + 1] = a[1];
	a[n + 2] = a[2];
    for(int i = 0; i < n; i++){
		if(a[i] && a[i + 1] && a[i + 2] && a[i + 3]) return 1;
    }
	return 0;
}
void solve(){
	cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	while(check()){
		for(int i = 0; i < n; i++){
			a[(i + 1) % n] = max_(0, a[(i + 1) % n] - a[i]);
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] && a[(i + 1) % n]) a[(i + 1) % n] = max_(0, a[(i + 1) % n] - a[i]);
		else break;
    }
	for(int i = 0; i < n; i++){
		tmp = (i - 1 + n) % n;
		if((!a[tmp]) && a[i]){
			ans[++cnt] = i + 1;
			tmp2 = (i + 1) % n;
			tmp3 = (i + 2) % n;
			if(a[tmp2] && a[tmp3]){
				tt = a[tmp2] / a[i];
				if(a[tmp3] > (a[tmp2] - a[i] + a[tmp2] - a[i] * tt) * tt / 2){
					ans[++cnt] = tmp3 + 1;
				}
			}
		}
	}
	sort(ans + 1, ans + cnt + 1);
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	printf("\n");
	return ;
}
int main(){
	scanf("%d", &t);
	for(int kk = 1; kk <= t; kk++){
		solve();
	}
	return 0;
}