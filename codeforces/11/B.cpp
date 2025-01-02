/*                     بسم الله الرحمن الرحيم                       */
#include<bits/stdc++.h>
#define ll long long
#define db double
#define pi 3.14159265359
#define AZBO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
using namespace std ;
int main(){
    AZBO
    int n;
    cin>>n;
    n=abs(n);
    ll x=0,cnt=0;
    while(x<n||(x-n)%2!=0)
        {
           cnt++;
           x+=cnt;
        }

cout << cnt;
}
// Made by:) Mahmoud_Azb  ^_^*/