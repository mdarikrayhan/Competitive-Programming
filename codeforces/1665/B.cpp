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
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x]++;
    }
    if(m.size()==1){
        cout<<0;
        return;
    }
    int maxf=0,ans=0;
    for(auto i:m){
        maxf=max(maxf,i.s);
    }
    while(maxf<n){
        ans+=1+min(n-maxf,maxf);
        maxf+=min(n-maxf,maxf);
    }
    cout<<ans;
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