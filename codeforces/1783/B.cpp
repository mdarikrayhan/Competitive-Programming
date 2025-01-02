#include <iostream>
using namespace std;

int main() {
	int s,n,a,k,e[2500];
	for (cin>>s; s--;) {
		cin>>n;
		for (a=n*n; a--;) e[a]=a&1?n*n-a/2:1+a/2;
		for (a=n; a--; puts("")) for (k=n; k--;) cout<<e[a&1?k+n*a:n-k-1+n*a]<<' ';
	}
}