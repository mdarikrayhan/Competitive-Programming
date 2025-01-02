#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
#define Nmax 200100
int N;
string s, t;
int beg[Nmax], en[Nmax];

class Aho {
public:
  int sigma = 26; // alphabet size 
  int off = 'a';
  int to[Nmax][26]; // todo: change / resize
  int sz = 1; // nodes
  int NR = 0; // terminal nodes
  int tr[Nmax], term[Nmax], cnt[Nmax];
  int link[Nmax]; // fail edge


  Aho(int sg, int offset) {sigma = sg; off = offset;}
  Aho() {}

  void add(string &s) {
    int cur = 0; // root
    for(auto c: s) {
      if(!to[cur][c - off]) {
          to[cur][c - off] = sz++;
      }
      cur = to[cur][c - off];
    }
    term[cur] = cur;
    tr[cur] = ++NR; 
    cnt[cur]++;
  }
   
  void push_links() {
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()) {
      int V = Q.front(); Q.pop();
      int U = link[V];
      if(!term[V]) term[V] = term[U];
      for(int c = 0; c < sigma; c++) {
        if(to[V][c]) {
            link[to[V][c]] = V ? to[U][c] : 0;
            Q.push(to[V][c]);
        } else {
            to[V][c] = to[U][c];
        }
      }
    }
  }

  void match(string &s, int fl) {
    int cur = 0;
    for(int i=0;i<sz(s);++i) {    
      char c = s[i];
      cur = to[cur][c-off];
      int f = cur;
      while(f) {
        if(tr[f]) {
          if(fl == 0) en[i] += cnt[f];
          else beg[i] += cnt[f];
        }
        if(f == term[f]) f = term[link[f]];
        else f = term[f];
      }
    }
  }
};

Aho aho1, aho2;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>s>>N;
  
  FOR(i, N) {
    cin>>t;
    aho1.add(t);
    reverse(all(t));
    aho2.add(t);
  }
  aho1.push_links();
  aho1.match(s,0);

  aho2.push_links();

  reverse(all(s));
  aho2.match(s,1);

  ll ret = 0;

  FOR(i, sz(s)-1) {
    //cout<<i<<" "<<en[i]<<" "<<beg[sz(s)-2-i]<<endl;
    ret += 1LL*en[i]*beg[sz(s)-2-i];
  }
  cout<<ret<<"\n";

  return 0;
}