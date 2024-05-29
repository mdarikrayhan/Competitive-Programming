#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define elif else if
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>


#define repname(a, b, c, d, e, ...) e
#define rep(...)                    repname(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter < (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i < (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i < (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i < (r); i += (c))





struct ScalarInput {
    template<class T>
    operator T(){
        T ret;
        cin >> ret;
        return ret;
    }
};
struct VectorInput {
    size_t n;
    VectorInput(size_t n): n(n) {}
    template<class T>
    operator vector<T>(){
        vector<T> ret(n);
        for(T &x : ret) cin >> x;
        return ret;
    }
};
ScalarInput input(){ return ScalarInput(); }
VectorInput input(size_t n){ return VectorInput(n); }

template<typename T>
void print(vector<T> a){
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" \n"[i+1==a.size()];
  }
}

template<class T>
void print(T x){
    cout << x << '\n';
}
 
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){
  cout << head << ' ';
  print(forward<Tail>(tail)...);
}



ll inf=1LL<<60;
vector<vector<ll>>mul(int n,vector<vector<ll>>A,vector<vector<ll>>B){
  vector<vector<ll>>C(2*n+1,vector<ll>(2*n+1,inf));
  rep(i,2*n+1)rep(k,2*n+1)rep(j,2*n+1){
    C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
  }
  return C;
}

vector<vector<ll>>Pow(int n,vector<vector<ll>>&A,int p){
  if(p==1)return A;
  if(p&1){
    return mul(n,A,Pow(n,A,p-1));
  }
  vector<vector<ll>>B=Pow(n,A,p/2);
  return mul(n,B,B);
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<ll>a(n),b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];



  vector<vector<ll>>mat(2*n+1,vector<ll>(2*n+1,0));


  for(int i=0;i<=2*n;i++){
    vector<ll>res(2*n+1,inf);
    res[i]=0;
    for(int j=0;j<n;j++){
      vector<ll>nres(2*n+1,inf);
      for(int k=0;k<=2*n;k++){
        if(k>0)nres[k-1]=min(nres[k-1],res[k]+b[j]);
        if(k!=2*n)nres[k+1]=min(nres[k+1],res[k]+a[j]);
      }
      swap(nres,res);
    }
    for(int j=0;j<=2*n;j++)mat[i][j]=res[j];
  }

  
  vector<vector<int>>A(2*n+1,vector<int>(2*n+1));
  for(int i=0;i<=2*n;i++){
    for(int j=0;j<=2*n;j++){
      A[i][j]=mat[i][j];
    }
  }

  vector<vector<ll>>ans=Pow(n,mat,m);
  print(ans[0][0]);
}