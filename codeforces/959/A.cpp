#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ld long double
#define ll long long
#define Friendy  ios_base::sync_with_stdio(false); cin.tie(0);
#define sz size
//int dis(int x1,int y1, int x2, int y2){
//    return ((x1-x2)*(x1-x2))+ ((y1-y2)*(y1-y2));
//}
//bool knowBit(int n,int i){
//return (n>>i)&1;
//}
ll sum(int n ){
    return (n*(n-1))/2;
}
ll lcm(ll a , ll b){
    return a/__gcd(a,b)*b;
}
bool isPrime(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

ll Zeros(ll n) {
    if (n == 0) return 1;
    ll cnt = 0;
    while (n) {
        if ((n & 1ll) == 0) cnt++;
        n >>= 1ll;
    }
    return cnt;
}

int main() {
    Friendy
int n; cin>>n;
cout<<(n&1 ? "Ehab\n" :"Mahmoud");
    return 0;

}
