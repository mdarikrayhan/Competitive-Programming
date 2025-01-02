#include<bits/stdc++.h>
using namespace std;
int a[200005],aa[200005];
int mn[200005][5],mx[200005][5];
int pn[200005][5],px[200005][5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(a[1]>1){
		puts("-1");
		return 0;
	}
	memset(mn,63,sizeof(mn));
	memset(mx,-63,sizeof(mx));
	mn[1][0]=mx[1][0]=1;
	for(int i=1;i<n;++i)for(int j=0;j<=4;++j){
		if(mn[i][j]>mx[i][j])continue;
		for(int s=0;s<2;++s){
			if(j==0&&s==1)continue;
			if(j==4&&s==0)continue;
			int jj=(s==0)*(j+1);
			int L=mn[i][j]+s,R=mx[i][j]+s;
			if(a[i+1]){
				L=max(L,a[i+1]);
				R=min(R,a[i+1]);
			}
			if(L<=R){
				if(mn[i+1][jj]>L){
					mn[i+1][jj]=L;
					pn[i+1][jj]=j;
				}
				if(mx[i+1][jj]<R){
					mx[i+1][jj]=R;
					px[i+1][jj]=j;
				}
			}
		}
	}
	int an=-1,mm=0;
	for(int i=1;i<=4;++i)if(mn[n][i]<=mx[n][i]){
		if(an<mx[n][i])an=mx[n][i],mm=i;
	}
	if(!mm)puts("-1");
	else{
		printf("%d\n",an);
		int wz=n,na=an,zz=mm;
		aa[wz]=na;
		while(wz>1){
			int i=wz-1,jt=-1;
			for(int j=0;j<=4;++j){
				if(mn[i][j]>mx[i][j])continue;
				for(int s=0;s<2;++s){
					if(j==0&&s==1)continue;
					if(j==4&&s==0)continue;
					int jj=(s==0)*(j+1);
					int L=mn[i][j]+s,R=mx[i][j]+s;
					if(a[i+1]){
						L=max(L,a[i+1]);
						R=min(R,a[i+1]);
					}
					if(jj==zz&&L<=na&&na<=R)jt=j;
				}
			}
			int ss=(zz!=jt+1);
			na-=ss;zz=jt;--wz;
			aa[wz]=na;
		}
		for(int i=1;i<=n;++i)printf("%d ",aa[i]);
	}
	return 0;
}