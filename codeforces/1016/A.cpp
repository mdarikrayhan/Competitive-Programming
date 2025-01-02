#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long m,n,t,p,s=0;
    cin>>n>>m;
    
    while(n--)
    {
        cin>>t;
        p=(s+t)/m - s/m;
        s+=t;
        cout<<p<<" ";
    }
    
    return 0;
}
