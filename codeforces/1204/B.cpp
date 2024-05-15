#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <string>

using namespace std;


int main()
{
    /*
    long long n,k;
    cin>>n;
    cin>>k;
    long long hi=n;
    long long low=0;
    long long mid;
    while(hi-low>1){
        mid=(hi+low)/2;
        long long s=(mid*(mid+1))/2-(n-mid);
        if(s<=k){
            low=mid;
        }else{
            hi=mid;
        }
    }
    if((hi*(hi+1))/2-n+hi==k) cout<<n-hi;
    else cout<<n-low;
*/
    int n,l,r;
    cin>>n>>l>>r;

    int low=n-l+1;
    int l1=l-1;
    int s=1;
    while(l1!=0){
        s=s*2;
        low=low+s;
        l1--;
    }
    cout<<low<<" ";

    int high=1;
    int h1=0;
    int h=1;
    while(h1!=r-1){
        h=h*2;
        high=high+h;
        h1++;
    }
    high=high+(n-r)*h;
    cout<<high;



    return 0;
}




