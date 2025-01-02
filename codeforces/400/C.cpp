#include<cstdio>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	int n,m,x,y,z,p,a,b,x1,y1,n1,m1,t;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	x%=4;y%=2;z%=4;
	for(int i=0;i<p;i++){
		scanf("%d%d",&a,&b);n1=n;m1=m;
		for(int i=0;i<x;i++){
			x1=b;y1=n1-a+1;
			t=n1;n1=m1;m1=t;
			a=x1;b=y1;
		}if(y)b=m1-b+1;
		for(int i=0;i<z;i++){
			x1=m1-b+1;y1=a;
			t=n1;n1=m1;m1=t;
			a=x1;b=y1;
		}printf("%d %d\n",a,b);
	}return 0;
} 