#include<bits/stdc++.h>
using namespace std;
struct str{
	int len,num[2005];
	bool operator <(str a){
		if(len!=a.len)return len<a.len;
		for(int i=len;i>=1;i--){
			if(a.num[i]==num[i])continue;
			return num[i]<a.num[i];
		}
		return 0;
	}
	str operator +(str a){
		a.len=max(a.len,len);
		for(int i=1;i<=len;i++){		
			a.num[i]+=num[i],
			a.num[i+1]+=a.num[i]/10;
			a.num[i]=a.num[i]%10;
		}
		if(a.num[a.len+1]!=0)a.len++;
		return a;
	}
}p[2005],f[5005],x;
void pow(str &a){
	for(int i=a.len;i>=1;i--){
		a.num[i]*=2;
		a.num[i+1]+=a.num[i]/10;
		a.num[i]=a.num[i]%10;
	}
	if(a.num[a.len+1]!=0)a.len++;
}
void print(str a){
	if(a.len==0){
		printf("0\n");
		return;
	}
	for(int i=a.len;i>=1;i--)
	printf("%d",a.num[i]);
	printf("\n");
}
void init(){
	p[0].num[1]=1;
	p[0].len=1;
	for(int i=1;i<=2001;i++){
		p[i]=p[i-1];
		pow(p[i]);
	}
}
int n,num[5005],last[5005];
string s;
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		cin>>s;
		scanf("%d",&num[i]);
		f[i]=f[i-1];
		if(s[0]=='w')last[num[i]]=i;
		else{
			if(last[num[i]]==0)continue;
			x=f[last[num[i]]]+p[num[i]];
			if(f[i]<x)f[i]=x;
		}
	}
	print(f[n]);
}