// LUOGU_RID: 144671306
#include<cstdio>
using namespace std;
int dd,mm,yy,bd,bm,by;
int day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int d,int m,int y){
	if(d<1||d>day[m]+(m==2&&y%4==0)||m<1||m>12||y<1||y>99)
	return false;
	return (yy-y>18||(yy-y==18&&m<mm)||(d<=dd&&m==mm&&yy-y==18));
}
int main(){
	scanf("%d.%d.%d",&dd,&mm,&yy);
	scanf("%d.%d.%d",&bd,&bm,&by);
	if(check(bd,bm,by)||check(bd,by,bm)||check(bm,bd,by)||check(bm,by,bd)||check(by,bd,bm)||check(by,bm,bd))
	printf("YES");
	else
	printf("NO");
	return 0;
}