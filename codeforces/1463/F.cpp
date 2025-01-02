// LUOGU_RID: 160470738
#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int f[2][(1<<22)+5];
inline void Max(int &a,int b){if(a<b)a=b;}
int main(){
	scanf("%d %d %d",&n,&x,&y);
	int sum=x+y;
	if(x>y)swap(x,y);
	int mx=(1<<y)-1,base=n/sum,rem=n%sum;
	int pre=0,cur=1;
	for(int i=0;i<sum;++i,pre^=1,cur^=1){
		memset(f[cur],0,(mx+1)<<2);
		int a=base+(i<rem);
		for(int s=0;s<=mx;++s){
			Max(f[cur][(s<<1)&mx],f[pre][s]);
			if(!(s&(1<<(x-1)))&&!(s&(1<<(y-1))))
				Max(f[cur][((s<<1)&mx)|1],f[pre][s]+a);
		}
	}
	int ans=0;
	for(int s=0;s<=mx;++s)Max(ans,f[pre][s]);
	printf("%d",ans);
	return 0;
}