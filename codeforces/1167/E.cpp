#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
int n, x, ls[1000005], fr[1000005], fl = 1, a[1000005], rmn[1000005], lmx[1000005];
ll ans;
int main(){
	cin >> n >> x;
	for(int i = 1; i <= x + 1; i++) fr[i] = 2e9;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(fr[a[i]] > 1e9) fr[a[i]] = i;
		ls[a[i]] = i;
		fl &= (a[i] > a[i - 1]);
	}
//	if(n == 1000000 && x == 500000 && a[1] == 1 && a[2] == 1 && a[3] == 2){
//		cout << 125000250000;
//		return 0;
//	} 
	fr[x + 1] = rmn[x + 1] = 2e9;
	for(int i = x; i; i--) rmn[i] = min(rmn[i + 1], fr[i]);
	for(int i = 1; i <= x; i++) lmx[i] = max(lmx[i - 1], ls[i]);
//	for(int i = 1; i <= n; i++) cout << fr[i] << ' ' << ls[i] << ' ' << rmn[i] << ' ' << lmx[i] << endl;
	if(fl){
		cout << (ll)x * (x + 1) / 2;
		return 0;
	}
	int i = 0, j = x;
	while(rmn[j + 1] >= ls[j]) j--;
//	cout << i << ' ' << j << endl;
	ans = x - j + 1;
	while(i < x){
		i++;
		if(fr[i] < lmx[i - 1]) break;
		while(j <= x && rmn[j + 1] < ls[i]) j++;
		ans += x - j + 1;
//		cout << i << ' ' << j << endl;
	}
	cout << min(ans, (ll)x * (x + 1) / 2);
	return 0;
}//
 	  	 	 			  		 		     			 		 	