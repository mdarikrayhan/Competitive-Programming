#include <bits/stdc++.h>
using namespace std;

// #define __ll128_t i128
const double eps = 1e-6;
#define ll long long
typedef long double ld;
#define pb push_back // for vector
#define pi pair 
// #define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define ff first
#define ss second
#define vt vector
#define vi vt<ll>
#define ub upper_bound
#define lb lower_bound
#define repr(i, n, a) for (ll i = n; i >= a; i--)
#define dq deque
#define inset(a, st) st.find(a) != st.end()
#define issub(a, b) b.find(a) != string::npos // check if a is substr of b
#define len(a) (ll)a.size()
const ld PI = 2 * acos(0.0);
const ll mod = 1e9 + 7;
const ll nax = 2e5 + 5;
void ff(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool cmp(pi<int,int>&a, pi<int,int>&b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  else {
    if(a.first > b.first){
       if(a.second == 0){
        return 0;
       }
       else {
        return 0;
       }
    }
    else {
       if(b.second == 0){
        return 1;
       }
       else {
        return 1;
       }
    }
  }
}

class Pair {
  public :
  ll coeff;
  ll val;
  ll res;
  Pair (ll coeff, ll val, ll res){
    this->coeff = coeff; this->val = val; this->res = res;
  }
  Pair (){}
};

bool cmp3(Pair & a, Pair & b){
  if(a.res == b.res){
    return a.val > b.val;
  }
  return a.res < b.res ;
}


void solve(){
int a; 
cin>>a;
string s; cin>>s;
vt<string>v;

int i  = 0 , j = 0;
while(j < (int)s.size()){

  if(s.substr(j, 3) == "++a" || s.substr(j , 3) == "a++"){
     v.push_back(s.substr(i , j+2-i+1));
     j += 3;
     i = j;
     continue;
  }
  j++;
}

ll sol = 0;
vt<pi<int , int>>vals;
rep(i , 0 , v.size()){
  string num = "";
  int j = 0;
 
  while( v[i][j] != '*' && v[i][j] != 'a'){
    num = num + v[i][j];
    j++;
  }
  
  if(num == "+" || num == "" || num == "+++"|| num == "++"){
    num = "1";
  }
  else if(num =="-" || num == "-++"){
    num ="-1";
  }
  if(v[i].substr(v[i].size() - 3 , 3 ) == "++a"){
    vals.push_back({stoi(num) , 0});
  }
  else {
    vals.push_back({stoi(num),  1});
  }
  
}
sort(all(vals), cmp);
rep( i , 0 , vals.size()){

  // cout << vals[i].first <<" "<<vals[i].second<<"  ";
  if(vals[i].second == 0){
    a++;
    sol += vals[i].first * a;
  }
  else {
   sol += vals[i].first*a;
   a++;
  }
}
cout << sol<<"\n";
}


int main(){

    // ff();
    // ll t;
    // cin>>t;
    
    // while(t--){
   
    solve();
// }

return 0;
}