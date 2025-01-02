#include<iostream>
using namespace std;
long long T,N,K;int main(){cin>>T;while(T--)cin>>N>>K,K*=(N+K-1)/K,cout<<(K+N-1)/N<<endl;return 0;}