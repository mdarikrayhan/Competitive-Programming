#include <bits/stdc++.h>
#define f first
#define s second
#define ent '\n'
#define int long long

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")

//typedef long double ld;
typedef long long ll;
using namespace std;

struct node{double x,y;};
//double len(node a,node b)
//{return sqrt((a.x-b.x)*(a.x-b.y)+(a.y-b.y)*(a.x-b.y));}

struct seg{
    int mx1=0,mx2=0,ans=0;
};

const string out[2]={"NO\n","YES\n"};
const ll dx[]={0,0,1,-1,-1,1,1,-1};
const ll dy[]={1,-1,0,0,-1,1,-1,1};
//const int mod=998244353;
//const int md=1e9+7;
const int mx=1e6+12;
const int tst=1e5;
const bool T=0;

int pref[mx];
int b[mx];
int n, m, k;

void Press_Fn_with_F11() {
    string s;
    cin >> n >> m >> s;
    int mn = 0, val = 0;
    for(auto x:s){
        if(x == ')'){
            val--;
        }
        else val++;
        mn = min(mn, val);
    }
    int t = abs(mn);
    reverse(s.begin(), s.end());
    while(mn < 0){
        val++;
        mn++;
        s += '(';
    }
    reverse(s.begin(), s.end());
    while(val > 0){
        val--;
        s += ')';
    }
    stack<int> st;
    n = s.size();
    for(int i=1;i<=n;i++){
        if(s[i-1] == ')'){
            b[i] = b[st.top()-1] + 1;
            st.pop();
        }
        else st.push(i);
        pref[i] = pref[i-1] + b[i];
    }
    while(m--){
        int tt, l, r;
        cin >> tt >> l >> r;
        l += t, r += t;
        cout << pref[r] - pref[l] - (b[r] - b[l-1]) * b[l-1] << ent;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    int d = 5e8;
    if(T)cin>>t;
    for(int i=1;i<=t;i++) {
//    	cout<<"Case "<<i<<": ";
        Press_Fn_with_F11();
    }
}