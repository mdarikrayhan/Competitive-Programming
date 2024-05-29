#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
//int val[200010];
int ans,n;
struct u2003{
	int a,b;
}val[200010];
bool cmp(u2003 x,u2003 y){
	return x.a+x.b>y.a+y.b;
}
int cnt;
signed main(){
	scanf("%lld",&n);
	int a1,a2,b1,b2;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&a1,&b1,&a2,&b2);
		if(a1+b1<a2+b2){
			if(a1-b2>0)ans+=a1-b2;
			else if(b1-a2>0)ans+=a2-b1;
		}
		else{
			val[++cnt].a=a1;
			val[cnt].b=b1;
			val[++cnt].a=a2;
			val[cnt].b=b2;
		}
		
	}
	sort(val+1,val+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(i&1)ans+=val[i].a;
		else ans-=val[i].b;
	}
	printf("%lld\n",ans);
	return 0;
}
   			 		 	  		     							 		