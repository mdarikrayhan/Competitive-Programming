#include <bits/stdc++.h>
using namespace std;
map<long long,long long>mp;
map<long long,long long>mp2;
set<long long>st;
pair<long long ,long long>pr[210000];
vector<long long >vec1;
vector<long long >vec2;
char a[210000],b[1010];
main()

{
long long t,n,k=0,l,sum=0,p=0,r,bg=1,mx=0,mn=2000000000,tp=0,cou=0,b=0,m=0;
cin>>t;
while(t--)
{
    cin>>n;
   
    if(n%2==1)
        for(int i=0;i<n;i++)
        {
            cout<<7<<" ";
        }
   
   else 
    {cout<<3<<" "<<1<<" ";
        for(int i=0;i<n-2;i++)
        {
            cout<<2<<" ";
        }
        }
    cout<<endl;

}

}