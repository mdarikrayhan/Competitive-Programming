#import<iostream>
int rs[300013],t=0,n,i;
void o(int l,int r){
int l_=l,r_=--r;
while(l<=r){
for(i=r-1;i>=l;i--)rs[++t]=i%n;
for(i=l+1;i<r;i++)rs[++t]=i%n;
l++,r--;
}
for(i=l_;i<(l_+r_)/2;i++)rs[++t]=i%n;
}
int main(){
std::cin>>n;
o(0,n),o((n+1)/2,n/2+n),o(0,n);
for(std::cout<<t<<'\n',i=1;i<=t;i++)std::cout<<rs[i]<<' ';
}