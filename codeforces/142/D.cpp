#include <cstdio>
#include <cmath>
char s[1005];int n,m,k,ans[23],G,R,has,oG,oR;
#define o(x) return puts((!x)?"First":"Second") * 0
#define F(i,a,b) for(int i=a;i<=b;++i)
int main(void) {
	scanf("%d%d%d" , &n , &m , &k);
	F(i,1,n) {
		has = G = R = 0; scanf("%s",s+1); 
		F(j,1,m) if(s[j]=='-') has=1; else if(s[j]=='G') G=j; else if(s[j]=='R') R=j;if((!G&&!R)||!has) continue; if(!G) oR=1; else if(!R) oG=1; else F(j,0,20) if((1<<j)&(abs(R - G)-1)) ++ ans[j];
	}
	if(oR&&oG) return puts("Draw") * 0;if(oR)o(1); if(oG) o(0);
	F(i,0,20) if(ans[i]%(k + 1)) o(0); o(1);
}