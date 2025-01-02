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
const int N=1e6+5,M=1e6+2,mo=620071201,inf=1e9+7,bs=10;
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
char s[N];
int n;
int hsh[N],qb[N];
int getval(int le,int ri){
	if(le>ri)return 0;
	return (hsh[ri]-hsh[le-1]*qb[ri-le+1]%mo+mo)%mo;
}
bool check(int le,int ri){
	if(le<=0||ri<=0||le>=ri||ri==n)return 0;
	if((s[le+1]=='0'&&le+2<=ri)||(s[ri+1]=='0'&&ri+2<=n))return 0;
	return (getval(1,le)+getval(le+1,ri))%mo==getval(ri+1,n);
}
void print(int le,int ri){
	rep(i,1,n){
		printf("%c",s[i]);
		if(i==le)printf("+");
		else if(i==ri)printf("=");
	}
}
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	qb[0]=1;
	rep(i,1,n)
	    qb[i]=qb[i-1]*10%mo;
	rep(i,1,n)
	    hsh[i]=hsh[i-1]*10%mo+s[i]-'0';
	rep(i,2,n-1){
		int len=n-i;
		if(check(len-1,i)){
			print(len-1,i);
			return 0;
		}
		if(check(len,i)){
			print(len,i);
			return 0;
		}
		if(check(i-len,i)){
			print(i-len,i);
			return 0;
		}
		if(check(i-len+1,i)){
			print(i-len+1,i);
			return 0;
		}
	}
	return 0;
}
		    	 			 		   	 		 				 	  	