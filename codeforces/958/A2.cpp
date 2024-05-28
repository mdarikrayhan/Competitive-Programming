#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3")
using namespace std;
//using namespace __gnu_pbds;
#define bit(_x) (1 << _x)
#define int long long
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define pyes cout<<"Yes\n"
#define pno cout<<"No\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
typedef long double ld;
const int mod = 1e9+7;
const int INF = 1e15;
const int N=1e6;
//cout<<fixed<<setprecision(20)<<mx<<endl;
// vector<int>primes;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set;
//cout << fixed << setprecision(7) << ans << '\n';
// (1,0,n-1,l-1,r-1,1);
void deb(){
    cout<<"\n";
}
template <typename T, typename... Types>
void deb(T var1, Types... var2){
    cout<<var1<<" ";
    deb(var2...);
}
template <typename T>
void pv(vector<T>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int modmul(int a, int b){
    int res = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}
// int check(int mex,vector<int>&a){
//     if(mex==0){
//         return true;
//     }
//     vector<int>cnt(mex,0);
//     for(int x:a){
//         if(x<mex){
//             cnt[x]++;
//         }
//     }
//     sort(all(cnt));
//     if(cnt[0]==0){
//         return false;
//     }
//     if(cnt[0]==1){
//         if(mex>1 and cnt[1]==1){
//             return false;
//         }
//     }
//     return true;
// }
// int bsearch(vector<int>&a){
//     int n=a.size();
//     int l=0,r=n;
// 	while(l<=r){
// 		int mid=(l+r)/2;
// 		if(check(mid,a)){
// 			l=mid+1;
// 		}else{
// 			r=mid-1;
// 		}
// 	}
//     return l-1;
// }
 
 
class presum{
	vector<int>v;
	public:
	presum(vector<int>&a){
		v.resize(a.size());
		int t=0;
		for(int i=0;i<a.size();i++){
			t+=a[i];
			v[i]=t;
		}
	}
	int get(int l,int r){
		if(l==0){
			return v[r];
		}
		return v[r]-v[l-1];
	}
};
int fac[N];
int spf[N];
void sieve(){
    spf[1] = 1;
        for (int i = 2; i < N; i++)
            spf[i] = i;
        for (int i = 4; i < N; i += 2)
            spf[i] = 2;
        for (int i = 3; i * i < N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < N; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
}
void calc_fac(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
}
template <typename T>
void fill(vector<T>&a){
    for(int i=0;i<a.size();i++){
        cin>>a[i];
    }}
int modpower(int x, int y){
    if(y==0){
        return 1;
    }
    int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}
int modInverse(int n){return modpower(n, mod - 2);}
int nCrModPFermat(int n,int r)
{   
    //deb("fn",n,r);
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r]) % mod
            * modInverse(fac[n - r]) % mod)
           % mod;
}
bool is_bound(pii p,int n,int m){
    if(p.first < 0 || p.first>=n || p.second<0 || p.second >=m){
        //deb(p.F,p.S);
        return false;
    }
    
    return true;
}
 
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.F==b.F){
            return a.S<b.S;
        }
        return a.F<b.F;
    }
};
 
vector<pii>dirs={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
vector<pii>dirs2={{-1,0},{0,1},{1,0},{0,-1}};
vector<pii>dirs3={{0,0},{1,0},{0,1},{1,1}};
void factorize(int tmp,map<int,int>&mp){
    mp.clear();
    while(tmp>1){
        mp[spf[tmp]]++;
        tmp/=spf[tmp];
    }
    return;
}
int fn(int a,int b){
    int ans=1;
    while(a>1){
        if(b%spf[a]==0){
            ans=max(ans,spf[a]);
        }
        a/=spf[a];
    }
    return ans;
}
map<char,int>mpd={{'U',0},{'R',1},{'D',2},{'L',3}};
int nc2(int n){
    return (n*(n-1))/2;
}
 
// bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&par){

// }
 

void primeFactors(int n,map<int,int>&mp) 
{ 
    while (n % 2 == 0) 
    { 
        mp[2]++;
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            mp[i]++;
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        mp[n]++;
} 

vector<int>par(2e5+10),opp(2e5,-1);
int find_par(int v){
    if(v==par[v]){
        return v;
    }
    return par[v]=find_par(par[v]);
}
void merge(int u,int v){
    int pu=find_par(u);
    int pv=find_par(v);
    par[pv]=pu;
}

void solve(int ttc){
    int n,m;
    cin>>n>>m;
    vector<string>g1(n),g2(m);
    fill(g1);
    fill(g2);
    for(int i=0;i<=n-m;i++){
        int p=-1;
        while(p+1<n){
            p=g2[0].find(g1[i],p+1);
            if(p==-1){
                break;
            }
            int flg=1;
            for(int j=m-1;j>=0;j--){
                if(g1[i+j]!=g2[j].substr(p,m)){
                    flg=0;
                    break;
                }
            } 
            if(flg){
                deb(i+1,p+1);
                return;
            }
        }
    }
 
}  
 
signed main(){
    //ISSUE ONLY IF N<K ?
    //K<SQRTN K>SQRTN ?
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
    //caldp();
    //calc_fac();
    //sieve();
    //cal();
	for(int i=1;i<=t;i++){
        //int n,k;
        //cin>>n>>k;
		solve(i);
	}
	
}