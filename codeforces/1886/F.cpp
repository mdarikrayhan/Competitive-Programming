// #define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
using namespace std; typedef long long ll;
constexpr int N=4505;
int n,a[N],an,b[N],bn,c[N],cn;
int solve(int d){
    static int val[N],res[N]; For(i,1,n*3) val[i]=res[i]=0;
    val[d]--; res[d]--; For(i,1,an) val[d+a[i]]--,res[d+a[i]]--;
    static int st[N]; int tp=0,cur=0,x=1;
    while(x<=cn&&c[x]<=d) val[d+c[x]]--,res[d+c[x]]--,res[c[x]]--,x++;
    For(i,d+1,n*3){
        while(x<=cn&&c[x]==i){
            x++; val[i]--; res[i]--; st[++tp]=i;
        }
        cur+=val[i]+1;
        while(cur<0){
            if(tp==0) return 1e9;
            int w=st[tp--]; val[w]++; cur++; val[d+w]--; res[d+w]--; if(d+w<=i) cur--;
        }
    }
    For(i,1,bn) res[b[i]]--;
    int tt=0; For(i,1,n*3) { tt+=res[i]; if(tt+i<0) return 1e9; }
    return -tt;
}
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    cin>>n; For(i,1,n) { int op,x; cin>>op>>x; if(op==1) a[++an]=x; else if(op==2) b[++bn]=x; else c[++cn]=x; }
    if(n==0) { cout<<"2\n"; return 0; }
    sort(a+1,a+1+an); sort(b+1,b+1+bn); sort(c+1,c+1+cn); int ans=1e9;
    For(d,1,n+1){
        int res=solve(d); debug(d,res); ans=min(ans,res);
    }
    if(ans==1e9) cout<<"-1\n"; else cout<<ans+1<<'\n';
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: May 12 Sun, 09 : 10 : 17