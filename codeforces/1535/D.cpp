/*sankooru14*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define For(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); (begin) > (end) ? i-- : i++)
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
typedef vector <ll> vl;
typedef vector <int> vi;
typedef vector <pair<ll,ll>> vpl;
typedef vector <vl> vll;
typedef vector <vi> vii;
typedef vector <vll> vlll;
const ll MAXI= 1e15;
const ll mod = 1e9+7;
void fast(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
}
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
ll fast_pow(ll a, ll p) {
  ll res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
 
ll fact(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
 
ll ncr(ll n, ll k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}
//basic idea - we will represent each game as a node in a tree
//count will store {int,char} where int -> stores the possible number of winners until that game and char represents the winner at that game

int main()
{
  fast();
  int k;
  cin>>k;
  string s;
  cin>>s;
  int total_games = (1<<k)-1;
  int total_nodes = (1<<k)+total_games;
  pair <int,char> count[total_nodes+1];
  //first we will build a tree and each node will store no of possible winners until that game and winner at that game
  for(int i=total_games+1;i<=total_nodes;i++){
    count[i].ff = 1;
    //writing base case
  }
  int ind = 0;
  for(int level = k-1;level>=0;level--){
    int j = 1<<level;
    int node=j;
    while(j--){
      if(s[ind]=='0'){
        count[node].ff = count[(2*node)].ff ;
        count[node].ss = '0';
      }
      else if(s[ind]=='1'){
        count[node].ff = count[(2*node)+1].ff ;
        count[node].ss = '1';
      }
      else{
        count[node].ff = count[(2*node)+1].ff + count[(2*node)].ff;
        count[node].ss = '?';
      }
      
      ind++;
      node++;
    }
  }
  int q;
  cin>>q;
  while(q--){
    int p;
    char c;
    cin>>p>>c;
    //find the tree node of given game number
    int tree_index;
    
    for(int i=k-1;i>=0;i--){
      if(p>(1<<i)){
        p-=(1<<i);
      }
      else{
        tree_index = (1<<i)+(p-1);
        break;
      }
    }
    count[tree_index].ss = c;
    while(tree_index>0){
      if(count[tree_index].ss =='0'){
        count[tree_index].ff = count[tree_index*2].ff;
      }
      else if(count[tree_index].ss =='1'){
        count[tree_index].ff = count[(tree_index*2)+1].ff;
      }
      else{
        count[tree_index].ff = count[tree_index*2].ff + count[(tree_index*2)+1].ff;
      }
      tree_index/=2;
    }
    cout<<count[1].ff <<endl;

  }

  return 0;
}