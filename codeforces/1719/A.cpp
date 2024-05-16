#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m;

        cin>>n>>m;

        if((m+n)%2==0)
        {
            cout<<"Tonya"<<endl;
        }
        else
        {
            cout<<"Burenka"<<endl;
        }
    }
}