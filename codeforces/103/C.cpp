// LUOGU_RID: 159064606
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,T,x;
char doing(int n,int m,int x){
	if(n%2==1&&m>0&&n==x) return 'X';
	m-=n%2;n/=2;
	if(m>n){
		if(x%2==0) return 'X';
		x=x/2+1;
		return x>n*2-m?'X':'.';
	}
	else{
		if(x%2==1) return '.';
		x=x/2;
		return x>n-m?'X':'.';
	}
}
signed main(){
	cin>>n>>m>>T;
	while(T--){
		scanf("%lld",&x);
		putchar(doing(n,m,x));
	}
	return 0;
}