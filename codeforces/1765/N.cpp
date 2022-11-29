#include<cstdio>
#include<cstring>
const int o=5e5+10;
int T,n,k,tp,pre[o],lst;char x[o],st[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%s%d",x+1,&k);n=strlen(x+1);st[lst=tp=1]=x[1];
		for(int i=2;i<=n;++i){
			for(;tp&&x[i]<st[lst]&&(lst>1||x[i]>48)&&k>=tp-lst+1;) k-=tp-lst+1,tp=lst-1,lst=pre[lst];
			st[++tp]=x[i];pre[tp]=lst;
			if(st[tp]>'0') lst=tp;
		}
		for(int i=1;i<=tp-k;++i) putchar(st[i]);
	}
	return 0;
}