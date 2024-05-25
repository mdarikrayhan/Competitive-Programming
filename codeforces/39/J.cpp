#include<cstdio>
#include<cstring>
#define maxn 1000006
using namespace std;
char s[maxn],t[maxn];
int main(){
	int n,p,q,ans,k;
	scanf("%s%s",s,t);
	n=strlen(s);
	p=-1;q=n;
	for(int i=0;i<n-1;i++){
		if(s[i]!=t[i])break;p=i;
	}for(int i=n-1;i>0;i--){
		if(s[i]!=t[i-1])break;q=i;
	}
	if(p+1<q-1||(p==-1&& q==n))printf("0");
	else if(p+1==q-1)printf("1\n%d",q);
	else {
		
		ans=1;k=p+1;
		for(int i=p;i>=0;i--){
			if(s[i]==s[i+1])ans++,k=i;else break;
		}printf("%d\n",ans);p++;
		for(int i=k+1;i<=p+1;i++)printf("%d ",i);
		
		
	}
	return 0;
} 