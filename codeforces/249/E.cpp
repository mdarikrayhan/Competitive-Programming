#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const long long mod=(long long)1e+11;
const long long rev3=66666666667LL;
inline long long T(long long a,long long b){
	return ((a*b-(long long )((long double)a*b/mod)*mod+mod)%mod);
}
inline long long C(long long x,long long y){
	if(x>=y){
		return T(T(T(4,x)+T(3,T(x,x))+T(2,T(x,T(x,x)))-y-T(3,T(x,y))+T(y,T(y,y))+mod+mod,y),rev3*5);
	}else{
		return T(T(T(x,T(x,x))-x+T(4,y)+T(3,T(x,y))-T(3,T(y,y))+T(2,T(y,T(y,y)))+mod+mod,x),rev3*5);
	}
}
inline long double W(long double x,long double y) {
	if(x>=y){
		return (4*x+3*x*x+2*x*x*x-y-3*x*y+y*y*y)*y/6;
	}else{
		return (x*x*x-x+4*y+3*x*y-3*y*y+2*y*y*y)*x/6;
	}
}
int main(){
	int T,a,b,c,d;
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		long long t=(C(c,d)-C(c,b-1)-C(a-1,d)+C(a-1,b-1)+mod+mod)%mod;
		if(W(c,d)-W(c,b-1)-W(a-1,d)+W(a-1,b-1)<1e+10){
			printf("%I64d\n",t/10);
		}else{
			printf("...%010I64d\n",t/10);
		}
	}
	return 0;
}
/*

in:
5
1 1 1 1
2 2 3 3
2 3 5 6
100 87 288 2002
4 2 5 4

out:
1
24
300
...5679392764
111

*/