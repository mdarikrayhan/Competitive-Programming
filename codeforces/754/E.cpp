#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define all(x) begin(x),end(x)

template<class T>
using iset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define rep(x,y,z) for(int x=y;x<z;x++)
#define sz size

typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
     int n = sz(a), L = 31 - __builtin_clz(n);
     static vector<complex<long double>> R(2, 1);
     static vector<C> rt(2, 1);  // (^ 10% faster if double)
     for (static int k = 2; k < n; k *= 2) {
          R.resize(n); rt.resize(n);
          auto x = polar(1.0L, acos(-1.0L) / k);
          rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
     }
     vi rev(n);
     rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
     rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
     for (int k = 1; k < n; k *= 2)
          for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
                    // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                    auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
                    C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
               }
}

void solve(){
     int n,m;
     cin>>n>>m;
     vector<string> a(n);
     for(auto&i:a){
          cin>>i;
     }

     int n1,m1;
     cin>>n1>>m1;
     vector<string> b(n1);
     for(auto&i:b){
          cin>>i;
     }

     int wildcards=0;
     for(auto&s:b)for(auto&i:s)wildcards+=i=='?';
     

     double PI=acos(-1);
     
     vector<C> v1((m+m1)*n);
     for(int i=0;i<n;i++){
          int begi=i*(m+m1)+m1;
          for(int j=0;j<m;j++){
               double val=2*PI*(a[i][j]-'a')/26;
               v1[begi+j]={cos(val),sin(val)};
          }
     }
     

     vector<C> v2((m+m1)*n1);
     for(int i=0;i<n1;i++){
          int begi=i*(m+m1);
          for(int j=0;j<m1;j++){
               if(b[i][j]!='?'){
                    double val=2*PI*(b[i][j]-'a')/26;
                    v2[begi+j]={cos(val),-sin(val)};
               }
          }
     }
     reverse(all(v2));

     int nn=1ll<<(__lg(v1.size() + v2.size() - 1)+1);
     v1.resize(nn);
     v2.resize(nn);
     
     fft(v1);
     fft(v2);
     for(int i=0;i<nn;i++)v1[i]*=v2[i];
     fft(v1);
     for(int i=0;i<nn;i++)v1[i]/=nn;
     reverse(v1.begin()+1,v1.end());
     
     vector<vector<int>> sol(n,vector<int>(m));

     double eps=1e-6;
     for(int i=0;i<v1.size();i++){
          
          double ival=v1[i].imag();
          double rval=v1[i].real();
          double rounded=round(rval);
          
          if(abs(ival)>eps)continue;
          if(abs(rval-rounded)>eps)continue;

          int val=rounded;
          
          
          int index=i-((m+m1)*n1-1);              
          
          index%=(m+m1)*n;
          index+=(m+m1)*n;
          index%=(m+m1)*n;

          int x=index/(m+m1);
          int y=index%(m+m1);

          // cout<<x<<' '<<y<<'\n';
               
          y=(m1+m)-y;
          y%=m;
          y=(m-y)%m;
               
               
          // cout<<' '<<x<<' '<<y<<' '<<rval<<' '<<rounded<<' '<<val<<endl;
          sol[x][y]+=val;
     }

     
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               // cout<<' '<<sol[i][j]<<' ';
               cout<<((sol[i][j]==n1*m1-wildcards)?'1':'0');
          }
          cout<<'\n';
     }
}

int main(){
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     int numberOfTests=1;
     //cin>>numberOfTests;
     while(numberOfTests--){
          solve();
     }
}
