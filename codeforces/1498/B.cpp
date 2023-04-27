#include<bits/stdc++.h>
using namespace std;
int t,n,w,x,y,z,a[32];
int main() {
for(scanf("%d",&t); t--; printf("%d\n",y)) {
for(scanf("%d%d",&n,&w),z=n; z--;
scanf("%d",&x),++a[__builtin_ctz(x)]);
for(y=0; n; ++y)
for(z=20,x=w; x&&~z; --z)
for(; (x>>z)&&a[z]; --n,--a[z],x-=1<<z);
}
exit(0);
}