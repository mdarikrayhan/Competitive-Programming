// LUOGU_RID: 160173861
#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[11]= {1,2,3,5,7,11,13,17,19,23,29};
int f[1010];
int n;
signed main() {
	cin >> n;
	memset(f,0x3f,sizeof(f));
	f[1] = 1;
	for(int j = 0; j <= 9; j++){
		for(int i=1000; i; i--){
			int x=f[i];
			for(int k = 1; k <= 63; k++){
				if(1e18 / p[j+1] < x) break;
				x *= p[j+1];
				if(i*(k+1) > n) break;
				f[i*(k+1)] = min(f[i*(k+1)],x);
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}