#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

typedef long long LL;

const int MAXN=1e5+10;

LL sum;
int n,m;
LL a[MAXN],b[MAXN],d[MAXN];

int read(){
	int sym=1,num=0;char cnt=getchar();
	while(cnt<'0'||cnt>'9'){
		if(cnt=='-') sym=-1;
		cnt=getchar();
	}
	while(cnt>='0'&&cnt<='9'){
		num=(num<<3)+(num<<1)+(cnt^48);
		cnt=getchar(); 
	} 
	return sym*num;
}

void PRINT(){
	printf("%lld\n",sum/2+max(sum%2,(LL)0));	
}

int main(){
	n=read(); 
	for(int i=1;i<=n;i++){
		a[i]=read(),d[i]=a[i]-a[i-1];
		if(d[i]>0||i==1) sum+=d[i];
	//	printf("lyd %lld\n",sum);
	}
	PRINT();
//	printf("lyd%lld\n",sum);
	m=read();
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),val=read();
		if(d[l]>0||l==1) sum-=d[l];
		if(d[r+1]>0&&r<n) sum-=d[r+1]; 
		d[l]+=val,d[r+1]-=val;
		if(d[l]>0||l==1) sum+=d[l];
		if(d[r+1]>0&&r<n) sum+=d[r+1];
		PRINT();
	}
	return 0;
} 
      			     	 						  			   	