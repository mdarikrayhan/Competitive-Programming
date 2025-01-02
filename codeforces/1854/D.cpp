// LUOGU_RID: 160024155
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=505;
int n,a[N],vis[N],tot;
inline bool ask(int u,int k,vector<int>S){
    cout<<"? "<<u<<' '<<k<<' '<<S.size()<<' ';
    for (auto it:S) cout<<it<<' ';
    cout<<endl;
    int rd;cin>>rd;
    return rd;
}
inline int work(int x,int bu){
    vector<int>V;
    rep(i,1,n) V.push_back(i);
    while (V.size()>1){
        vector<int>K;
        int len=V.size();
        rep(i,0,len/2-1) K.push_back(V[i]);
        if (ask(x,bu,K)) V=K;
        else{
            K.clear();
            rep(i,len/2,len-1) K.push_back(V[i]);
            V=K;
        }
    }
    return V[0];
}
inline bool getqry(int u,int bu){
    cout<<"? "<<u<<' '<<bu<<' '<<tot<<' ';
    rep(i,1,tot) cout<<a[i]<<' ';
    cout<<endl;
    int rd;cin>>rd;
    return rd;
}
inline void print(){
    cout<<"! "<<tot<<' ';
    sort(a+1,a+tot+1);
    rep(i,1,tot) cout<<a[i]<<' ';
    cout<<endl;
}
void solve(){
    cin>>n,a[++tot]=work(1,1e8),vis[a[tot]]=1;
    rep(i,1,63){
        int T=work(a[tot],1);
        if (T==a[1]) break;
        a[++tot]=T,vis[T]=1;
    }
    if (tot<63){
        rep(i,1,n){
            if (vis[i]) continue;
            if (getqry(i,1e8)) vis[i]=1,a[++tot]=i;
        }
        print();
        return;
    }
    rep(i,1,n){
        if (vis[i]) continue;
        if (getqry(i,63)) vis[i]=1,a[++tot]=i;
    }
    if (tot<63*2){
        rep(i,1,n){
            if (vis[i]) continue;
            if (getqry(i,1e8)) vis[i]=1,a[++tot]=i;
        }
        print();
        return;
    }
    rep(i,1,n){
        if (vis[i]) continue;
        if (getqry(i,63*2)) vis[i]=1,a[++tot]=i;
    }
    if (tot<63*4){
        rep(i,1,n){
            if (vis[i]) continue;
            if (getqry(i,1e8)) vis[i]=1,a[++tot]=i;
        }
        print();
        return;
    }
    rep(i,1,n){
        if (vis[i]) continue;
        if (getqry(i,63*4)) vis[i]=1,a[++tot]=i;
    }
    rep(i,1,n){
        if (vis[i]) continue;
        if (getqry(i,1e8)) vis[i]=1,a[++tot]=i;
    }
    print();
}
signed main(){
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}