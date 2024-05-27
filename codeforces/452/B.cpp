#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	if(n && m){
		if(n < m){
			if(2 * sqrt((n - 1) * (n - 1) + m * m) > m + sqrt(n * n + m * m)){
				printf("%d %d\n%d %d\n%d %d\n%d %d\n", n - 1, m, 0, 0, n, m, 1, 0);
			}else{
				printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, 0, m, n, 0);
			}
		}else{
			if(2 * sqrt(n * n + (m - 1) * (m - 1)) > n + sqrt(n * n + m * m)){
				printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m - 1, 0, 0, n, m, 0, 1);
			}else{
				printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, n, 0, 0, m);
			}
		}
	}else if(n)	printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, 0, 0, 0, n - 1, 0);
	else	printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, 0, m, 0, 0, 0, m - 1);
	return 0;
}