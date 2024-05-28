#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N=1005000;

int n,m;
int b[N];
long long ans;

inline long long read(){
	long long re=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		re=re*10+ch-'0';
		ch=getchar();
	}
	return re*k;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		b[x]++,b[y]++;
	}
	for(int i=1;i<=n;i++)	ans-=(long long)b[i]*(n-1-b[i]);
	ans=ans/2+(long long)(n-2)*(n-1)*n/6;
	printf("%lld\n",ans);
	return 0;
}