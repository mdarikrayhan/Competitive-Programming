#include <bits/stdc++.h> // (c) Dmytro Fedoriaka, 2024.
using namespace std;
#define int int64_t
vector<int>ReadVec(int n){vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];return a;} 

constexpr int INF = 1000000000;

struct MaxMax {
  int idx1=-1;
  int max1=-INF, max2=-INF;

  MaxMax MulBy(int k) const {
    return MaxMax{.idx1=idx1, .max1=k*max1, .max2=k*max2};
  }
};

MaxMax Merge(const MaxMax& m1, const MaxMax& m2) {
  if(m1.max1<m2.max1)return Merge(m2, m1);
  if(m1.idx1==m2.idx1) return MaxMax{.idx1=m1.idx1, .max1=m1.max1, .max2=max(m1.max2, m2.max2)};
  return MaxMax{.idx1=m1.idx1, .max1=m1.max1, .max2=max(m1.max2, m2.max1)};
}

struct SparseTable {
  int L,n;
  vector<vector<MaxMax>> st;
  
  SparseTable(){}
  SparseTable(const vector<MaxMax>& data) {
    n = data.size();
    L = 64-__builtin_clzll(n);
    st.resize(L);
    st[0]=data;
    for(int l=1;l<L;l++) {
      int ll = 1<<(l-1);
      st[l].resize(n);
      for(int i=0;i<n-ll;i++) st[l][i]=Merge(st[l-1][i], st[l-1][i+ll]);
    }
  }
  
  // [l..r)
  MaxMax Get(uint64_t l, uint64_t r) {
    //assert(l<n);
    if(r>n)r=n;
    int lv=63-__builtin_clzll(r-l);
    return Merge(st[lv][l], st[lv][r-(1<<lv)]);
  }
};


struct Solver{  
  vector<int> h,a,b,ans;
  int n,maxA;  
  vector<MaxMax> ha;
  SparseTable hast;
  
  void Solve1(int x) {    
    MaxMax m0;
    for(int c=1;(c-1)*x+1 <= maxA; c++) {
      MaxMax m1 = hast.Get( (c-1)*x+1, c*x+1);
      m0 = Merge(m0, m1.MulBy(c));
    }
    ans[m0.idx1]=max(ans[m0.idx1], m0.max1-m0.max2);
  }
  
  void Solve() {
    cin>>n;
    h = ReadVec(n);
    a = ReadVec(n);
    
    if(n==1){ cout << a[0]*h[0]<<"\n"; return; }
    
    ans.assign(n, 0);
    b.resize(n);
    maxA=0;
    for(int ai:a)maxA=max(maxA,ai);
    ha.resize(maxA+1);
    for(int i=0;i<n;i++) {
      ha[a[i]]=Merge(ha[a[i]], MaxMax{.idx1=i, .max1=h[i], .max2=0});
    }
    hast = SparseTable(ha);    
    for(int x=1;x<=maxA;x++) Solve1(x);
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout << "\n";  
  }  
};
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  int casesNum=1;
  cin>>casesNum;
  for(int caseId = 1; caseId<=casesNum; caseId++) {
  	Solver().Solve();	
  }    
  return 0;
}
