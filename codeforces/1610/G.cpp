// LUOGU_RID: 158591275
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=233;
const int mod=998244853;
string s,f[300005];
int stmp[300005],upperid,n,val[300005],place[300005][20],prehash[300005][20],power[300005]={1},str[300005];
inline void sset(){
	
	for(int i=1;i<=n;i++){
		power[i]=1ll*power[i-1]*base%mod;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='(')stmp[++upperid]=i;
		else {
			if(upperid)val[stmp[upperid]]=i+1,upperid--;
		}
	}
}
inline void cl(int i){
	
		place[i][0]=str[i+1],prehash[i][0]=s[i],str[i]=i;
		for(int j=1;j<=18;j++){
			place[i][j]=place[place[i][j-1]][j-1];
			prehash[i][j]=(prehash[i][j-1]+1ll*prehash[place[i][j-1]][j-1]*power[(1<<j-1)])%mod;
		}
}
int main(){
	cin>>s;
	n=s.length();
	sset();
	place[n][0]=str[n]=n;
	for(int i=n-1;i>=0;i--){
		cl(i);
		if(val[i]){
			int x=i,y=str[val[i]];
			for(int j=18;j>=0;j--){
				if(prehash[x][j]==prehash[y][j]){
					x=place[x][j],y=place[y][j];
				}
			}
			if(y==n||(s[x]>s[y]))str[i]=str[val[i]];
		}
	}
	int x=str[0];
	while(x<n){
		cout<<s[x];
		x=place[x][0];
	}
	return 0;
}