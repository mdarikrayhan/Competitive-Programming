#include<iostream>
enum{P=1000000007};
int f[5009],n,i,j,k,z,iv=1;
int main(){
 for(std::cin>>n>>k,i=n,j=P-2;j;j>>=1,i=1ll*i*i%P)if(j&1)iv=1ll*iv*i%P;
 for(*f=i=1;i<=n;*f=1ll**f*z%P,++i)for(std::cin>>z,j=i;j;--j)f[j]=(1ll*z*f[j]%P-f[j-1]+P)%P;
 for(z=i=0,j=1;i<=n;++i,j=1ll*j*iv%P*k--%P)z=(z+1ll*f[i]*j%P)%P;
 std::cout<<(*f-z+P)%P;
}