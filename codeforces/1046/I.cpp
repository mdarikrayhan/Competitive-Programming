#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)
#define point complex<ll>
#define x real()
#define y imag()
using namespace std;

ll dot(point a,point b){
    return real(conj(a)*b);
}
ll cross(point a,point b){
    return imag(conj(a)*b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int n;
    ll d1,d2;
    cin>>n>>d1>>d2;
    auto f=[&](point p)->int{
        ll v=(p*conj(p)).x;
        if(v<=d1*d1) return -1;
        else if(v>d2*d2) return 1;
        return 0;
    };
    auto check=[&](point p,point v,point q)->bool{
        if(dot(v,q-p)>=0 && dot(-v,q-p-v)>=0){
            ll cs=abs(cross(v,q-p));
            return cs*cs<=d1*d1*(v*conj(v)).x;
        }else{
            return false;
        }
    };
    vector<point> a(n),b(n);
    vector<int> c;
    for(int i=0;i<n;i++){
        int u,wu;
        cin>>u>>wu;
        a[i]=point(u,wu);
        cin>>u>>wu;
        b[i]=point(u,wu);
        int cc=f(a[i]-b[i]);
        if(i>0){
            if(f(a[i-1]-b[i-1])!=-1 && cc!=-1 && check(a[i-1],a[i]-a[i-1]-b[i]+b[i-1],b[i-1])) c.pb(-1);
        }
        if(cc!=0) c.pb(cc);
    }
    int cnt=c[0]==-1;
    for(int i=1;i<c.size();i++){
        if(c[i]==-1 && c[i-1]==1) cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * bitwise and boolean operations
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

