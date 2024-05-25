#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_NODES 105
#define INF 10000007
 
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define clr(a) memset(a, 0, sizeof(a))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
 
typedef long long i64;
 
int v[MAX_NODES][MAX_NODES], vis[MAX_NODES], cost[MAX_NODES][MAX_NODES], n;
 
void reset() {
    clr(vis);
}
 
int max(int a, int b) {
    return (a > b) ? a : b;
}
 
int dfs(int u) {
    vis[u] = 1;
 
    int leaf = 0;
 
    int maxi = 0;
 
    fr(n) {
        int nd = v[u][i];
        if (!vis[nd]) {
            int total = cost[u][nd] + dfs(nd);
            maxi = max(total, maxi);
        }
    }
 
    return maxi;
}
 
int main() {
    reset();
    int p, b, c, root, x;
 
    si(n);
 
    fr(n - 1) {
        sii(p, b);
        si(c);
 
        cost[p][b] = c;
        cost[b][p] = c;
 
        v[p][i] = b;
        v[b][i] = p;
    }
 
    printf("%d\n", dfs(0));
    return 0;
}
 
	    		 	 		  	   	 	 	 		 				
  	 		 	   		  				  		  	
					 					  	   	   			  			 	