#include<iostream>
long long n,m;
int f(){for(m=n;m&&!(m%10&&n%(m%10));m/=10);return m;}
int main(int t){for(std::cin>>t;std::cin>>n;std::cout<<n<<' ')while(f())n++;}