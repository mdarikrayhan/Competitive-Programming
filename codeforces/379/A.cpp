#include<iostream>
using namespace std;
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j,k=n;
    while(n>=m)
    {
        k+=n/m;
        n=n/m+n%m;
    }
    cout<<k<<endl;
 
    return 0;
}