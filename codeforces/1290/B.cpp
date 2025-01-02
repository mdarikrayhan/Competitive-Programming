// LUOGU_RID: 160062271
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,alpha=50;
char ch[N];
int q[N][alpha];
int n,m,l,r;
int main(){
	scanf("%s%d",ch+1,&m); n=strlen(ch+1);
	for(int i=1;i<=n;++i) {for(int j=0;j<26;++j)q[i][j]=q[i-1][j];++q[i][ch[i]-'a'];}
	while(m--){scanf("%d%d",&l,&r);int cnt=0;if(l==r||ch[l]!=ch[r]){cout<<"Yes\n";continue;}else{
		for(int i=0;i<26;++i) if(q[r][i]!=q[l-1][i]) ++cnt;
		if(cnt>2) cout<<"Yes\n"; else cout<<"No\n";
	}} return 0;
}