#include<bits/stdc++.h>
using namespace std;
int main(){
	double a[11];
	for(int i=0;i<11;++i)cin>>a[i];
	for(int i=10;i>=0;--i)a[i]<5?printf("f(%d) = %.2lf\n",(int)a[i],5.*a[i]*a[i]*a[i]+sqrt(fabs(a[i]))):printf("f(%d) = MAGNA NIMIS!\n",(int)a[i]);
}