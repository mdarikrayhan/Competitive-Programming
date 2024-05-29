#include <bits/stdc++.h> 
#define int long long
using namespace std;

void read(int &x){
	x=0;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
int T,n,m,pow10[20],dig[20];
char s[20][20];
signed main(){
	pow10[0]=1;
	for(int i=1;i<=18;i++){
		pow10[i]=pow10[i-1]*10;
	}
	read(T);
	while(T--)
	{
		read(n);
		m=0;
		for(int i=1;i<=n;i++){
			dig[i]=getchar()-'0';
			m=m*10+dig[i];
		}
		for(int i=1;i<=n;i++){
			scanf(" %s",s[i]);
		}
		int cur=0,res=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<10;j++){
				if(j!=dig[i]){
					int l;
					for(l=0;l<10 && s[i][(dig[i]+l)%10]==s[i][(j+l)%10];l++);
					res=max(res,pow10[n-i]*min(cur*10+10-max(dig[i],j),l==10?(int)4e18:l)-m%pow10[n-i]);
				}
			}
			int l;
			for(l=0;l<10 && s[i][(dig[i]+l)%10]==s[i][(dig[i]+1+l)%10];l++);
			cur=min(cur*10+10-dig[i]-1,l==10?(int)4e18:l);
		}
		printf("%lld\n",res);
	}
} //