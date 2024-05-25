#include<cstdio>
using namespace std;
int main(){
	double a,d,x,y;
	int n;long long m;
	scanf("%lf%lf%d",&a,&d,&n);
	for(int i=1;i<=n;i++){
		x=d*i;
		m=(long long)(x/a);
		//printf("%d %d\n",i,m);
		if(m%4==0){
			x-=m*a;y=0.0;
		}else if(m%4==1){
			y=x-m*a;x=a;
		}else if(m%4==2){
			y=a;x=a-(x-m*a);
		}else{
			y=a-(x-m*a);x=0.0;
		}
		printf("%.9lf %.9lf\n",x,y);
	}return 0;
}