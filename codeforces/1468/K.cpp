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
void changeDir(int &x, int &y, char c){
    if(c=='L') x--;
    else if(c=='R') x++;
    else if(c=='U') y++;
    else y--;
}
bool check(int x, int y, int bx, int by, string &s){
    for(char c : s) {
        int nx=x, ny=y;
        changeDir(nx, ny, c);
        if(!(nx==bx && ny==by)) changeDir(x, y, c);
    }
    return !x && !y;
}
void TT(){
    string s;
    cin>>s;
    int x=0, y=0, n=(int)s.size();
    set<pair<int, int>>st;
    for(int i=0;i<n;i++) {
        changeDir(x, y, s[i]);
        st.insert({x, y});
    }
    for(auto p:st) if(check(0, 0, p.first, p.second, s)) return void(cout<<p.first<<" "<<p.second<<'\n');
    cout<<"0 0\n";
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

	  	 		 	 		 			 		 		 		 		 	