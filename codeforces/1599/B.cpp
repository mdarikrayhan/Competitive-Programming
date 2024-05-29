#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,A,B;
int main()
{
	int T;char s[10];scanf("%d",&T);
	while(T--) scanf("%lld%lld%lld%s%s",&n,&A,&B,s,s),printf("%lld\n",((B-A)&1)^(A<B)?n-1:0);return 0;
}