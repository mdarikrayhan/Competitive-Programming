#include<cstdio>
using namespace std;
struct str{
	int l,r,id;
}t[3005];
int T,n,a[1005][1005],m,fr[1005],f[1005],ans[1005],b[1005],rec[1005],cnt;
int hash(int num1,int num2,int num3){
	if(num1==0)num1=10;if(num2==0)num2=10;if(num3==0)num3=10;
	if(num1==-1)num1=0;
	return num1*121+num2*11+num3;
}
void init(){
	cnt=0;
	for(int i=1;i<=3000;i++)t[i].id=t[i].l=t[i].r=0;
	for(int i=1;i<=1000;i++)fr[i]=f[i]=ans[i]=b[i]=rec[i]=0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){			
			for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);
			
			for(int j=2;j<=m;j++){
				int num=hash(-1,a[i][j-1],a[i][j]);
				t[num].l=j-1;t[num].r=j;t[num].id=i;
			}
			for(int j=3;j<=m;j++){
				int num=hash(a[i][j-2],a[i][j-1],a[i][j]);
				t[num].l=j-2;t[num].r=j;t[num].id=i;
			}
		}
		for(int i=1;i<=m;i++)scanf("%1d",&b[i]);
		f[0]=1;
		for(int i=2;i<=m;i++){
			if(f[i-2]){
				int num=hash(-1,b[i-1],b[i]);
				if(t[num].id!=0){
					f[i]=f[i-2]+1;fr[i]=i-2;ans[i]=num;
				}
			}
			if(i==2)continue;
			if(f[i-3]){
				int num=hash(b[i-2],b[i-1],b[i]);
				if(t[num].id!=0){
					f[i]=f[i-3]+1;fr[i]=i-3;ans[i]=num;
				}
			}
		}
		if(f[m]==0){
			printf("-1\n");
			continue;
		}
		printf("%d\n",f[m]-1);
		int now=m;
		while(now){
			rec[++cnt]=now;
			now=fr[now];
		}
		for(int i=cnt;i>=1;i--)
		printf("%d %d %d\n",t[ans[rec[i]]].l,t[ans[rec[i]]].r,t[ans[rec[i]]].id);
	}
	return 0;
}