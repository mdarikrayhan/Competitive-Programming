#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,x,ans;
char s[N],c;
bool ok(int x){
	return x<1||x+2>n?0:s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
signed main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;i++) ans+=ok(i);
	while(q--){
		scanf("%d %c",&x,&c);
		for(int i=x-2;i<=x+2;i++) ans-=ok(i);
		s[x]=c;
		for(int i=x-2;i<=x+2;i++) ans+=ok(i);
		printf("%d\n",ans);
	}
	return 0;
}