#include<bits/stdc++.h>
const int N = 5009;
int n, a[N], k, V, dp[N][N], b[N];
void get(int d, int s){
	if(d == 0) return ;
	if(dp[d-1][s] == 1) b[d] = 0, get(d-1, s);
	else b[d] = 1, get(d-1, (s - a[d] % k + k)%k);
}
int main(){
	scanf("%d %d %d", &n, &k, &V);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(sum < V){
		printf("NO\n");
		return 0;
	}
	if(V % k == 0){
		printf("YES\n");
		if(a[n]) printf("%d %d %d\n", (a[n]+k-1)/k, n, 1);
		a[1] += a[n];
		sum = 0;
		if(V != 0){
			for(int i = 2; i < n; i++) if(a[i]) printf("%d %d %d\n", (a[i]+k-1)/k, i, 1);
			printf("%d %d %d\n", V/k, 1, n);
		}
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++)
		    dp[i][(j+a[i])%k] = dp[i-1][(j+a[i])%k] | dp[i-1][j];
	}
	if(dp[n][V%k] == 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	get(n, V%k);
	int s = 0;
	sum = 0;
	for(int i = 1; i <= n; i++)
	    if(b[i]){
	    	s = i;
	    	sum = a[i];
	    	break;
		}
	for(int i = s+1; i <= n; i++)
	    if(b[i] && a[i]) printf("%d %d %d\n", (a[i]+k-1)/k, i, s), sum += a[i];
	int t;
	if(s == 1) t = s + 1;
	else t = s - 1;
	if(sum > V) printf("%d %d %d\n", (sum-V)/k, s, t);
	else if(sum < V){
	     for(int i = 1; i <= n; i++)
	         if(i != t && !b[i] && a[i]) printf("%d %d %d\n", (a[i]+k-1)/k, i, t);
		printf("%d %d %d\n", (V-sum)/k, t, s);	 		
	}

	         
}
  	 	   		 	   		 	 	   	   	