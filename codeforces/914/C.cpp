#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
  
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // find_by_order, order_of_key


typedef long long ll;
typedef vector<int > vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<long long,long long > pll;
typedef vector<pair<ll,ll>> vpll;
typedef priority_queue<ll> pqll;
typedef deque<ll> dqll;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqrll;
#define fr(i,n,a) for(long long i=a; i<n; i++)
#define ufr(i,n,a) for(long long i=n-1; i>=a; i--)
#define vout(v) for(auto &e:v){cout<<e<<" ";} cout<<"\n";
#define mout(mp) for(auto &e:mp){cout<<e.first<<"------>"<<e.second<<"\n";} cout<<endl;
#define mvout(mp) for(auto &e:mp){cout<<e.first<<"----->\n"; for(long long i =0 ; i<(e.second).size();i++){cout<<(e.second)[i]<<" ";} cout<<"\n";} cout<<"\n";
#define Sort(a) sort(a.begin(),a.end())
#define be(a) a.begin(),a.end()
#define Sorta(a,n) sort(a,a+n)
#define pb push_back  
#define pf push_front
#define F first
#define S second 
const ll M = 1000000000+7;
const int N = 1000001;

 
// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
ll power(ll x, ll y)
{
    ll res = 1; // Initialize result
 
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x; // Change x to x^2
    }
    return res;
}





int countdigits(ll x){
    ll y=x;
    int c=0;
    while(y>0){
        c++;
        y=y/10;
    }
    return c;
}
#ifndef ONLINE_JUDGE
    #include </home/mayukh/Documents/Contests/debug.h> // replace with your path
#else
    #define debug(x...) 
    #define debuga(...)
#endif


    

void solve(){

    string s;
    cin>>s;
    ll k;
    cin>>k;

    if(k>5){
        cout<<0<<"\n";
        return;

    }
    if(k==0){
        cout<<1<<"\n";
        return;

    }
    deque<ll>dq0;
    dq0.pb(1);

    deque<ll>dq;
    fr(i,10,1){
        dq.pb((1<<i));
    }
    deque<ll>dq1;
    deque<ll>dq2;
    deque<ll>dq3;
    while(dq2.size()>0 && dq2.front()<10){
        fr(i,1000,power(2,dq2.front())-1){
            if(__builtin_popcount(i)==dq2.front()){
                dq3.pb(i);

            }

        }
        dq2.pop_front();



    }

    ll ans= 0;
    if(k==1){
        
        while(dq0.size()>0){
            ll cum =0;
            fr(i,s.length(),0){
                if(s[i]=='1'){
                    if(dq0.front()-cum>=0 && s.length()-1-i>=dq0.front()-cum){
                        ans+=Binomial(s.length()-1-i,dq0.front()-cum, M);
                        ans%=M;
                    }
                    cum++;


                }
            }
            if(cum==dq0.front()){
                ans++;
                ans%=M;

            }
            dq0.pop_front();
            
        }
        ans--;
        ans%=M;
        ans+=M;
        ans%=M;



    }else if(k==2){
        
        while(dq.size()>0){
            ll cum =0;
            fr(i,s.length(),0){
                if(s[i]=='1'){
                    if(dq.front()-cum>=0 && s.length()-1-i>=dq.front()-cum){
                        ans+=Binomial(s.length()-1-i,dq.front()-cum, M);

                        ans%=M;
                    }
                    // }else{
                    //     break;
                    // }
                    cum++;


                }
            }
            if(cum==dq.front()){
                ans++;
                ans%=M;

            }


            dq.pop_front();
        }

        

    }else if(k==3){
        while(dq.size()>0 && dq.front()<10){
            fr(i,1000,power(2,dq.front())-1){
                if(__builtin_popcount(i)==dq.front()){
                    dq1.pb(i);

                }

            }
            dq.pop_front();



        }
    
        
        while(dq1.size()>0){
            ll cum =0;
            fr(i,s.length(),0){
                if(s[i]=='1'){
                    if(dq1.front()-cum>=0 && s.length()-1-i>=dq1.front()-cum){
                        ans+=Binomial(s.length()-1-i,dq1.front()-cum, M);
                        ans%=M;
                    }
                    cum++;


                }
            }
            if(cum==dq1.front()){
                ans++;
                ans%=M;

            }
            dq1.pop_front();
        }


    }else if(k==4){
        while(dq.size()>0 && dq.front()<10){
            fr(i,1000,power(2,dq.front())-1){
                if(__builtin_popcount(i)==dq.front()){
                    dq1.pb(i);

                }

            }
            dq.pop_front();



        }
        while(dq1.size()>0 && dq1.front()<10){
            fr(i,1000,power(2,dq1.front())-1){
                if(__builtin_popcount(i)==dq1.front()){
                    dq2.pb(i);

                }

            }
            dq1.pop_front();



        }
        
        while(dq2.size()>0){
            ll cum =0;
            fr(i,s.length(),0){
                if(s[i]=='1'){
                    if(dq2.front()-cum>=0 && s.length()-1-i>=dq2.front()-cum){
                        ans+=Binomial(s.length()-1-i,dq2.front()-cum, M);
                        ans%=M;
                    }
                    cum++;


                }
            }
            if(cum==dq2.front()){
                ans++;
                ans%=M;

            }
            dq2.pop_front();
        }
    }else if(k==5){
        while(dq.size()>0 && dq.front()<10){
            fr(i,1000,power(2,dq.front())-1){
                if(__builtin_popcount(i)==dq.front()){
                    dq1.pb(i);

                }

            }
            dq.pop_front();



        }
        while(dq1.size()>0 && dq1.front()<10){
            fr(i,1000,power(2,dq1.front())-1){
                if(__builtin_popcount(i)==dq1.front()){
                    dq2.pb(i);

                }

            }
            dq1.pop_front();



        }
        while(dq2.size()>0 && dq2.front()<10){
        fr(i,1000,power(2,dq2.front())-1){
            if(__builtin_popcount(i)==dq2.front()){
                dq3.pb(i);

            }

        }
        dq2.pop_front();



        }
        
        while(dq3.size()>0){
            ll cum =0;
            fr(i,s.length(),0){
                if(s[i]=='1'){
                    if(dq3.front()-cum>=0 && s.length()-1-i>=dq3.front()-cum){
                        ans+=Binomial(s.length()-1-i,dq3.front()-cum, M);
                        ans%=M;
                    }
                    cum++;


                }
            }
            if(cum==dq3.front()){
                ans++;
                ans%=M;

            }
            dq3.pop_front();
        }
    }
    cout<<ans<<"\n";


    
   

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    ll p = 1000000007;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;

} 
