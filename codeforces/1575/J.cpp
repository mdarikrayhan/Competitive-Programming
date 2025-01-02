#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll 
#define db double
#define tii tuple<int,int,int>
#define pii pair<int,int>
#define pdd pair<db,db>
#define vi vector<int> 
#define vs vector<string>
#define vpi vector<pii>
#define vd vector<db>
#define vpd vector<pdd>
#define stack stack<int> 
#define eb emplace_back
#define pb push_back
#define e emplace
#define F first
#define S second
#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin(), (x).rend()
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define each(a,x) for(auto &a:x)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template<typename T> 
ostream& operator<<(ostream& COUT, vector<T>& v){ for(int i=0 ; i<v.size() ; i++){ COUT<<v[i]<<" "; } COUT << endl; return COUT; }
template<typename T> 
istream& operator>>(istream& CIN, vector<T>& a){ for(int i=0 ; i<a.size() ; i++) CIN>>a[i]; return CIN; }
template<typename T> 
void pws(const T& arg){ cout << arg <<endl;}
template <typename T, typename... Args>
void pws(const T& first, const Args&... args) {cout << first << " ";pws(args...);}
int sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

int dir[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
const int MOD = 1e9 + 7,PINF=1e17,NINF=-1e17;
int n,m,k,x,y,l,w;
string s,t;

int cs(int n){ return __builtin_popcount(n);}
int cbit(int bit){ return 1LL<<bit;}
int iset(int num,int bit){ return (num&cbit(bit))!=0;}

const int B=32,N=1e6+1,M=2e3+1;
vector<vector<pair<int,int>>>par(1000+2,vector<pair<int,int>>(1000+2));
pair<int,int> findUPar(int x,int y) {
        
        if(x == par[x][y].first && y==par[x][y].second)
            return par[x][y]; 
        return par[x][y] = findUPar(par[x][y].first,par[x][y].second); 
    }

void unionByRank(int x1,int y1,int x2,int y2) {
        auto ulp_u = findUPar(x1,y1); 
        auto ulp_v = findUPar(x2,y2); 
        if(ulp_u == ulp_v) return; 
        
            par[ulp_u.first][ulp_u.second] = ulp_v; 
    }
void solve(){
     int n,m,k;
     cin>>n>>m>>k;
     
     vector<vector<int>>vec(n+2,vector<int>(m+1));
     
     
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            cin>>vec[i][j];
        }
        
     }
     for(int i=1;i<=m;i++) {vec[n+1][i]=2; par[n+1][i]={n+1,i};}
     for(int i=n;i>=1;i--)
     {
        for(int j=m;j>=1;j--)
        {
            if( vec[i][j]==2 && vec[i+1][j]==2) par[i][j]={i+1,j};
            else if(vec[i][j]==2) par[i][j]={i+1,j};
            // cout<<par[i][j].first<<" "<<par[i][j].second<<" "<<i<<" " <<j<<endl;
            if(vec[i][j]!=2)par[i][j]={i,j};
                 
            
        }
     }
    //   int x_c=findUPar(3,2).first;
    //   int y_c=findUPar(3,2).second;
    //   cout<<x_c<<" "<<y_c<<endl;
     for(int i=1;i<=k;i++)
     {
      int x;
      cin>>x;
       int i_x=1;
       int j=x;
       
       while(i_x>=1 && i_x<=n && j>=1 && j<=m)
       { 
        if(vec[i_x][j]==2)
        {    
           
             int x_c=findUPar(i_x,j).first;
             int y_c=findUPar(i_x,j).second;
            
            //  cout<<x_c<<" "<<y_c<<endl;
             if(x_c==n+1) {cout<<par[i_x][j].second<<" "; break;}
             i_x=x_c;
             j=y_c;
        }
        else if(vec[i_x][j]==1)
        { 
         vec[i_x][j]=2;
         
          if( vec[i_x+1][j]==2) unionByRank(i_x,j,i_x+1,j);
          if(par[i_x][j].first==i_x) par[i_x][j]={i_x+1,j}; 
          if( i_x-1>=1 && vec[i_x-1][j]==2) unionByRank(i_x-1,j,i_x,j);
          
         j=j+1;
        }
        else 
        {  
         vec[i_x][j]=2;
   
         if( vec[i_x+1][j]==2) unionByRank(i_x,j,i_x+1,j);
         if(par[i_x][j].first==i_x) par[i_x][j]={i_x+1,j};
         if( i_x-1>=1 && vec[i_x-1][j]==2) unionByRank(i_x-1,j,i_x,j);
         
         j=j-1;
        }
        // cout<<i_x<<" "<<j<<endl;
        
       }
       

     }
     
   
     
    
         

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t=1;
  
    while(t--) solve();
}