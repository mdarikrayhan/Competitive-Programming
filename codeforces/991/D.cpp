//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: Md. Abu Farhad ( RUET, CSE'15)
 ** @Category:
/** ========================================**/

#include<bits/stdc++.h>
#include<stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld",&n)
#define scc(c)	            scanf("%c",&c)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define pb                  push_back
#define debug               cout<<"I am here"<<endl;
#define pno                 cout<<"NO"<<endl
#define pys                 cout<<"YES"<<endl

#define l(s)                s.size()
#define asort(a)            sort(a,a+n)
#define all(x) 	            (x).begin(), (x).end()
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)           sort(v.begin(), v.end());
#define vdsort(v)           sort(v.begin(), v.end(),greater<int>());
#define uniquee(x)          x.erase(unique(x.begin(), x.end()),x.end())
#define pn                  printf("\n")
#define el                  cout<<endl
#define md                  1000000007
#define inf                 9e18
#define ps                  cout<<" ";
#define Pai                  acos(-1.0)
#define pr                  pair<ll, ll>
#define ff                  first
#define ss                  second
#define mem(a,i)            memset(a, i, sizeof(a))
#define tcas(i,t)           for(ll i=1;i<=t;i++)
#define pcas(i)             cout<<"Case "<<i<<": "<<endl;
#define fast 	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int main()
{
    ll t;

    ll m,n,c,d,i,j,k,x,y,z,l,q,r;
    string s,s1, s2, s3, s4 , a, b;
    ll cnt=0,ans=0,sum=0;

    cin>>s>>s1;

    fr(i, s.size()-1)
    {
        if(s[i]=='0'  and s[i+1]=='0' )
        {
            if(s1[i]=='0' )s[i]=s[i+1]=s1[i]='2' , cnt++;
            else if(s1[i+1]=='0' )s[i]=s[i+1]=s1[i+1]='2' , cnt++;
        }

        if(s1[i]=='0'  and s1[i+1]=='0' )
        {
            if(s[i]=='0' )s1[i]=s1[i+1]=s[i]='2' , cnt++;
            else if(s[i+1]=='0' )s1[i]=s1[i+1]=s[i+1]='2' , cnt++;
        }
    }

    cout<<cnt<<endl;

return 0;
}

///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1




