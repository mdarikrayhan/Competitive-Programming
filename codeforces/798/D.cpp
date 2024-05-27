//  Esti <3

//\
     šťastia pre nás :)
//   you're already the best
//             _
//   ^ ^      //
// >(O_O)<___//
//   \ __ __  \
//    \\ \\ \\\\
 
#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

using ll = long long;
//#define int long long
#define forn(i,n) for(int i=0; i<(n); ++i)
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second 
#define vii(a,n) vector<int> a(n); forn(i,n) cin>>a[i];
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll inf = 1e18;
const ll mod = 998244353;

// \
\
:smiling_face_with_3_hearts: :smiling_face_with_3_hearts:  :smiling_face_with_3_hearts:  
 
//vidime sa veľmi skoro, moje slnko

//[] {}

/*
⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⢿⢂⢂⢂⢂⠔⡐⡐⢔⢔⢡⠪⣛⣿⣿⣿⣿⣿⣿⣿
⣿⡯⣿⣯⣿⣯⣿⡿⣾⢝⢑⢐⢐⠔⢔⢱⢘⢌⢆⡧⣣⡣⡳⡜⡽⣾⣿⣯⣿⣷
⣽⣿⡿⣿⢽⣾⣿⡻⡋⡂⢆⢑⢜⠸⡸⡘⡜⣜⢜⢜⢜⢜⢕⢕⠱⡽⣿⣾⣿⣽
⢵⣻⣿⣯⣳⣿⣟⡯⠪⠐⠌⡂⢅⠇⡕⢕⢱⡿⡜⡸⡰⡑⢅⢇⠣⢝⡿⣯⣿⣿
⢼⣽⢻⣿⣻⣷⡷⡩⡱⢁⠣⢘⠄⢕⠜⠜⢒⢂⢇⣎⢆⢌⡄⢕⢁⡳⣫⣟⣯⣿
⠿⣽⣿⣿⣯⠧⡗⡕⢔⢐⢈⠐⢍⠢⡃⡣⡭⣽⣺⣺⡳⣜⢮⠸⣰⣮⣻⣿⣿⢿
⠪⡸⣘⢓⢕⠕⢕⠅⠕⡐⡐⢌⢈⠔⢌⢢⡫⣞⡾⡲⡪⡯⠇⢕⢼⣿⣾⣿⣻⣿
⠨⡂⠆⠕⡡⢊⠢⠨⡈⡮⡾⢜⠦⠂⡘⡰⡩⡚⡺⢝⢼⢡⢨⢺⣯⣿⣷⣿⢿⣟
⠡⡨⠨⢂⣢⠡⢊⢔⡽⡣⣋⢞⡝⢵⢲⡐⡕⡜⡄⠐⠨⡋⢔⢹⣿⡿⣷⣿⣿⣿
⠐⣼⢿⠫⡐⠌⡂⡾⢜⠜⡕⡽⡪⢏⡗⡧⣣⢣⢲⠠⡀⢜⠰⡡⠻⣿⣿⣯⣷⣿
⣸⣶⠟⡑⢄⢱⣸⣅⠅⠨⠈⠄⠌⡢⠨⢑⠑⢣⠱⡹⣪⠄⠑⢕⣯⢝⢿⣽⣻⣿
⡟⡐⡐⡐⣰⣰⣿⡍⠀⠂⠁⢌⠊⠔⡑⠄⠌⠄⡈⠪⡱⠏⣇⠕⡺⣿⣮⣛⢻⣿
⢇⢂⠢⢢⢯⣿⣿⣦⣄⠈⠐⠠⠡⢑⠠⠁⠈⠢⠨⠔⢘⢕⢵⣱⢑⢿⣿⡿⣷⣖
⢐⡐⠡⡿⣦⢿⣷⣿⠇⠀⢁⠨⠀⠅⢂⠁⠈⠀⡂⠌⢀⠎⣮⡪⡇⡆⠽⣿⣿⣿
⢘⢌⣧⠚⣿⢿⣷⣿⠂⠈⢀⠠⠐⠈⠠⠈⡀⠠⠐⢀⢁⠈⡎⠮⡺⡘⠐⠻⣾⣿
*/

void solve() {

    int n; cin>>n;
    vii(a,n);
    vii(b,n);
    vector<pi> v(n);
    forn(i,n) v[i]={a[i],i};
    sort(rall(v));
    vector<int> ans={v[0].s};
    for(int i=1; i+1<n; i+=2) {
        if (b[v[i].s] >= b[v[i+1].s]) ans.pb(v[i].s);
        else ans.pb(v[i+1].s);
    }
    if (n&1); else ans.pb(v.back().s);
    sort(all(ans));
    cout<<ans.size()<<'\n';
    for(auto&x:ans) cout<<x+1<<' ';

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1; 
    //cin>>t;
    while (t--) solve();
    return 0;
}