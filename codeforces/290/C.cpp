// LUOGU_RID: 159239324
#include<bits/stdc++.h>
using namespace std;
double n,m,a=0,b=0,c=0,d=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		a+=m;
		b++;
		if(a*d>c*b){
			c=a;
			d=b;
		}
	}
	printf("%.6lf",c/d);
	return 0;
}