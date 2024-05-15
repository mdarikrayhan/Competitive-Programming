#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define f first
#define s second
const int mod=1e9+7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
}

int ceil_div(int a,int b){
    return a%b==0?a/b:a/b+1;
}

int gcd(int a,int b){
    if(!a||!b)return a^b;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

void solve(){
    int n,x;
    cin>>n>>x;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum1+=a;
        sum2+=ceil_div(a,x);
    }
    cout<<ceil_div(sum1,x)<<' '<<sum2;
}

signed main(){
    fast();
    int T=1;
    cin>>T;
    for(int tests=1;tests<=T;tests++){
        solve();
        cout<<'\n';
    }
    return 0;
}