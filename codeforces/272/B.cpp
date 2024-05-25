#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    long long n,ans[40]={0},t=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>t;
            ans[__builtin_popcount(t)]++;
    }
long long anse=0;
for(int i=0;i<40;i++)
{
    if(ans[i]==2)
    anse++;
    else
    anse+=ans[i]*(ans[i]-1)/2;
}
cout<<anse<<endl;
    return EXIT_SUCCESS;
}
