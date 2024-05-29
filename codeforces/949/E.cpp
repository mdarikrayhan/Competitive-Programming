#include"bits/stdc++.h"
#define int long long
const int N=1e5+10;
using namespace std;
int ans[N],cnt,lj[N];
int n,m=1e9;
int a[21][N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();} 
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();} 
	return x*f;
}
void dfs(int digi,int len){
	if(!a[digi][1]&&len<=1){
		if(cnt<m){
			m=cnt;
			for(register int i=1;i<=m;i++)ans[i]=lj[i];
		}
		return;
	}
	if(digi>20||cnt>m)return;
	int fl=0;
	for(register int i=1;i<=len;i++)if(a[digi][i]&1){fl=1;break;}
	if(!fl){
		for(register int i=1;i<=len;i++)a[digi+1][i]=a[digi][i]>>1;
		int pos=unique(a[digi+1]+1,a[digi+1]+len+1)-a[digi+1]-1;
		dfs(digi+1,pos);
	}else{
		lj[++cnt]=-(1<<digi);
		for(register int i=1;i<=len;i++){
			if(a[digi][i]&1)a[digi+1][i]=(a[digi][i]+1)>>1;
			else a[digi+1][i]=a[digi][i]>>1;
		}
		int pos=unique(a[digi+1]+1,a[digi+1]+len+1)-a[digi+1]-1;
		dfs(digi+1,pos);cnt--;
		lj[++cnt]=1<<digi;
			for(register int i=1;i<=len;i++){
			if(a[digi][i]&1)a[digi+1][i]=(a[digi][i]-1)>>1;
			else a[digi+1][i]=a[digi][i]>>1;
		}
		pos=unique(a[digi+1]+1,a[digi+1]+len+1)-a[digi+1]-1;
		dfs(digi+1,pos);cnt--;
	}
}
signed main(){
	n=read();
	for(register int i=1;i<=n;i++)a[0][i]=read();
	sort(a[0]+1,a[0]+n+1);
	n=unique(a[0]+1,a[0]+n+1)-a[0]-1; 
	dfs(0,n);
	printf("%lld\n",m);
	for(register int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}
	 	   	 							 	    			 	  	 	