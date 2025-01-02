// LUOGU_RID: 160086888
#include<bits/stdc++.h>
using namespace std;

const int N=105;

int n,m,grp[N*2];

int main(){
	
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m); for(int i=0;i<=n+m-2;i++) grp[i]=0;
		for(int i=0,x;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &x),grp[i+j]^=x;
		int f=0; for(int i=0;i<=n+m-2;i++) if(grp[i]) f=1;
		printf(f?"Ashish\n":"Jeel\n");
	}
	return 0;
}