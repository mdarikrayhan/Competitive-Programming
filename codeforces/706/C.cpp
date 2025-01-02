#include<bits/stdc++.h>
#define  ll  long long int
#define  pr priority_queue<int>
#define vll vector<ll>
#define vvll vector<vll>
#define all(vc) ((vc).begin()), ((vc).end())
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);

#define inf 1000000000000000
#define low lower_bound(arr, arr + n, x)
// getline(cin, s);
//upper_bound(arr, arr+5, 35) - arr;
//lower_bound(arr, arr+n, p) - arr;
// *max_element(arr+l , arr+r+1) ;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//distance(set.begin(), set.lower_bound(n))
//last elment in set rbegin(),erase elemint st.erase(st.find(x));
//result += (arr[i] * (i + 1) * (n - i));
#define  pq1  priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<int>>
//vector<vector<bool>> vis(r, vector<bool>(c,0));
//fixed << setprecision(3)
//ans.to_ullong()
//rotate(c.begin(), it, c.end());
/*
auto it = unique(v.begin(), v.end());
      v.resize(distance(v.begin(), it));
 */
 // cout.precision(15);
using namespace std;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
const int N=2e5+5;
ll dp[2][N];
vector<ll>v(N);
ll ans2=1e16;
vector<pair<string,string>>vc(N);
int n;
bool can(string s1,string s2){
    for(int i=0;i<min(s1.size(),s2.size());i++){
        if(s1[i]<s2[i])return false;
        if(s1[i]>s2[i])return true;
    }
    if(s1.size()>=s2.size())return true;
    return false;
}
ll rec(int i,int lastch){
    if(i==n+1){
            return 0;
      }
          ll&ret=dp[lastch][i];
             if(~ret)return ret;
         ret=1e16;
    if(lastch==0){
        if(can(vc[i].first,vc[i-1].first)&&can(vc[i].second,vc[i-1].first)){
              ret=min(ret,rec(i+1,0));
             ret=min(ret,rec(i+1,1)+v[i]);

        }
        else if(can(vc[i].first,vc[i-1].first)){
            ret=min(ret,rec(i+1,0));
        }
        else if(can(vc[i].second,vc[i-1].first)){
            ret=min(ret,rec(i+1,1)+v[i]);

        }
        else{
            return 1e16;
        }
    }
    else{
         if(can(vc[i].first,vc[i-1].second)&&can(vc[i].second,vc[i-1].second)){
           ret=min(ret,rec(i+1,0));
             ret=min(ret,rec(i+1,1)+v[i]);

        }
        else if(can(vc[i].first,vc[i-1].second)){
               ret=min(ret,rec(i+1,0));
        }
        else if(can(vc[i].second,vc[i-1].second)){
          ret=min(ret,rec(i+1,1)+v[i]);
        }
        else{
            return 1e16;
        }
    }
    return ret;
   // return ret;
}
void solve(){


     cin>>n;
    memset(dp,-1,sizeof(dp));
     for(int i=1;i<=n;i++){
        cin>>v[i];
     }
     vc[0].first="a";
     vc[0].second="a";
     for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        vc[i].first=s;
        reverse(all(s));
        vc[i].second=s;
     }
     ll ans=rec(1,0);
     if(ans>=1e16){
        cout<<-1;
     }
     else{
        cout<<ans;
     }


 }


int main()
{

    Hakuna_Matata;
   int t=1;
  // cin>>t;
   while(t--){
   solve();
   }
    return 0;
}


