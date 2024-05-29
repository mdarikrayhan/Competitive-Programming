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


double randdouble(double l, double r) {
    // l以上r以下の実数を返す.
    return l + (r-l) * (double)rand() / RAND_MAX;
}

int randint(int l, int r) {
    // l以上r以下の整数を返す.
    return l + rand()%(r-l+1);
}

int naive(int n,int m,int d,vector<vector<int>>&A){
  int ans=m;
  rep(bit,1,(1<<m)){
    vector<int>res;
    res.push_back(-1);
    res.push_back(n);
    int p=0;
    rep(i,m){
      if((bit>>i)&1){
        p++;
        for(auto j:A[i]){
          res.push_back(j);
        }
      }
    }
    sort(res.begin(),res.end());
    bool flag=true;
    for(int i=0;i<res.size()-1;i++){
      if(res[i+1]-res[i]>d)flag=false;
    }
    if(flag)ans=min(ans,p);
  }
  return ans;
}

int solve(int n,int m,int d,vector<vector<int>>&A){
  vector<int>pos(n,0);
  rep(i,m){
    for(auto j:A[i])pos[j]=i;
  }
  vector<int>cnt(m,0);
  rep(i,d-1){
    cnt[pos[i]]++;
  }
  vector<int>ok(1<<m,1);
  rep(i,d-1,n){
    cnt[pos[i]]++;
    int bit=0;
    rep(j,m){
      if(cnt[j]>0)bit|=1<<j;
    }
    ok[bit]=0;
    cnt[pos[i-d+1]]--;
  }



  int ans=m;
  rep(bit,1<<m){
    int p=0;
    rep(i,m){
      if((bit>>i)&1){
        p++;
        if(ok[bit^(1<<i)]==0)ok[bit]=0;
      }
    }
    if(ok[bit]){
      ans=min(ans,m-p);
    }
  }
  return max(0,ans);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  if(0){
    while(true){
      int n=randint(1,20);
      int d=randint(1,n);
      int m=randint(1,5);
      print(n,m,d);
      vector<vector<int>>A(m);
      rep(i,n){
        A[randint(0,m-1)].push_back(i);
      }
      int ans1=solve(n,m,d,A);
      int ans2=naive(n,m,d,A);
      if(ans1!=ans2){
        print(n,m,d);
        rep(i,m){
          if(A[i].size()==0)cout<<endl;
          else print(A[i]);
        }
        print(ans1,ans2);
        exit(0);
      }
    }
  }

  int n,m,d;
  cin>>n>>m>>d;
  vector<vector<int>>A(m);
  rep(i,m){
    int s;
    cin>>s;
    rep(j,s){
      int a;
      cin>>a;
      A[i].push_back(a-1);
    }
  }
  print(solve(n,m,d,A));
}