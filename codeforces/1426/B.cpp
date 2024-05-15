#include <algorithm>
#include<bits/stdc++.h>
#include <cctype>
#include <climits>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iterator>
#include <limits>
#include <locale>
#include <math.h>
#include <numeric>
#include <ostream>
#include <pthread.h>
#include <sstream>
#include <tuple>
#include <type_traits>
#include <cassert>
#include <utility>
#include <string_view>
 
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
 
using namespace std;
// using namespace __gnu_pbds;
 
 
#define md                  1000000007
#define pb                  push_back
#define eb                  emplace_back
#define em                  emplace
#define mp                  make_pair
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);
#define DEBUG
#undef  DEBUG
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
#define sc static_cast<ll>
#define ONEPROBLEM
#if defined(ONEPROBLEM)
#undef ONEPROBLEM
#endif
//#define ONEPROBLEM

template<typename C> constexpr auto Size(const C& c) -> decltype(c.size()){
  return c.size();
}
template<typename T,std::size_t N> constexpr auto Size(const T(&)[N]) -> decltype(N){
  return N;
}

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
bool ispossible(const vector<ll>& a,int n,ll d,ll k,ll gain){
  //cout << "IN HERE\n";
  int i=0;
  ll elapsed{1};
  ll nextime{elapsed+1LL+k};
  while(d > 0){
    gain-=a[i];
    if(gain<=0)return true;
    if(elapsed+1LL==nextime){
      nextime+=1LL+k;
      i=0;
      --d;
      ++elapsed;
    }
    else{
      i=(i+1)%n;
      if(i==0){
        d-=(nextime-elapsed);
        elapsed=nextime;
        nextime+=1LL+k;
      }
      else{
        ++elapsed;
        --d;
      }
    }
    //cout << "Day " << d << " elapsed is " << elapsed << " next time is " << nextime << " gain is " <<
   // gain  << " index is " << i << " and k is " << k << "\n"; 
  }
  return gain<=0 and d<=0;
}
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
struct HashStruct{
  template<typename T,typename U> std::size_t operator()(const pair<T,U>& other) const{
    auto first{std::hash<T>{}(other.first)};
    auto second{std::hash<U>{}(other.second)};
    return (first^(second<<1));
  }
}; 
#define GET(a) (a-'A')
//#define PRINT
std::ofstream Result("output.txt",ios::out);
typedef typename std::priority_queue<pii,
typename std::vector<pii>,
typename std::less<pii>> pq;
static constexpr int MOD{ 998244353 };
#define ms(a,b) (((a%MOD)+(b%MOD))%MOD)
#define ps(a,b) (((a%MOD)*(b%MOD))%MOD)
map<int,int> h{};
void dfs(const string& s,int i,int l,int num,int c){
  if(i==l){
    if(num%7==0){
      h[c]=num;
    }
    return;
  }
  if(i==0){
    for(int j{1};j<10;++j){
      num=j;
      if((s[i]-'0')!=j){
        dfs(s,i+1,l,num,c+1);
      }
      else{
        dfs(s,i+1,l,num,c);
      }
    }
  }
  else{
    for(int j{0};j<10;++j){
      auto x=num*10+j;
      if((s[i]-'0')!=j){
        dfs(s,i+1,l,x,c+1);
      }
      else{
        dfs(s,i+1,l,x,c);
      }
    }
  }
}
namespace details{
  vector<int> primes{};
  void init();
}
void details::init(){
  static constexpr int n{1000};
  static constexpr int SIZE{10000};
  bool isPrime[SIZE];
  memset(isPrime,true,sizeof(isPrime));
  static_assert(sizeof(isPrime)==(sizeof(bool)*std::size(isPrime)));
  for(int i{2};;++i){
    if(isPrime[i]){
      details::primes.pb(i);
      if(std::size(details::primes)==static_cast<std::size_t>(n))break;
      for(int j{i*2};j<=SIZE;j+=i){
        isPrime[j]=false;
      }
    }
  }
}
bool isKalindrome(const vector<int>& a,int low,int high,int del){
  if(low>=high)return true;
  bool ans=false;
  if(a[low]==a[high]){
    ans=ans or isKalindrome(a, low+1, high-1, del);
  }
  else if(del==-1){
    ans = ans or isKalindrome(a, low, high-1, a[high]) or
    isKalindrome(a, low+1, high, a[low]);
  }
  else if(a[low]==del){
    ans = ans or isKalindrome(a, low+1, high, del);
  }
  else if(a[high]==del){
    ans = ans or isKalindrome(a, low, high-1, del);
  }
  return ans;
}
map<string,int> dp{};
int dfs(string& s){
  if(s.empty())return 99999;
  auto it=dp.find(s);
  if(it!=end(dp))return it->second;
  auto num=stoll(s);
  if(num%25==0)return 0;
  const auto& l{int(size(s))};
  int ret=INT_MAX;
  for(int i{};i<l;++i){
    auto t=s;
    t.erase(i,1);
    ret=min(ret,1+dfs(t));
  }
  return dp[s]=ret;
}
void beatifulArray(){
  ll n,k,b,s;
  cin >> n >> k >> b >> s;
  if(k*b==s){
    for(int i{};i<n-1;++i){
      cout << "0 ";
    }
    cout << s << "\n";
    return;
  }
  if(k==1){
    if(b!=s){
      cout << "-1\n";
      return;
    }
    cout << s << " ";
    for(int i{1};i<n;++i){
      cout << "0 ";
    }
    cout << "\n";
    return;
  }
  if(k*b>s){
    vector<ll> elements{k*b};
    s-=k*b;
    ll starter{k-1};
    int i{1};
    for(;i<n and s>0;++i){
      ll taker=min(starter,s);
      elements.push_back(taker);
      s-=taker;
    }
    while(i++<n)elements.push_back(0);
    if(s!=0){
      cout << "-1\n";
      return;
    }
    for(auto&& x: elements){
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  int i{};
  if(b==0LL){
    ll start{k-1ll};
    vector<ll> elements{};
    for(;i<n and s>0;++i){
      ll taker=min(s,start);
      elements.push_back(taker);
      s-=taker;
    }
    while(i++<n){
      elements.push_back(0);
    }
    if(s){
      cout << "-1\n";
      return;
    }
    for(auto&& x: elements){
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  vector<ll> elements{b*k};
  s-=b*k;
  ll start{k-1ll};
  for(i=1;i<n and s>0;++i){
    ll taker = min(s,start);
    elements.push_back(taker);
    s-=taker;
  }
  while(i++<n){
    elements.emplace_back(0);
  }
  if(s){
    cout << "-1\n";
    return;
  }
  for(auto&& x: elements){
    static_assert(std::is_same_v<decltype(x),long long int&>,"Types differ!\n");
    cout << x << " ";
  }
  cout << "\n";
  return;  
}
int dfs(const string& s,int i,int l,int* dp){
  if(i==l)return 0;
  if(dp[i]!=-1)return dp[i];
  int ret=INT_MAX;
  int j{i};
  int MEX{-1};
  int met[2]={0,0};
  while(j<l){
    ++met[s[j]-'0'];
    if(met[0]==0)MEX=0;
    else if(met[1]==0)MEX=1;
    else MEX=2;
    ret=min(ret,MEX+dfs(s,j+1,l,dp));
    ++j;
  }
  return dp[i]=ret;
}
vector<int> getGoodNumbers(int maxCounter){
  vector<int> a;
  a.reserve(maxCounter);
  int start{1};
  auto isGood=[](const int x){
    return (x%10!=3 and x%3!=0);
  };
  while(1){
    if(isGood(start)){
      a.push_back(start);
      --maxCounter;
      if(!maxCounter)break;
    }
    ++start;
  }
  return a;
}
vector<int> theNumbers{};
int mx{INT_MIN};
#define f first
#define s second
bool visited[51][51];
bool canI(vector<string>& board,int i,int j,int n,int m){
  static int dx[4]={1,-1,0,0};
  static int dy[4]={0,0,1,-1};
  auto isGood=[&](int i,int j){
    return i>=0 and j>=0 and i<n and j<m;
  };
  bool ans=true;
  auto col=board[i][j];
  visited[i][j]=true;
  for(int k{};k<4;++k){
    auto ni{i+dx[k]},nj{j+dy[k]};
    if(isGood(ni,nj) and !visited[ni][nj]){
       if(board[ni][nj]=='.'){
         board[ni][nj]=(col=='W')?('R'):('W');
         ans=ans and canI(board,ni,nj,n,m);
       }
       else if(board[ni][nj]==col){
        return false;
       }
       else if(board[ni][nj]!=col){
        ans= ans and canI(board,ni,nj,n,m);
       }
    }
  }
  return ans;
}
set<vector<int>> bads{};
int cache[101][101];
bool can(int i,int j,int n,int m,int k){
  if(k<0 or i>n or j>m)return false;
  if(cache[i][j]!=-1)return cache[i][j];
  if(i==n and j==m){
    if(k==0)return true;
  }
  bool ans=false;
  ans=ans or can(i+1,j,n,m,k-j);
  ans=ans or can(i,j+1,n,m,k-i);
  return cache[i][j]=ans;
}
int memo[2][101];
bool dfs(int i,int j,int m,const vector<string>& a){
  if(i<0 or j>=m or j<0 or i>=2)return false;
  if(a[i][j]=='1')return false;
  if(i==1 and j==m-1)return true;
  if(memo[i][j]!=-1)return memo[i][j];
  bool ans{false};
  const int dx[]={1,1,0,-1,-1};
  const int dy[]={0,1,1,0,1};
  for(int k{};k<5;++k){
    ans=ans or dfs(i+dx[k],j+dy[k],m,a);
  }
  return memo[i][j]=ans;
}
using ip=typename std::pair<int,int>;
class Solution{
  private:
  int n{};
  int m{};
  bool isGood(int i,int j) const{
    return (i>=0 and j>=0 and i<n and j<m);
  }
  public:
  int MinimumEffort(vector<vector<int>>& heights){
     n=int(heights.size());
     m=int(heights.front().size());
     auto getI=[&](int i,int j){
      return i*m+j;
     };
     auto getij=[&](int I){
      return mp(I/m,I%m);
     };
     int l{n*m};
     const int INF{0x3f3f3f3f};
     int dist[l];
     fill(dist,dist+l,INF);
     dist[0]=0;
     set<ip> bst{};
     bst.emplace(0,0);//{cost,I}
     const int dx[4]={1,-1,0,0};
     const int dy[4]={0,0,1,-1};
     while(!bst.empty()){
      auto cur{*bst.begin()};
      static_assert(std::is_same<decltype(cur),
      typename std::pair<int,int>>::value,"Types differ...\n");
      bst.erase(bst.begin());
      auto theNode{cur.s};
      auto theIJ{getij(theNode)};
      auto oi{theIJ.first},oj{theIJ.second};
      for(int k{};k<4;++k){
        auto ni{oi+dx[k]},nj{oj+dy[k]};
        if(isGood(ni, ni)){
          auto NI{getI(ni,nj)};
          auto dH{abs(heights[ni][nj]-heights[oi][oj])};
          dH=max(dH,cur.f);
          if(dist[NI]>dH){
            if(dist[NI]!=INF){
              bst.erase(bst.find(mp(dist[NI],NI)));
            }
            dist[NI]=dH;
            bst.emplace(dist[NI],NI);
          }
        }
      }
     }
     return *(dist+l-1);
  }
};
int theCache[201][2][3];
//dp[i][j][k] index/taken or not taken/
bool can(const string& s,int i,int l,int prev,bool canremove){
  if(i==l)return true;
  bool ans=false;
  //dp[i][canremove][prev+1]
  if(theCache[i][canremove][prev+1]!=-1){
    return theCache[i][canremove][prev+1];
  }
  if(prev==-1 and canremove){
    //starting the process
    ans=ans or can(s,i+1,l,s[i]-'0',true);
    ans=ans or can(s,i+1,l,prev,false);
  }
  else if(!canremove and prev==-1){
    ans=ans or can(s,i+1,l,s[i]-'0',true);
  }
  else if(canremove){
    if(s[i]-'0'>=prev)ans=ans or can(s,i+1,l,s[i]-'0',true);
    ans=ans or can(s,i+1,l,prev,false);
  }
  else if(!canremove){
    if(s[i]-'0'>=prev)ans=ans or can(s,i+1,l,s[i]-'0',true);
  }
  return theCache[i][canremove][prev+1]=ans;
}
vector<int> thePrimes{};
void init(int n){
  bool isPrime[n+1];
  memset(isPrime,1,sizeof isPrime);
  for(int i{2};i<=n;++i){
    if(isPrime[i]){
      thePrimes.pb(i);
      for(int j{i*2};j<=n;j+=i){
        isPrime[j]=false;
      }
    }
  }
}
namespace std{
  template<typename T,typename U> inline constexpr bool issamev=std::is_same<T,U>::value;
}
//https://mirror.codeforces.com/problemset/problem/385/B
void bearANDstring(bool last=false){
  string s{};
  cin >> s;
  const string theTarget{"bear"};
  using ip = typename std::pair<int,int>;
  #define mp make_pair
  vector<ip> theIxs{};
  theIxs.reserve(5000);
  const auto& n{int(size(s))};
  typename std::string::size_type pos=0;
  while(1){
    auto pos2=s.find(theTarget,pos);
    if(pos2==string::npos)break;
    theIxs.emplace_back(pos2,pos2+size(theTarget)-1);
    pos=++pos2;
  }
  using ll = long long;
  ll res=0;
  const auto& l{int(size(theIxs))};
  for(int i{};i<l;++i){
    auto left{theIxs[i].f};
    auto right{theIxs[i].s};
    if(i==0 and i==l-1){
      left=max(1,left);
      right=n-right;
    }
    else if(i==0){
      left=max(1,left);
      right=n-right;
    }
    else if(i==l-1){
      right=n-right;
      left=left-theIxs[i-1].f;
    }
    else{
      right=theIxs[i+1].s-right;
      left=left-theIxs[i-1].f;
    }
    //cout << left << " " << right << "\n";
    res+=sc(right)*sc(left);
  }
  cout << res << "\n";
  return;
}
map<string,int> theGoodOnes{{"1",1},{"14",2},{"144",3}};
int goodNumber[20];
bool ig(const string& s,int i,int n){
  if(i==n)return true;
  if(goodNumber[i]!=-1){
    return goodNumber[i];
  }
  bool theResponse{false};
  for(const auto& [aString,aLength] : theGoodOnes){
    auto pos = s.find(aString,i);
    if(pos == i){
      theResponse |= ig(s,i+aLength,n);
    }
  }
  return goodNumber[i]=theResponse;
}
#define PRINTGRID
#undef PRINTGRID
int cache2[101][101];
static constexpr int INF{0x3f3f3f3f};
int finder(int iR,int nR,const vector<int>& reds,
int iB,int nB,const vector<int>& blue,int acc){
  if(iR==nR and iB==nB){
    return 0;
  }
  if(cache2[iR][iB]!=-INF){
    return cache2[iR][iB];
  }
  int ans=0;
  if(iR!=nR){
    ans=max(ans,max(acc+reds[iR],finder(iR+1,nR,reds,
    iB,nB,blue,acc+reds[iR])));
  }
  if(iB!=nB){
    ans=max(ans,max(acc+blue[iB],finder(
      iR,nR,reds,iB+1,nB,blue,acc+blue[iB])));
  }
  return cache2[iR][iB]=ans;
}
vector<int> aVectorCache{};
void init2(long long int n){
  if(n<2)return;
  aVectorCache.clear();
  aVectorCache.push_back(2ll);
  long long int delta{5ll};
  while(1){
    auto next{aVectorCache.back()+delta};
    if(next>n)break;
    aVectorCache.push_back(next);
    delta+=3ll;
  }
}
int theCaching[101][101];
int dfs(const vector<int>& a,int i,int k,int l){
  if(i==l)return 0;
  if(theCaching[i][k]!=-1){
    return theCaching[i][k];
  }
  if(k==1){
    int sub{};
    for(int j{i+1};j<l;++j){
      sub+=abs(a[j]-a[j-1]);
    }
    return sub;
  }
  int ans{INT_MAX};
  int j{i};
  int sub{};
  while(j<=(l-k)){
    if(j==i)ans=min(ans,dfs(a,j+1,k-1,l));
    else{
      sub+=abs(a[j]-a[j-1]);
      ans=min(ans,sub+dfs(a,j+1,k-1,l));
    }
    ++j;
  }
  return theCaching[i][k]=ans;
}
void killIII(bool last=false){
  int n,k;
  cin>>n>>k;
  int num;
  cin>>num;
  string s{to_string(num)};
  cin>>s;
  if(k==0){
    cout<<s;
    return;
  }
  if(n==1){
    cout<<"0\n";
    return;
  }
  s.front()='1';
  --k;
  for(int i{1};i<n and k>0;++i){
    if(s[i]=='0')continue;
    --k;
    s[i]='0';
  }
  cout<<s;
  return;
}
typedef void(*funcptr)(int,int);
typedef void(func)(int,int);
namespace detail{
  template<typename T> struct type_identity{typedef T type;};
  template<typename T> auto try_add_pointer(int) -> 
  type_identity<typename std::remove_reference<T>::type*>;
  template<typename T> auto try_add_pointer(...) -> type_identity<T>;
}
template<typename T> struct addpointer: decltype(detail::try_add_pointer<T>(0)){};
template<typename T> using addpointer_t = typename addpointer<T>::type;
static_assert(std::is_same<funcptr,addpointer_t<func>>::value,"Types differ!\n");
using ll=long long int;
ll theDp[1'000'001][3];

template<typename...ARGS> auto makeArray(ARGS&&...args) -> typename std::array<std::common_type_t<ARGS...>,sizeof...(ARGS)>{
  return {std::forward<ARGS>(args)...};
}

void printAddress(){
  return;
}

template<typename Head, typename ... Tail> auto printAddress(Head&& _ptr, Tail&& ... _tail) -> void {
  std::cout << _ptr << "\n";
  if(sizeof...(Tail)){
    printAddress(_tail...);
  }
}
void kill_pb1_contest_13_01_2024(){
  int m;
  cin>>m;
  return;
}
namespace {
  vector<pair<int,ll>> queries{};
  const bool preCompute{false};
  void theTerminator2(){
    sort(begin(queries),end(queries),[](auto&& x,auto&& y){
      return x.s<y.s;
    });
    bool isPrime[queries.back().s+1];
    isPrime[0]=isPrime[1]=false;
    memset(isPrime,1,sizeof isPrime);
    vector<ll> _thePrimes{};
    for(ll i{2};i<=queries.back().s;++i){
      if(isPrime[i]){
        _thePrimes.emplace_back(i);
        for(ll j{i*2};j<=queries.back().s;j += i){
          isPrime[j]=false;
        }
      }
    }
    sort(begin(queries),end(queries),[](const auto& x,const auto& y){
      return x.f<y.f;
    });
    for(const auto& [theNum,_]: queries){
      if(isPrime[theNum]){
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
    }
  }
  void theTerminator() {
    vector<ll> a;
    for(auto&& x: queries){
      a.push_back(x.s);
    }
    sort(begin(a),end(a),less<ll>());
    auto it=unique(begin(a),end(a));
    a.resize(it-begin(a));
    const auto& m{int(size(a))};
    int i{0};
    map<ll,ll> _cacher{};
    auto mx{a.back()};
    ll sum{};
    for(ll j{1ll};j<=mx;++j){
      auto jj{j};
      while(jj){
        sum += (jj%10);
        jj/=10;
      }
      if(a[i]==j){
        _cacher.emplace(j,sum);
        ++i;
      }
    }
    for(const auto& [_,theNum] : queries){
      cout << _cacher[theNum] << "\n";
    }
  }
}
#include<string_view>
using namespace std::literals;
vector<int> decimals{};
int len=0;
namespace std{
  ostream& operator<<(ostream& os,const std::tuple<int,ll>& iTuple){
    return os << std::get<0>(iTuple) << " " << std::get<1>(iTuple) << "\n";
  }
}

void kill(){
  int n,m;
  cin>>n>>m;
  static constexpr const int theSize{2};
  vector<vector<vector<int>>> _tiles(n,vector<vector<int>>(theSize,vector<int>(theSize,0)));
  vector<vector<int>> _temp(theSize,vector<int>(theSize,0));
  int p{};
  for(int i{};i<2*n;++i){
    int a,b;
    cin>>a>>b;
    _temp[p][0]=a,_temp[p][1]=b;
    ++p;
    if(p==2){
      p=0;
      _tiles[i/2] = _temp;
    }
  }
  if(m&1){
    cout<<"NO\n";
    return;
  }
  std::function<bool(int)> isSymmetric = [&_tiles](int i){
    return (_tiles[i][0][1]==_tiles[i][1][0]);
  };
  for(int i{};i<n;++i){
    if(isSymmetric(i)){
      cout<<"YES\n";
      return;
    }
  }
  cout<<"NO\n";
  return;
}
int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif
#if !defined(ONEPROBLEM)
    int n=1;
    cin>>n;
    //cin.ignore(std::numeric_limits<std::size_t>::max(),'\n');
    for(int i=0;i<n;i++){
       if(preCompute){
        ll x,y;
        cin>>x>>y;
        queries.emplace_back(i+1,(x-y)*(x+y));
        theTerminator2();
       }
       else{
        kill();
       }
   }
#elif defined(ONEPROBLEM)
   kill();
#endif
  return 0;
}
