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
void TT(){
    int n, k, m;
    cin>>n>>k>>m;
    vector<int>b(m);
    for(int &i:b) cin>>i;
    if((n-m)%(k-1)) return void(cout<<"NO\n");
    vector<int>erased;
    for(int i=1;i<=n;i++) if(!binary_search(b.begin(), b.end(), i)) erased.push_back(i);
    for(int i:b){
        int smaller = lower_bound(erased.begin(), erased.end(), i)-erased.begin();
        int bigger = int(erased.size())-smaller;
        if(bigger>=(k-1)/2 && smaller>=(k-1)/2) return void(cout<<"YES\n");
    }
    cout<<"NO\n";
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
