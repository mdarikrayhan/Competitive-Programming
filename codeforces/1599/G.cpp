#include<bits/stdc++.h>
#define db double
using namespace std;
struct node{db x,y;}a[200010],s;
int n,k;
db ans;
bool cmp(node x,node y){return x.x!=y.x?x.x<y.x:x.y<y.y;}
db dis(int x,int y){return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));}
bool check(int x,int y,int z){return fabs((a[x].x-a[y].x)*(a[x].y-a[z].y)-(a[x].x-a[z].x)*(a[x].y-a[y].y))<=1e-8;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	s=a[k];
	if(n>3){
		if(!check(1,2,3)&&!check(1,2,4))swap((check(1,3,4)?a[2]:a[1]),a[n]);
		else for(int i=3;i<n;i++)if(!check(1,2,i))swap(a[i],a[n]);
	}else swap(a[k],a[n]);
	sort(a+1,a+n,cmp);
	for(int i=1;i<=n;i++)if(a[i].x==s.x&&a[i].y==s.y)k=i;
	if(k==n)printf("%.8lf",min(dis(1,n),dis(n-1,n))+dis(1,n-1)),exit(0);
	ans=min(dis(1,k)+dis(n-1,n),dis(k,n-1)+dis(1,n))+dis(1,n-1);
	for(int i=2;i<=k;i++)ans=min(ans,min(dis(k,n-1)+dis(i,n),dis(i,k)+dis(n-1,n))+dis(i,n-1)+dis(i-1,n)+dis(1,i-1));
	for(int i=k;i<n-1;i++)ans=min(ans,min(dis(1,k)+dis(i,n),dis(k,i)+dis(1,n))+dis(1,i)+dis(i+1,n)+dis(i+1,n-1));
	printf("%.8lf",ans);
	return 0;
}