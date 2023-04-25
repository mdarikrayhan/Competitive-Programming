#include<bits/stdc++.h> 
using namespace std;
int const M=500500,sg[]={4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7};
int i,j,n,T,R,Ans;char s[M];
int SG(int x){return (x==0||x==1||x==15||x==35)?0:(x==17||x==18||x==32||x==52)?2:sg[x%34];}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%s",&n,s+1);Ans=R=0;
		for (i=1;i<=n;i++) R+=s[i]=='R';
		if ((R<<1)>n) {puts("Alice");continue;}
		if ((R<<1)<n) {puts("Bob");continue;}
		for (i=1;i<=n;i=j){ j=i+1;
			while (j<=n&&s[j]!=s[j-1]) j++;
			Ans^=SG(j-i);
		} 
		puts(Ans?"Alice":"Bob");
	}
	return 0;
}