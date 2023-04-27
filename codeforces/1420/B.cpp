#include<ios>
#define R(X) scanf("%lli",&X)
__int64 i,n,r,t,a[37];
int L(int n){return n?1+L(n/2):0;}
int main(){
	for(R(t);r=0,t--;){
		for(R(n),i=0;i<37;i++)a[i]=0;
		for(;n--;)R(i),r+=a[L(i)]++;
		printf("%lli\n",r);
	}
}