#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,ans;char s[3][o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%s%s%s",&n,s[0]+1,s[1]+1,s[2]+1);
		for(int i=0;i<3;++i) for(int j=i+1;j<3;++j)
			if(s[i][n]^s[j][n]) for(int k=n;s[i][k]==s[i][n]&&s[j][k]==s[j][n];--k) ++ans;
		if(ans>n) ans=n;
	}
	return 0;
}