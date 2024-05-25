#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define po pop_back
#define f1 first
#define s2 second
#define PI 3.1415926535897932384626433832795l
//this func will tell s2 is a substring in s1 or not
ll fss(string s1, string s2){
    if(s1.find(s2) != string::npos)
        return s1.find(s2);
    return -1;
}
//this will provide a string which will be 
//reversed binary conversion of numbers till 10^18
string dec_to_bin(ll x){
    string str="";
    while(x>0){
        if(x%2==1) str.push_back('1');
        else str.push_back('0');
        x=x/2;
    }
    ll k=64-str.size();
    while(k--) str.push_back('0');
    return str;
}
//Lexicographically largest sub-sequence of the given string
string getLexLarSubSeq(string s,ll n){
    stack<char> st;
    for(ll i=0;i<n;i++){
        while (!st.empty() && s[i] > st.top())
            st.pop();
        st.push(s[i]);
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
void print_vec(vector<ll> &v){
    for(ll i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void print_pair_vec(vector<pair<ll,ll>> &v){
    for(ll i=0;i<v.size();i++){
        cout<<v[i].f1<<" "<<v[i].s2<<endl;               
    }
}
//prints stack from top to bottom
void print_stack(stack<ll>s){
    if(s.empty()){
        cout<<endl;
        return;
    }
    ll x = s.top();
    s.pop();
    cout<<x<<" ";
    print_stack(s);
    s.push(x);
}
ll maxx(ll a, ll b){if(a>=b) return a; return b;}
ll minn(ll a, ll b){if(a<=b) return a; return b;}
void swap(ll &x,ll &y){
    ll t=x;x=y;y=t;
}
const ll M = 1e9+7;
ll bin_mul_mod(ll a,ll b,ll m){
    ll ans=0;a = a%m;
    while(b>0){
        if(b&1) ans=(ans+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}
ll bin_exp_mod(ll a,ll b,ll m){
    ll result = 1;a = a%m;
    while(b){
        if(b&1) result=(result*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return result;
}
//SIEVE ALGORITHMS
const ll N = 1e7+10;
/*vector<bool> isPrime(N,1);
vector<ll> lp(N,0);
vector<ll> hp(N,0);
void SeiveAlgo(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i<N;i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i;
            for(ll j=i*2;j<N;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }
}*/  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);cout.tie(nullptr);
  //SeiveAlgo();
  ll n;cin>>n;
  ll arr[n][n];ll sum=0,minm=INT_MAX;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
        sum+=arr[i][j];
        if(i+j==n-1) minm=minn(minm,arr[i][j]);
    }
  }
  cout<<sum-minm<<endl;
}
   
    




















































    
  
    


       
       
    

            

    


 

 




            

    


 

 
