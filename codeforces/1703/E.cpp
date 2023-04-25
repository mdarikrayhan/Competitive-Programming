#include <iostream>
using namespace std;

int main() {
	int s,q,u,a,r,e;
	for (cin>>s; s--; cout<<u<<'\n') {
		cin>>q;
		string h[q];
		a=q--;
		for (u=0; a--;) cin>>h[a];
		for (a=q+2>>1; a--;) for (r=q+1>>1; r--; u+=e>2?4-e:e) e=h[a][r]+h[r][q-a]+h[q-a][q-r]+h[q-r][a]-192;
	}
}