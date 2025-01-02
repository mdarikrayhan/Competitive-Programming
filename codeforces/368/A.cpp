#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define cy() cout << "YES" << '\n'
#define cn() cout << "NO" << '\n'

// Function to check if an integer is prime or not
bool isprime(ll n){
    if(n<2){
        return false;
    }
    for(ll i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        } 
    }
    return true;
}

int primefactorcount(int n){
    int k = 0;
    for(int i = 2;i<=n;i++){
        if(n%i == 0 && isprime(i)){
            k+=1;
        }
}
    return k;
}
ll nextlucky(ll n){
  bool luckfound = false;
  ll ans =0;
  while(luckfound!=true){
    if(n%10 !=4 && n%10!=7){
      n+=1;
    }else{
      ll t = n;
      while(t>0){
        ll rem = t%10;
        if(t== 7 || t == 4){
          break;
        }
        if(t%10!=4 && t%10!=7){
          break;
        }else{
          t/=10;
        }
      }
      
      if(t==4 || t== 7){
        ans = n;
        luckfound = true;
      }
    }
  }
  return ans;
}
ll countdigit(ll n){
  ll ans = 0;
  if(n<0){
    n+=-1;
  }
  while(n>0){
    ans+=1;
    n/=10;
  }
  return ans;
}
void solve(){
  int n , d;
  cin >> n >> d;
  int a[n];
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  int m;
  cin >> m;
  int ans = 0;
  int currenthooks = 0;
  if(m>n){
    ans-= d*(m-n);
    for(int i = 0;i<n;i++){
        ans+=a[i];  
    }
  }else if(m<=n){
    for(int i = 0;i<m;i++){
      ans+=a[i];
    }
  }
  
  cout << ans;
  
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int tt;
    // cin >> tt;
    // while(tt--){
    //     using std::chrono::high_resolution_clock;
    //     using std::chrono::duration_cast;
    //     using std::chrono::duration;
    //     using std::chrono::milliseconds;
    //     auto t1 = high_resolution_clock::now();
       solve();
    //     auto t2 = high_resolution_clock::now();
    //     auto ms_int = duration_cast<milliseconds>(t2 - t1);
    //     duration<double, std::milli> ms_double = t2 - t1;
    //     //std::cout << ms_double.count() << "ms\n";
    // }
    return 0;  
}


