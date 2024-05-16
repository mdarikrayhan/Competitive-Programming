#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long x=n;
        int cnt=0;
        while (x>0)
        {
            x/=10;
            cnt++;
        }
        x=1;
        for(int i=0; i<cnt-1; i++)
            x*=10;
        cout <<n-x<<"\n";
    }
    return 0;
}