// LUOGU_RID: 160425333
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
inline int query(int l,int r){
    cout<<"? "<<l<<' '<<r<<' '<<2<<endl;
    int x;cin>>x;
    return 2*x-(r-l+1);
}
int const N=1e4+10;
int n,tag,flg,Ql[N],Qr[N];
inline void work(int l,int r){
    if (n&1){
        if (l==r) return cout<<"! "<<l<<endl,void();
    }else{
        if (l==r) return cout<<"! "<<l<<endl,void();
        if (l+1==r){
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
                cout<<"! ";
                if (!flg) return cout<<r<<endl,void();
                else return cout<<l<<endl,void();
            }
            int Lf=Ql[l-1],Rg=Qr[r+1];
            if (!flg) --Lf;
            else --Rg;
            if (Lf>Rg){
                int B=query(1,l);
                cout<<"! ";
                if (B<Ql[l-1]) return cout<<r<<endl,void();
                else return cout<<l<<endl,void();
            }else{
                int B=query(r,n);
                cout<<"! ";
                if (B<Qr[r+1]) return cout<<l<<endl,void();
                else return cout<<r<<endl,void();
            }
        }
    }
    int lf=query(1,mid),rg=query(mid+1,n);
    Ql[mid]=lf,Qr[mid+1]=rg;
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