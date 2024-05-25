// Lakshay's code
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define  FOR(i,n) for(long long i = 0; i < (n); i++)
#define  FORR(i,n) for(long long i = n-1; i >= 0; i--)
#define  FOR1(i,n) for(long long i = 1; i <= (n); i++)
#define  FOR2(i,n) for(long long i = 2; i <= (n); i++)
#define pb push_back
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>
#define el cout<<endl;
#define fi first
#define se second
#define noo cout<<"NO"<<endl;
#define yess cout<<"YES"<<endl;
#define take(a,n) FOR(i,n) cin>>a[i];
#define print(v) for(auto it:v) cout<<it<<" "; el
#define all(v) v.begin(),v.end()
#define sort(v) sort(v.begin(),v.end())
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define w(T)	 ll T; cin>>T; while(T--)
#define input(a,n) int n; cin>>n; V a(n); take(a,n);
#define pii pair<int,int>
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res%m ;}
int nCr(int n , int r){
    if (n < r) return 0;
    if (r > n - r) r = n - r;
    ll ans = 1; ll i;
    for (i = 1; i <= r; i++){ans = (ans*(n - r + i));ans /= i;} return ans;
}
ll modinv(ll a , ll m ) {return expo(a , m-2 , m)%m;} // m is prime 
 
using namespace std;
typedef pair<int, pii> pipii;
const int mod = 1e9+7;
//  int c = count(s.begin(), s.end(), '(');
// to_string, stoi, stoll, gcd - already exist
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai
//* Number of bits preserved rahti hai in a,b = a&b,a|b  a+b = (a&b)+(a|b)
 
int ff(int st,int en, int k, V &b){
    int n = b.size();
    int i1 = lower_bound(all(b),st) - b.begin();
    int i2 = lower_bound(all(b),en) - b.begin();
    if(i1 == n) return 0;
    if(i2 == n) i2--;

    if(b[i1]>en) return 0;

    int ans = 0;
    for(int i=i1;i<=i2;i++){
        int idx = lower_bound(all(b),b[i]+k-1) - b.begin();
        if(idx > i2 ) break;
        // cout<<i<<" , "<<idx<<endl;
        if(b[idx] > b[i]+k-1)idx--;
        if(idx<0) continue;
        // yess
        ans = max(ans, idx-i+1);
    }

    // cout<<i1<<" "<<i2<<endl;

    return ans;
}

int f(V a, V b){
    int n = a.size(), m = b.size();
    if(n==0 || m==0) return 0;
    
    V pre(n+1);
    int i = n-1, j = m-1, p = 0;
    FORR(i,n){
        while(j>=0 && a[i] < b[j] ){
            j--;
        }
        if(j<0) {
            pre[i] = p; continue;
        }
        if(a[i]==b[j]) {
            pre[i] = ++p; j--;
        }else pre[i] = p;
    }
    // vector<int> su(n + 1);
    // int r = m - 1;
    // for (int i = n - 1; i >= 0; --i){
    //     su[i] = su[i + 1];
    //     while (r >= 0 && b[r] > a[i]) --r;
    //     if (r >= 0 && b[r] == a[i]) ++su[i];
    // }

    // print(su);
    // print(pre);

    int ans = 0;
     j = 0;
     int r = 0;
    FOR(l, m){
        while (j < n && a[j] <= b[l] + j) ++j;
        while (r < m && b[r] - b[l] < j) ++r;
        ans = max(ans, r - l + pre[j]);
    }
    return ans;

    // // print(pre)

    // int ans = pre[0];
    // FOR(i,n-1){
    //     int k = i+1;
    //     int st = a[i] - k+1;
    //     int en = a[i+1]-1;
    //     int temp = ff(st,en,k,b)+pre[i+1];
    //     ans = max(ans,temp);
    //     // cout<<st<<" "<<en<<" "<<k<<" "<< temp<<endl;
    // }
    // // el
    // ans = max(ans,ff(a[i]-i,1e9,i+1,b));
    // // cout<<ans<<endl;
    // return ans;
}

// int f(const vector<int> &a, const vector<int> &b){
//     int n = a.size();
//     int m = b.size();
//     vector<int> su(n + 1);
//     int r = m - 1;
//     for (int i = n - 1; i >= 0; --i){
//         su[i] = su[i + 1];
//         while (r >= 0 && b[r] > a[i]) --r;
//         if (r >= 0 && b[r] == a[i]) ++su[i];
//     }
//     int ans = 0;
//     int j = 0;
//     r = 0;
//     FOR(l, m){
//         while (j < n && a[j] <= b[l] + j) ++j;
//         while (r < m && b[r] - b[l] < j) ++r;
//         ans = max(ans, r - l + su[j]);
//     }
//     return ans;
// }
   
int32_t main() {
    fast
    w(T){
        int n,m; cin>>n>>m;
        V a(n),b(m); take(a,n); take(b,m)
        int ans = 0;
        V A,B;
        FOR(i,n){
            if(a[i]>0) A.pb(a[i]);
        }
        FOR(i,m){
            if(b[i]>0) B.pb(b[i]);
        }

        ans += f(A,B);
        A = V(); B = V();
        FOR(i,n){
            if(a[i]<0) A.pb(-a[i]);
        }
        FOR(i,m){
            if(b[i]<0) B.pb(-b[i]);
        }
        reverse(all(A));
        reverse(all(B));

        ans += f(A,B);

        cout<<ans<<endl;
    }

    return 0;
}