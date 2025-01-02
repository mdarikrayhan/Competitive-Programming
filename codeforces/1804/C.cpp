#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rev(a) reverse(a.begin(),a.end())
#define s1(a) sort(a.begin(),a.end())
#define s2(a,n) sort(a,a+n)
#define pb push_back
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define g(x,y) __gcd(x,y)
using namespace std;
 
bool mycomparer(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.first < rhs.first) {
        return true;
    }
    else if (lhs.first == rhs.first && lhs.second > rhs.second) {
        return true;
    }
    else {
        return false;
    }
}
 
bool isPrime(ll n) {
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
ll div(ll n) {
    ll m = 0;
    while (n % 2 == 0) {
        n = n / 2;
        m++;
    }
    return m;
}
 
ll mod = 1e9 + 7;
const int N= 1e5+10;
int dp[N];
int h[N];
int amount(int coins,int n){
    if (coins=0) return 0;
    int ans=0;int x=0;
    for(int i=0;i<n;i++){
        if(coins-h[i]>=0){

        ans=amount(coins-h[i],n);
        if(ans==0){
            x++;
        }
        }
    }return x;
}

int main(){
    int t;cin>>t;
    while(t--){
        ll n,x,p;
        cin>>n>>x>>p;ll c=0;
        for(ll i=1;i<=min(2*n,p);i++){
            ll num1= (i*i + i)/2;
            ll num2= num1-(n-x);
            ll num3= num1 + x;
            // cout<<num1<<" "<<num2<<endl;
            if(num2%n==0|| num3==n){
                c=1;
                break;
            }
        }
        if(c==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
   
}