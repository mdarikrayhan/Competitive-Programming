#include<cstdio>
int n,a,i,s;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%1d",&a),s+=a==(i&1);
    printf("%d",s<n-s?s:n-s);
}