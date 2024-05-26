#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int mod=1000000000+7;

long long int gcd(long long int a, long long int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

long long int fast_power(long long int a,long long int x)
{
    if(x==0)
    {
        return 1;
    }
    else if(x==1)
    {
        return a%mod;
    }
    else
    {
        if(x%2==0)
        {
            long long dum=fast_power(a,x/2);
            dum=(dum*dum)%mod;
            return dum;
        }
        else
        {
            long long dum=fast_power(a,(x-1)/2);
            dum=(dum*dum)%mod;
            dum=(a*dum)%mod;
            return dum;
        }
    }
}

long long int inverse_mod(long long int a)
{
    return fast_power(a,mod-2);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    unsigned long long int i,j,n,H;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>H;
        unsigned long long b=2*1000000000+1;
        unsigned long long a=1;
        unsigned long long ans=-1; 
        while(a<b)
        {
            unsigned long long int x= (a+b)/2;
            if(x<=H)
            {
                unsigned long long max_ans=(x*(x+1))/2;
                if(max_ans>=n)
                {
                    ans=x;
                    b=x;
                }
                else
                {
                    a=x+1;
                }
            }
            else
            {
                unsigned long long max_ans=(H*(H+1))/2;
                max_ans+=(x-H)*H;
                i=(x-H-1)/2;
                j=x-H-1-i;
                max_ans+=(i*(i+1))/2;
                max_ans+=(j*(j+1))/2;
                if(max_ans>=n)
                {
                    ans=x;
                    b=x;
                }
                else
                {
                    a=x+1;
                }
            }
        }

        cout<<ans<<"\n";

        
    }
    

    return 0;
}