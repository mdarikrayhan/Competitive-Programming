#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int max(long long int a, long long int b)
{
    if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    long long int n, m, k;
    cin>>n>>m>>k;
    if(k>3)
    {
        cout<<0<<endl;
    }
    else if(k==3)
    {
        cout<<max(0,(m-n+1)-(m/n))<<endl;
    }
    else if(k==2)
    {
        cout<<max(0,m/n-1)+min(m,n)<<endl;
    }
    else if(k==1) cout<<1<<endl;
    }
}