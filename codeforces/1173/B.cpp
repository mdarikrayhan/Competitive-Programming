#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int power(int x, int n){
    int result = 1;
    while (n > 0) {
        if (n & 1 == 1){
            result = (result * x);
        }
        x = (x * x);
        n = n >> 1;
    }
    return result;
}

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

    /*int t;
    cin>>t;
    for(int j=0;j<t;j++){
        long long d,x;
        cin>>d>>x;

        long long s=power(2,d);
        long long c=1;

        while(s!=x&&d>=0){
            if(x>s){
                d--;
                s=s+power(2,d);
                c++;
            }else{
                d--;
                s=s-power(2,d);
                c++;
            }
        }
        if(s==x){
            cout<<"Case "<<j+1<<": "<<"YES "<<c<<endl;
        }else{
            cout<<"Case "<<j+1<<": "<<"NO "<<endl;
        }
    }*/

    int n;
    cin>>n;
    int b=n-1;
    if(b%2==1){
        b=b+3;
        b=b/2;
        cout<<b<<endl;
    }else{
        b=b+2;
        b=b/2;
        cout<<b<<endl;
    }
    int x=1;
    int y=1;

    for(int i=0;i<n;i++){
        cout<<x<<" "<<y<<endl;
        if(x<b){
            x++;
        }else{
            y++;
        }
    }



    return 0;
}




