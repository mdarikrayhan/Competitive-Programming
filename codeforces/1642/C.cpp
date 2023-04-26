#include <bits/stdc++.h>
using namespace std;
int T,n,x,y; 
int main() {
	for(scanf("%d",&T);T--;) {
		map<int,int>S;
		scanf("%d%d",&n,&x); for(int i=1;i<=n;i++,S[y]++) scanf("%d",&y);
		int ans=n;
		for(auto &[a,b]:S) if(a%x==0&&S[a/x]) ans-=2*min(S[a/x],b),b-=min(S[a/x],b);
		printf("%d\n",ans);
	}
}