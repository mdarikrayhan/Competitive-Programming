#include<bits/stdc++.h>
using namespace std;
typedef long long int i64;
i64 gcd(i64 x,i64 y){return y?gcd(y,x%y):x;}
i64 a(i64 x){return x>0?x:-x;}
i64 a(i64 x,i64 mod){x%=mod;return x>=0?x:mod-x;}
void no(){cout << "NO" << endl;}
int main(){
	i64 dx1,dx2,dy1,dy2;int n;
	cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
	i64 d = a(dx1 * dy2 - dy1 * dx2);
	if(d != n){
		no();
		return 0;
	}
	puts("YES");
	i64 g = gcd(a(dx1), a(dx2));
	for(int i=0; i<g; i++)for(int j=0; j<d/g; j++)
		printf("%d %d\n",i,j);
	return 0;
}
