#include <stdio.h>

typedef long long ll;

int c[407];
ll dp1[407][407], dp2[407][407], dp3[407][407];

inline ll min(ll a, ll b){
	return a < b ? a : b;
}

int main(){
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	for (int i = n; i >= 1; i--){
		bool flag = true;
		for (int j = i; j <= n; j++){
			flag &= c[i] == c[j];
			dp1[i][j] = 0x7fffffffffffffffll;
			for (int k = i; k < j; k++){
				dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j]);
			}
			if (c[i] == c[j]){
				if (flag){
					dp2[i][j] = x;
					dp3[i][j] = x + (ll)y * (j - i + 1);
				} else {
					dp2[i][j] = dp3[i][j] = 0x7fffffffffffffffll;
					for (int k = i + 1; k <= j; k++){
						if (c[i] == c[k]){
							dp2[i][j] = min(dp2[i][j], dp1[i + 1][k - 1] + dp2[k][j] + y * 2);
							dp3[i][j] = min(dp3[i][j], dp1[i + 1][k - 1] + dp3[k][j] + y);
						}
					}
				}
				dp1[i][j] = min(dp1[i][j], min(dp2[i][j], dp3[i][j]));
			}
		}
	}
	printf("%lld", dp1[1][n]);
	return 0;
}
 