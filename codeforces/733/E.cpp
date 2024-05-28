#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) lson[x]
#define rs(x) rson[x]
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef long long ll;
const int N=1e6+5,M=1e6+2,mo=1e9+7,inf=1e9+7,bs=19491001;
const double eps=1e-8;
inline void read(int &p){
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	p=x*w;
}
int n;
char s[N];
queue<int>le,ri;
int disl,disr,sumd[N],sumu[N];
int ans[N];
signed main(){
	read(n);
	scanf("%s",s+1);
	rep(i,1,n)
	    sumu[i]=sumu[i-1]+(s[i]=='U');
	repp(i,n,1)
	    sumd[i]=sumd[i+1]+(s[i]=='D');
	rep(i,1,n){
		if(s[i]=='U'){
			if(sumu[i-1]>=sumd[i+1])ans[i]=n-i+1;
			else ans[i]=i;
		}
		else{
			if(sumu[i-1]>sumd[i+1])ans[i]=n-i+1;
			else ans[i]=i;
		}
	}
	rep(i,1,n){
		disl+=le.size();
		while(le.size()>sumd[i])
		    disl-=(i-le.front()),le.pop();
		ans[i]+=disl*2;
		if(s[i]=='U')le.push(i);
	}
	repp(i,n,1){
		disr+=ri.size();
		while(ri.size()>sumu[i])
		    disr-=(ri.front()-i),ri.pop();
		ans[i]+=disr*2;
		if(s[i]=='D')ri.push(i);
	}
	rep(i,1,n)
	    printf("%lld ",ans[i]);
	return 0;
}
		 			  	     			 	    	  	 		