// LUOGU_RID: 156992316
// Problem: Periodical Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF215E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Genshin Impact launch
// ZYB TXDY
// 
// Powered by CP Editor (https://cpeditor.org)

//%^~
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 100005
#define eps 1e-9
#define foru(a,b,c)	for(int a=b;a<=c;a++)
#define RT return 0;
#define LL long long
#define LXF int
#define RIN rin()
#define HH printf("\n")
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
inline LXF rin(){
	LXF x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){ 
	if(ch=='-') w=-1;
	ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
	x=x*10+(ch-'0');
	ch=getchar();
	}
	return x*w;
}
LL L,R;
LL a[100];
LL b[100];
LL c[100];
LL solve(LL t){
	if(t<2)	return 0;
	int len=__lg(t)+1;
	for(int i=len-1;i>=0;i--){
		b[len-i]=(t&(1ll<<i))>0;
	}
	LL ret=0;
	foru(n,2,len-1){
		foru(k,1,n-1){
			a[k]=0;
			if(n%k!=0)	continue;
			a[k]=1ll<<(k-1);
		}
		foru(k,1,n-1){
			if(n%k!=0)	continue;
			for(int j=k+k;j<=n-1;j+=k){
				if(n%j!=0)	continue;
				a[j]-=a[k];
			}
			ret+=a[k]; 
		}
	}
	foru(k,1,len-1){
		a[k]=0;
		if(len%k!=0)	continue;
		bool og=1;
		foru(i,1,len){
			if(i<=k)	c[i]=b[i];
			else	c[i]=c[i-k];
		}
		foru(i,1,len){
			if(c[i]<b[i])	break;
			if(c[i]>b[i]){
				og=0;
				break;
			}
		}
		a[k]=og;
		foru(i,1,k-1){
			if(b[i+1]!=1)	continue;
			a[k]+=(1ll<<(k-i-1));
		}
	}
	foru(k,1,len-1){
		if(len%k!=0)	continue;
		for(int j=k+k;j<=len-1;j+=k){
			if(len%j!=0)	continue;
			a[j]-=a[k];
		}
		ret+=a[k]; 
	}
	return ret;
}
signed main(){
	cin>>L>>R;
	cout<<solve(R)-solve(L-1);
	// HH;
	// foru(i,25,38){
		// cout<<i<<' '<<bitset<6>(i)<<endl;
	// }
	return 0;
}