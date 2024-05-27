#include<bits/stdc++.h>
#define Faster ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;





int main()
{
    Faster

    int t=1;
    //cin>>t;
    while(t--)
    {
        ll k,n,g,a;
        cin>>k;
        if(k==1e9-1)
        {
            g=1;
            n=1601;
            a=625001;
            cout<<n<<'\n';
                for(int i=1;i<1600;i++)
            cout<<0<<' ';
            cout<<-1<<' '<<a<<' ';
                continue;
        }
        if(k>=1e9-1e3)
        {
         g=1000-k%(1000);
         n=1000+g;
         a=(k+g)/1000+1;
         cout<<n<<'\n';
         for(int i=1;i<1000;i++)
            cout<<0<<' ';
         cout<<-1<<' '<<a/2<<' '<<(a+1)/2<<' ';
         for(int i=2;i<g;i++)
            cout<<0<<' ';
        continue;
        }
         g=1000-k%(1000);
         n=1000+g;
         a=(k+g)/1000+1;
         cout<<n<<'\n';
         for(int i=1;i<1000;i++)
            cout<<0<<' ';
         cout<<-1<<' '<<a<<' ';
         for(int i=1;i<g;i++)
            cout<<0<<' ';
    }
}
/*

*/
