//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define int long long 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//indexed_set s;
//#define pii pair<int,int>
//#define ll long long  
//#define int unsigned int
//#define pb push_back
//#define mp make_pair
#define ff first
#define ss second
#define countbit(x) __builtin_popcountll( x )
//#define lb lower_bound
//#define ub upper_bound
//#define bs binary_search
#define mod 1000000007 // mod+2
#define double long double
#define all(x) x.begin(), x.end()
//#define debug(x) cout << #x << " = " << x << "\n"
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
const int inf=1e18;
const int N=200005;
//int d;
//vector <int> fac(N);
//vector <int> adj[N];  
//vector <int> vis(N);
//vector <vector <int>> v(N);

void google(int t){
    cout<<"Case #"<<t<<": ";
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
vector <char> dr={'D','U','R','L'};
/*
void dfs(int s){
    if(vis[s])return;
    vis[s]=1;
    for(auto u:adj[s]){
        dfs(u);
    }
}
int ncr(int n, int r){
    int x=(fac[r]*fac[n-r]);
    x=inv(fac[n],x);
    return x;
}
*/
int fun(int a,int b){
    if(b==0)return 1;
    else if(a==1)return 1;
    int temp=fun(a,b/2)%mod;
    temp=(temp*temp)%mod;
     if(b%2==1)temp=(temp*a)%mod;
    return temp%mod;
}
 
int inv(int a,int b){
    return (a*fun(b,mod-2))%mod;
}

// int funn(string& s, int i){
    
// }

void solve(){
    int i,j,k=0,n,m,l=0;
    int x,y;
    cin>>n;
    /*
    for(i=0;i<=n;i++)vis[i]=0;
    for(i=0;i<=n;i++){
         adj[i].clear();
    }
    */
    string s;
    cin>>s;
    cin>>x>>y;
    int ans=inf;
    vector <int> pfy(n+1,0), pfx(n+1,0), sfy(n+2,0), sfx(n+2,0);
    
    for(i=0;i<n;i++){
        if(s[i]=='U'){
            pfy[i+1]=pfy[i]+1;
            pfx[i+1]=pfx[i];
        }
        else if(s[i]=='D'){
            pfy[i+1]=pfy[i]-1;
            pfx[i+1]=pfx[i];
        }
        else if(s[i]=='L'){
            pfy[i+1]=pfy[i];
            pfx[i+1]=pfx[i]-1;
        }
        else{
            pfy[i+1]=pfy[i];
            pfx[i+1]=pfx[i]+1;
        }
        
    }
    
    for(i=n;i>0;i--){
        if(s[i-1]=='U'){
            sfy[i]=sfy[i+1]+1;
            sfx[i]=sfx[i+1];
        }
        else if(s[i-1]=='D'){
            sfy[i]=sfy[i+1]-1;
            sfx[i]=sfx[i+1];
        }
        else if(s[i-1]=='L'){
            sfy[i]=sfy[i+1];
            sfx[i]=sfx[i+1]-1;
        }
        else{
            sfy[i]=sfy[i+1];
            sfx[i]=sfx[i+1]+1;
        }
    }

    
    int hi=n, lo=0;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        int can=0;
        for(i=1;i+mid-1<=n;i++){
            int cx=pfx[i-1]+sfx[i+mid], cy=pfy[i-1]+sfy[i+mid];
            int req=abs(x-cx)+abs(y-cy);
            if((req<=mid)&&((mid-req)%2==0)){
                can=1;
                break;
            }
        }
        
        if(can){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
     
    if(ans==inf) ans=-1;
    cout<<ans<<"\n";
    //memset(a,0,sizeof(a));
    //cout<<fixed<<setprecision(10)<<ans<<"\n";
       
}

 
signed main()
{   /*  
   #ifndef ONLINE_JUDGE 
   freopen("inputhsr.txt", "r", stdin);  
   freopen("outputhsr.txt", "w", stdout); 
   #endif 
   */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
    fac[0]=1;
    for(i=1;i<N;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
    */ 
    
    int t=1;
    int T=1;
    //cin>>T;
    for(t=1;t<=T;t++){
        
       
        //google(t);
        solve();
        
        
    }
    
    return 0;
}
