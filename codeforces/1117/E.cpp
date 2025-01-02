// LUOGU_RID: 159793312
#include <cstdio>
#include <cstring>
const int maxn = 1e4+5,pw[] = {1,26,676,17576};
int n,qry[3][maxn];char s[maxn],t[3][maxn],ans[maxn];
int main(){
	scanf("%s",s),n = strlen(s);
	for(int _=0;_<3;++_){
		for(int j=0;j<n;++j)
			qry[_][j] = j%pw[_+1]/pw[_];
		printf("? ");
		for(int j=0;j<n;++j)putchar('a'+qry[_][j]);
		puts(""),fflush(stdout);
		scanf("%s",t[_]);
	}
	for(int i=0;i<n;++i){
		int pos = 0;
		for(int _=0;_<3;++_)
			pos += (t[_][i]-'a')*pw[_]; 
		ans[pos] = s[i];
	}
	return printf("! %s",ans),fflush(stdout),0;
}