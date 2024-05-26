#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=300000;
int a[N+1],c[N+1],f[N+1][20];
//vector<int>v[N+1];
void solve(){
    memset(f,-1,sizeof f);
    int q;
    cin>>q>>a[0]>>c[0];
    for(int _=1;_<=q;_++){
        int op;cin>>op;
        if(op==1){
            int p;cin>>p>>a[_]>>c[_];
            f[_][0]=p;
            for(int i=1;i<20;i++){
                f[_][i]=f[f[_][i-1]][i-1];
                if(f[_][i]==-1) break;
            }
        }else{
            int v,w;cin>>v>>w;
            int _a=0,cost=0;
            while(w && a[v]){
                int u=v;
                for(int i=19;i>=0;i--){
                    if(~f[u][i] && a[f[u][i]]){
                        u=f[u][i];
                    }
                }
                int d=min(a[u],w);
                cost+=d*c[u];
                _a+=d;
                a[u]-=d;
                w-=d;
            }
            cout<<_a<<' '<<cost<<endl;
        }
    }
}
signed main() {
//    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;//cin>>_;
    while(_--){
        solve();
    }
}