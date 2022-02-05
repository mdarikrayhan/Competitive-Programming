#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    long long int a,b,p,q;
    cin>>p>>q;
    if(p>q){
        a=p;
        b=q;
    }
    else{
        a=q;
        b=p;
    }
    double x=(a-b)%10;
    if(a==b){
        cout<<0<<nl;
    }
    else if(x==0){
        cout<<(a-b)/10<<nl;
    }
    else{
        cout<<((a-b)/10)+1<<nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}