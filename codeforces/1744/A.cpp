#include<cstring>
#include<stdio.h>
int main(){
	int t,n,f,i,a[52],b[52];char s[51];
	for(scanf("%d",&t);t;--t,puts(f?"NO":"YES")){
		for(scanf("%d",&n),memset(b,0,sizeof(b)),i=0;i<n;++i)scanf("%d",&a[i]);
		for(scanf("%s",s),f=i=0;i<n;++i)b[a[i]]&&b[a[i]]-s[i]?f=1:b[a[i]]=s[i];
	}
}