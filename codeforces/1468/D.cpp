//نفعكم الله ووفقكم -ادع لي-
//اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
//اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين. اللهم اطمس على أعداء الدين والمدنسين -الصهاينة اللصوص-
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;

#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define PI acos(-1)

template<class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+9, M = 2e5 + 6, MOD = 1e9+7, OO = 0x3f3f3f3f, SQR = 320;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
bool valid(int x, int y, int nnn, int mmm){return x>=0&&x<nnn&&y>=0&&y<mmm;}
int Log2(int x) {return 31-__builtin_clz(x);}
int check(int idx, vector<int>&e, int rem){
    int cnt=0;
    for(int i=idx-1, sec=1;i>=0;i--)
        if(e[i]<=rem-sec) cnt++, sec++;
    return cnt;
}
void TT(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    vector<int>explosions(m);
    for(int &e:explosions) cin>>e;
    sort(explosions.begin(), explosions.end());
    int e, ans;
    if(a<b){
        e=min(m, b-a-1);
        ans=check(e, explosions, b-1);
    } else{
        e=min(m, a-b-1);
        ans=check(e, explosions, n-b);
    }
    cout<<ans<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FAST
    int testCases = 1;
    cin >> testCases;
    while (testCases--) TT();
    return 0;
}
// You Got this! Bear those in mind:
//      * Read the problem Carefully
//      * BrainStorm & Think Twice, code once.
//      * Overcome Corner Cases.
//      * Have a quick revision of the code before submitting
