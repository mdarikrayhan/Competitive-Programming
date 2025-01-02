#include <bits/stdc++.h>
using namespace std;
#define  ll  long long
#define ld long double
const ll MOD=1e8;
const int mxn=2e5+100;
#define tt int tt;cin>>tt;while(tt--)



void sol(){

    ll n,m;cin>>n>>m;

    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    string s;
    for(int i=0;i<m;i++)s+='B';

    for(int i=0;i<n;i++){
        int x=a[i]-1;
        int y=m-a[i];
        if(x>y)swap(x,y);
        if(s[x]=='B')s[x]='A';
        else s[y]='A';
    }

cout<<s<<"\n";




}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    tt
        sol();
}

/*



 */