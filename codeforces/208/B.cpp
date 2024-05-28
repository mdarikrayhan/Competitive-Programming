#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
char a[60][2];
int f[60][60][60][60];
int check(int i,int j){
	if(a[i][0]==a[j][0]||a[i][1]==a[j][1])return 1;
	return 0;
}
int dfs(int s,int aa,int bb,int cc){
	if(s==1)return 1;
	if(f[s][aa][bb][cc])return 0;
	if(check(aa,bb)){
		if(dfs(s-1,aa,cc,s-3))return 1;
	}
	if(s>3&&check(aa,s-3)){
		if(dfs(s-1,bb,cc,aa))return 1;
	}
	f[s][aa][bb][cc]=1;
	return 0;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	if(dfs(n,n,n-1,n-2))cout<<"YES";
	else cout<<"NO";
}



 		 		 					 		   	 					 		 	