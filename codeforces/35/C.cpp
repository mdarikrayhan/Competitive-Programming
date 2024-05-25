#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define yes cout<<"YES";
#define no cout<<"NO";
#define ___          cout << (flag?"YES":"NO");
#define nl "\n"
#define __ endl
#define sz(s) (int)(s).size()
#define fr(n) for(int i = 0; i < n; ++i)
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
#define ld long double
#define aw3dni_ink_tet3aleg ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
const double PI = 3.14159265359;
#define sp(x) fixed<<setprecision(x)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
using namespace std;
const ull N = 1e5 + 5, oo = 0x3f3f3f3f3f3f3f3f, modd = 1e9 + 7;

//=======================================================================================
// to remove leading zeros from string =ans
// ans-erase(0(pos), ans.find_first_not_of('0'))==>this built in func mean
// This function searches the string for the first character that is not equal to '0' and returns the position of that character.
//(::string::npos)is equal -1 (not found)
// 2D vec-->> vector<vector<int>>v1(n,vector<int>(n))
//check=================================================================================================================
// INT16_MAX not
// sz vector !!
// take input first !!
// intermediate overflow !! do (subtract || div) first
// map,freq or bool to check
//check max num can you use to fit (focus on power )
// if in problem will be cycle and repeated check % (rem)
// push_back O(1)// s+=ss[i] O(N)
// fac(6) can divide of any lees than him ==>fac(6,5,4,3,2,1)
// cout<<fixed<<sp(0) ;
// if u can loop from 1 to max_element in array && time less than max size in vec use map
// reverse pq priority_queue<int, vector<int>, greater<int> > pq;
//back forward thinking??! العكس يباشا مترجعش من الاول زي العبيط
// should to be 2*1e9 not 1e18
//======================================================================================================================
typedef vector<vector<ll>> GRAPH;
int n,m;;
bool visited [2005][2005];
// this is (x+1,y),(x-1,y),(x,y+1),(x,y-1)
int x_inc[] = {1,-1,0,0}; // increase in x
int y_inc[] = {0,0,1,-1}; // increase in y
bool within_forest(int x,int y){ // to check i'm in bound or not(into grid)
    if(x<1||x>n)return false;
    if(y<1||y>m)return false;
    return true;
}
void solve() {
    cin>>n>>m;
    int k;cin>>k;
    queue<pair<ll,ll>>nxt_to_visit;
    while (k--){
        int x,y;cin>>x>>y;
        nxt_to_visit.push({x,y});
        visited[x][y]=true;
    }
    pair<ll,ll>ans;
    while (!nxt_to_visit.empty()){
        pair<ll,ll> curr=nxt_to_visit.front();
        ans=curr; // to save every time my current tree
        nxt_to_visit.pop();
        for (int i = 0; i < 4; ++i) {
            int x_new= curr.first+x_inc[i];
            int y_new= curr.second+y_inc[i];
            if(within_forest(x_new,y_new)&&!visited[x_new][y_new]){
                nxt_to_visit.push({x_new,y_new});
                visited[x_new][y_new] = true;
            }
        }
    }
    cout<<ans.first<<" "<<ans.second;
}

signed main() {
    //=========================================================================
    aw3dni_ink_tet3aleg
  //  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   // #endif
    //=========================================================================
    int T = 1;
  //  cin >> T;
    //linear_sieve();
    while (T--) {
        solve();
        cout << nl;
    }
    return 0;
}