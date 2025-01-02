#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define fl(x, n,i) for (int i = x; i < n; ++i)
#define mp(x,m) for(auto x : m)
#define pb push_back
#define pf push_front

// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// Defining aliases for data types
typedef vector<int> vint;
typedef map<int, int> mint;
typedef set<int> sint;
typedef pair<int, int> pint;
typedef stack<int> stint;
typedef queue<int> qint;

const int N = 1e9+7;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;



int fac[MAXN + 1];
int inv[MAXN + 1];


/** this is to pre-evaluate nCk under modulo m which is here MOD but can be changed **/
int exp(int x, int n, int m) {
    x %= m;
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

int choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }



// Tocheck for prime number
bool isPrime(int n) {
    if (n <= 1) {
        return false;  // 1 and numbers less than 1 are not prime
    }
    if (n <= 3) {
        return true;  // 2 and 3 are prime
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;  // Numbers divisible by 2 or 3 are not prime
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;  // Numbers divisible by factors other than 1, itself, and 2 or 3 are not prime
        }
    }
    return true;
}


// to get all the prime factors of a number
vint factors(int n){
    vint ans;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ans.pb(i);
            n/=i;
        }
    }
    if(n>1) ans.pb(n);
    return ans;
}


// this lcm would not throw overflow due to a*b
int lcm(int a,int b){
    return (a/__gcd(a,b))*b;
}


// binary exponentiation
double binary_exp(double x,int n){
    double ans = 1.0;
    int nn=n;
    if(nn<0) nn = -1*nn;
    while(nn){
        if(nn%2){
            ans=ans*x;
            nn=nn-1;
        }
        else{
            x=x*x;
            nn=nn/2;
        }
    }

    if(n<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}

//modulo inverse of any number let say i.e, A**-1  = (A**m-2)%m  which is the binary exponentiation of A,m-2 with Modulo of M;


void pre2D(int **a,int n,int m){
    int pre[n+1][m+1];  
    fl(0,n+1,i){
        fl(0,m+1,j){
            if(i==0 || j==0){
                pre[i][j]=0;
            }
            else{
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
            }
        }
    }
    fl(0,n+1,i){
        fl(0,m+1,j){
            cout<<pre[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool dfs(int node,vector<vint> adj,int vis[],int path[],mint &m){
    vis[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,path,m)){
                // m[node]=0;
                return true;
            }
        }
        else if(path[it]){
            // m[node]=0;
            return true;
        }
    }
    path[node]=0;
    m[node]=1;
    return false;
}


signed main() {
    pbds A; //declaration  and now A is an ordered_set
    //order_of_key returns the value while the find_by order returns an iterator.
    // also lower_bound and upper_bound can be cainted using this set and it returns the iterator.
    int t;
    cin>>t;
    fl(0,t,i){
        int n;
        cin>>n;
        vint v(n,0);
        fl(0,n,i) cin>>v[i];
        int g=v[0];
        fl(1,n,i){
            g=__gcd(g,v[i]);
        }
        sort(v.begin(),v.end());
        if(v[0]>=0){

            vint ans;
            // ans.pb(v[0]);
            int z=min(g,v[0]);
            while(z<=v[v.size()-1]){
                ans.pb(z);
                z+=g;
            }
            if(ans.size()<=300){
                cout<<"YES"<<endl;
                cout<<ans.size()<<endl;
                fl(0,ans.size(),j) cout<<ans[j]<<" ";
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }


    }
    return 0;
}

// if gcd(a,n)=1 and gcd(b,n)=1 then gcd(a*b,n) also equal to 1 and vice versa.
// anf gcd(a,n)=1 then gcd(a+kn,n)=1 and vice versa.
