#include <iostream>

#include <algorithm>

using namespace std;
int main()
{
int a;
cin>>a;
int x;
for(int i=0;i<a;i++)
{
    cin>>x;
    if(x%2==0)
    cout<<x/2<<endl;
    else
    cout<<(x-1)/2<<endl;
}
    return 0;
}