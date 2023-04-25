// #define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
#define assume(expr) ((!!(expr))||(exit((fprintf(stderr,"Assumption Failed: %s on Line %d\n",#expr,__LINE__),-1)),false))
using namespace std;
#define double long double
const int N=105; typedef long long ll; using Vec = vector<double>;
const int A=100;
ll nnn; int n; Vec F[N],S[N];
// double Powsum(int t,int w) { double res=0; For(k,1,t) res+=pow(k,-w);; return res; }
const int M=5e5;
Vec Pre[A];
void InitPowSum() { For(w,1,A-1) { int sz=M/A; Pre[w].resize(sz); For(k,1,sz-1) Pre[w][k]=Pre[w][k-1]+pow(k,-1.0L*w); } }
double Powsum(ll t,int w){
    if(t==0) return 0.0;
    assume(Pre[w].size());
    if(t<ll(Pre[w].size())) return Pre[w][t];
    double a=Pre[w].size()-0.5,b=t+0.5; double ans=Pre[w].back();
    if(w==1) ans+=log(b)-log(a); else ans+=(pow(b,1.0L-w)-pow(a,1.0L-w))/(1.0L-w);
    return ans;
}
Vec Exp(const Vec& f){
    Vec g; int sz=f.size(); g.resize(sz); g[0]=exp(f[0]);
    For(i,0,sz-2) { For(j,0,i) g[i+1]+=(j+1)*f[j+1]*g[i-j];; g[i+1]/=(i+1.0L); }
    return g;
}
signed main(){
    InitPowSum();
    cin>>nnn>>n; For(i,1,n){
        ll a; cin>>a,a=nnn-a;
        F[i].resize(A); F[i][0]=-log(a);
        For(w,1,A-1) F[i][w]=((w&1)?1.0L:-1.0L)/w*Powsum(a-1,w);
        F[i]=Exp(F[i]); S[i].resize(A); partial_sum(F[i].begin(),F[i].end(),S[i].begin());
    }
    For(i,1,n){
        double ans=F[i][0]; For(j,1,A-1) { double tt=F[i][j]; For(k,1,n) if(k!=i) tt*=(1-S[k][j-1]);; ans+=tt; }
        cout<<setprecision(20)<<fixed<<ans<<'\n';
    }
    cerr<<"Time = "<<clock()<<" ms"<<endl;
    return 0;
}

// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING