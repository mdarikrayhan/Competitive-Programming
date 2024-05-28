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
const bool T=1;

int a[mx];
int n, m, k;

void Press_Fn_with_F11() {
    cin >> n;
    n <<= 1;
    int st = 0;
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        a[i] = (c == '1');
        st ^= a[i];
    }
    if(st || a[1] != a[n]){
        cout << "-1\n";
        return;
    }
    vector<string> ans;
    if(a[1]){
        string t = "";
        for(int i=1;i<=n;i++){
            a[i] ^= 1;
            if(i % 2){
                t += "()";
            }
        }
        ans.push_back(t);
    }
    int b1 = 0, b2 = 0;
    string s = "", t = "";
    for(int i=1;i<=n;i++){
        if(a[i]){
            if(b1 >= b2){
                b1--, b2++;
                s += ')';
                t += '(';
            }
            else{
                b1++, b2--;
                s += '(';
                t += ')';
            }
        }
        else{
            s += '(';
            t += '(';
            b1++, b2++;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(b1 > 0 && s[i] == t[i]){
            b1 -= 2;
            s[i] = t[i] = ')';
        }
    }
    ans.push_back(s);
    ans.push_back(t);
    cout << ans.size() << ent;
    for(auto s:ans){
        cout << s << ent;
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