// LUOGU_RID: 160424503
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
inline int query(int l,int r){
    cout<<"? "<<l<<' '<<r<<' '<<2<<endl;
    int x;cin>>x;
    return 2*x-(r-l+1);
}
int n,tag,flg;
inline void work(int l,int r){
    if (l==r) return cout<<"! "<<l<<endl,void();
    int mid=(l+r)>>1,lf=query(1,mid),rg=query(mid+1,n);
    if (lf>rg) work(l,mid);
    else if (lf<rg) work(mid+1,r);
    else{
        if (!tag){
            if (mid>1){
                cout<<"? "<<1<<' '<<mid<<' '<<n<<endl;
                int x;cin>>x;
                if (x>1) flg=0;
                else flg=1;
            }else{
                cout<<"? "<<mid+1<<' '<<n<<' '<<n<<endl;
                int x;cin>>x;
                if (x==1) flg=0;
                else flg=1;
            }
            tag=1;
        }
        if (!flg) work(mid+1,r);
        else work(l,mid);
    }
}
void solve(){
    cin>>n;
    work(1,n);
}
signed main(){
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}