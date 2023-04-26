#include<bits/stdc++.h>
#define end return void(puts("NO"));
using namespace std;const int N=505;
int a[N],b[N],n,i,j,k,x,y,f,it,T_T;vector<pair<int,int>>ans;
void D(int l,int r){ans.push_back(make_pair(l,r));reverse(a+l,a+r+1);}
void go(){
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	if(a[1]!=b[1])end;
	for(i=2;i<=n;++i)if(a[i]!=b[i]){
		x=b[i-1],y=b[i];f=0;it=-1;
		for(j=i;j<n;++j)if(a[j]==y&&a[j+1]==x){f=1;D(i-1,j+1);break;}else if(a[j]==x&&a[j+1]==y)it=j;
		if(f)continue;
		if(it==-1)end;
		for(j=i-1;j<=it;++j)for(k=it+1;k<=n;++k)if(a[j]==a[k]&&!f){f=1;D(j,k);break;}
		if(!f)end;
		for(j=i;j<n;++j)if(a[j]==y&&a[j+1]==x){
			D(i-1,j+1);break;
		}
	}
	puts("YES");
	printf("%d\n",ans.size());
	for(auto&x:ans)printf("%d %d\n",x.first,x.second);
}
int main(){
	for(scanf("%d",&T_T);T_T--;ans.clear())go();
}