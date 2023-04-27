#include<cstdio>
#include<algorithm>
int a,b;int main(){for(scanf("%*d");~scanf("%d%d",&a,&b);)printf("%d\n",std::min({a,b,(a+b)/3}));}