#include<bits/stdc++.h>
using namespace std;
int main()
{
   int N,K,X,Y;
   cin>>N>>K>>X>>Y;
   if(N<=K)
   {
       cout<<X*N;
   }
   else
   {
       cout<<(X*K)+((N-K)*Y);
   }

}




