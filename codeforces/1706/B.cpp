#include <iostream>
#define I std::cin>>

int main() {
	int t,n;
	for (I t; t--;) {
		I n;
		int i=n,m,p=1,c[n],h[n];
		for (; i--; h[i]=0) I c[i];
		for (i=n; i--; p=!p) h[n-c[i]]=!(m=h[n-c[i]])|p^m<0?-m-(p?1:-1):m;
		for (; n--; std::cout<<(m>0?m:-m)<<' ') m=h[n];
	}
}