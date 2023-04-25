#include <cstdio>
const int N=5e5;
int n,x,a[N+1],w;
int main(){
scanf("%d %d",&n,&x);
while(n--)scanf("%d",&w),++a[w];
for(int i=1;i<x;++i){
if(a[i]%(i+1)!=0){
puts("No");
return 0;
}
a[i+1]+=a[i]/(i+1);
}
puts("Yes");
}