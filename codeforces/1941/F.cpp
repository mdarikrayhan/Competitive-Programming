#include <bits/stdc++.h>
 
// TO USE ORDERED_SET.....
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp
// using namespace __gnu_pbds;
 
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 

using namespace std;                                  
#define int long long
#define pb push_back
#define fo(i,n) for(int i = 0; i < n; i++)
#define fo1(i,n,s,d) for(int i = s; i < n ; i+= d)
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mib map<int,bool>
#define en "\n"
#define si set<int>
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mpr make_pair
#define F first
#define S second
// #define double         long double
#define heap_max        priority_queue <int>
#define heap_min        priority_queue <int, vi, greater<int>>

#define pii pair<int,int>
 
const int MAX = 1e18;

using namespace std;

int mod2=1000000007;

int mod= 998244353;

const int MAX2=100;

vector<int> divisor[MAX2]; 
 
void sieve()                            // IMPORTANT!!!!!  O(nlogn)
{ 
    for (int i = 1; i <= MAX2; ++i) { 
        for (int j = i; j <= MAX2; j += i) 
            divisor[j].push_back(i); 
    } 
}


bool my_compare(pair<int,int>& a, pair<int,int>& b){
    return a.F<b.F;
}


int norm (int x) {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
}

template<class T>
T power(T a, int b) {
        T res = 1;
        for (; b; b /= 2, a *= a) {
                if (b & 1) res *= a;
        }
        return res;
}

struct Z {
        int x;
        Z(int x = 0) : x(norm(x)) {}
        int val() const {
                return x;
        }
        Z operator-() const {
                return Z(norm(mod - x));
        }
        Z inv() const {
                return power(*this, mod - 2);
        }
        Z &operator*=(const Z &rhs) {
                x = x * rhs.x % mod;
                return *this;
        }
        Z &operator+=(const Z &rhs) {
                x = norm(x + rhs.x);
                return *this;
        }
        Z &operator-=(const Z &rhs) {
                x = norm(x - rhs.x);
                return *this;
        }
        Z &operator/=(const Z &rhs) {
                return *this *= rhs.inv();
        }
        friend Z operator*(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res *= rhs;
                return res;
        }
        friend Z operator+(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res += rhs;
                return res;
        }
        friend Z operator-(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res -= rhs;
                return res;
        }
        friend Z operator/(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res /= rhs;
                return res;
        }
        friend std::istream &operator>>(std::istream &is, Z &a) {
                int v;
                is >> v;
                a = Z(v);
                return is;
        }
        friend std::ostream &operator<<(std::ostream &os, const Z &a) {
                return os << a.val();
        }
};
 

// Z fact[300005];            // CODE FOR FACTORIAL...!!!!

// fact[0]=1;           // will not run in VS Code remove 2 zeros for running but will run in codeforces.

// fo(i,300004){s

//   fact[i+1]=(i+1)*fact[i];

// }

int max2(int n,int ans){

  if(n==1) return ans;

  else{
    n =n/2;
    ans++;
    return max2(n,ans);
  }

}


int knapSack(int W, int w[], int val[], int n)          // Standard knapsack 0/1
{ 

vector<vector<int>>dp(n+1,vector<int>((W+1),0));
dp[0][0]=0;

for(int i=0;i<(n);i++){
        for(int j=0;j<(W+1);j++){
                if((j+w[i])<(W+1)){    // putting in the knapsack..
                dp[i+1][j+w[i]]= max(dp[i+1][j+w[i]],(dp[i][j]+val[i]));
                }
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]); // not puting in the knapsack..
        }
}
int ans=0;

for(int j=0;j<(W+1);j++){
        if(dp[n][j]>ans){
        ans=dp[n][j];
        }
}

return ans;

}


int sum_v(vector<int>v){
        int ans=0;
        fo(i,v.size()) ans+=v[i];
        return ans;
}



// ADJACENCY_MATRIX.

// vvi adj_mat(n);
// fo(i,n){
//         int v,u;
//         cin>>v>>u;
//         v--;u--;
//         adj_mat[v].pb(u);
//         adj_mat[u].pb(v);
// }  





// BINARY_SEARCH.

// int low =1; int high = (n/(k+1))+1;
// while(high-low>1){
//         int mid = (low+high)/2;
//         (check(mid))?(low=mid):(high=mid);
// }





int dfs(int x,int u,int f,vvi& adj_mat,int& res){        // On trees....

        int sz=1;
        for(auto v : adj_mat[u]){
                if(v==f) continue;
                sz+=dfs(x,v,u,adj_mat,res);
        }
        if(sz>=x  && u!=f){
                res++; sz=0;                    // Calculation on on of connected components....
        }
        return sz;

}

bool chck(int k,int x,vvi& adj_mat){

        int res=0;
        int tz=dfs(x,0,0,adj_mat,res);
        if(res>k || (res==k && tz>=x)) return true;
        else return false;

}

//  Initialization of a vector matrix....

// vvi   forward(n, vi(32,0));

signed main(){

        int tt;
        cin>>tt;

        while(tt--){

        int n,m,k;
        cin>>n>>m>>k;
        vi a(n);
        vi d(m); vi f(k);
        fo(i,n) cin>>a[i];
        fo(i,m) cin>>d[i];
        fo(i,k) cin>>f[i];

        int maxi=0;
        int pos=0;
        fo(i,n-1){
                if((a[i+1]-a[i])>maxi){
                        maxi=a[i+1]-a[i];
                        pos=i;
                }
        }

        int maxi2=0;
        fo(i,n-1){
                if((a[i+1]-a[i])>maxi2 && i!=pos){
                        maxi2=a[i+1]-a[i];
                }
        }

        sort(all(d)); sort(all(f));

        vi lower_df;
        vi upper_df;
        int imbalance=maxi;

        fo(i,k){

                int r = f[i];
                double mid = (double(a[pos]+a[pos+1])/2.0 - r);

                int x_l = lower_bound(all(d),mid)-d.begin();
                int x_u = upper_bound(all(d),mid) -1-d.begin();

                int imb1=imbalance;
                if(x_l>=0 && x_l<m){
                        int k = d[x_l]+f[i];
                        if(k<a[pos+1]){
                                imb1= k-a[pos];
                        }
                }

                int imb2=imbalance;
                if(x_u>=0 && x_u<m){
                         int k = d[x_u]+f[i];
                        if(k>a[pos]){
                                imb2=a[pos+1]-k;
                        }
                }

                imbalance = min(imbalance,min(imb1,imb2));  
        }

        imbalance = max(imbalance,maxi2);

        cout<<imbalance<<en;
        } 
        return 0; 
  }