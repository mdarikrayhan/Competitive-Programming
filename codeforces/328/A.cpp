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

void solve() {
    ld a,b,c,d;cin>>a>>b>>c>>d;
    ld aa=0,bb=0,cc=0,aaa=0,bbb=0,ccc=0;
    aa=b-a;
    bb=c-b;
    cc=d-c;
    aaa=b/a;
    bbb=c/b;
    ccc=d/c;
//    cout<<aa<<nl<<bb<<nl<<cc<<nl;
//cout<<(ld)d*ccc<<nl<<((ll)d*ccc)<<nl;
    if(aaa==bbb &&aaa==ccc &&bbb==ccc){ // check geometric progression
        ll tmp = d*ccc;
         cout<<(((ld)d*ccc - tmp >0) ? 42 :d*ccc); // to check if int or not (in problem)
    }
    else if(aa==bb &&bb==cc &&aa==cc){ // check arithmetic progression
        cout<<d+cc;
    }
    else{
        cout<<42;
    }
}

signed main() {
    //=========================================================================
    aw3dni_ink_tet3aleg
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //=========================================================================
    int T = 1;
//    cin >> T;
    //linear_sieve();
    while (T--) {
        solve();
        cout << nl;
    }
    return 0;
}