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
    int n,k;
    cin>>n>>k;
    int tf,tb;
    if(n%2)tf=n/2,tb=n-tf;
    else tf=n/2-1,tb=n-tf;
    multiset<int> s[k];
    vector<int> a[k];
    deque<int> q;
    for(int i=0;i<n*k;i++){
        int x;
        cin>>x;
        q.push_back(x);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<tf;j++){
            int x=q.front();
            q.pop_front();
            s[i].insert(x);
        }
        for(int j=0;j<tb;j++){
            int x=q.back();
            q.pop_back();
            s[i].insert(x);
        }
    }
    for(int i=0;i<k;i++){
        for(auto x:s[i])a[i].push_back(x);
    }
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i][tf];
    }
    cout<<sum;
}

signed main(){
    fast();
    int T=1;
    cin>>T;
    for(int tests=1;tests<=T;tests++){
        //cout<<"Case #"<<tests<<": \n";
        solve();
        cout<<endl;
    }
    return 0;
}