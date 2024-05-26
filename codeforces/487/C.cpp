#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef long long ll;
const int N=20005,M=40005,inf=1e9+7,bs=19491001;
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
int quick_power(int base,int x){
	int res=1;
	while(x){
		if(x&1)res*=base,res%=n;
		base*=base,base%=n;
		x>>=1;
	}
	return res;
}
bool check(){
	rep(i,2,sqrt(n))
		if(n%i==0)return 0;
	return 1;
}
signed main(){
	read(n);
	if(n==4){
		printf("YES\n1\n3\n2\n4");
		return 0;
	}
	if(!check()){
		puts("NO");
		return 0;
	}
	puts("YES");
	puts("1");
	rep(i,2,n-1)
	    printf("%lld\n",(i-1)*quick_power(i,n-2)%n);
	if(n!=1)printf("%lld\n",n);
	return 0;
}
 	 				   	 	 	 	 	  	 	 	 	