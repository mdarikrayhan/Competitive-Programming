#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  n-=10;
  if((n>=1&&n<=9)||n==11)
  {
    cout<<4;
  }
  else if(n==10)
  {
    cout<<15;
  }
  else
  {
    cout<<0;
  }
}

