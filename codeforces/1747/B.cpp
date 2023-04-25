#include <iostream>
using namespace std;

int main() {
	int T,n,I;cin>>T;
	while(T--) {
		scanf("%d",&n);
		printf("%d\n",I=n+1>>1);
		for(int i=0; i<I; ++i)printf("%d %d\n",i*3+1,n*3-i*3);
	}
}