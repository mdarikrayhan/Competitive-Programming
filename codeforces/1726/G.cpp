#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010,mod=998244353;
inline void Add(int&x,int y){
    x=(x+y>=mod?x+y-mod:x+y);
}
inline void Sub(int&x,int y){
    x=(x-y<0?x-y+mod:x-y);
}
int n;
pair<int,int>a[N],tmp[N];

int nd[N],c[N],tot;

vector<int>vec;
struct Seg{
    struct Node{
        int l,r;
        int mv;
    }tr[N<<2];
    void pushup(int p){
        tr[p].mv=min(tr[p<<1].mv,tr[p<<1|1].mv);
    }
    void build(int p,int l,int r){
        tr[p].l=l,tr[p].r=r;
        if(l==r){
            tr[p].mv=nd[l];
            if(nd[l]==0){
                vec.push_back(l);
                tr[p].mv=1e9;
            }
            return;
        }
        int mid=(l+r)>>1;
        build(p<<1,l,mid),build(p<<1|1,mid+1,r);
        pushup(p);
    }
    void pushdown(int p){
        int d=min(tr[p<<1].mv,tr[p<<1|1].mv)-tr[p].mv;
        if(d){
            tr[p<<1].mv-=d,tr[p<<1|1].mv-=d;
        }
    }
    void change(int p,int l,int r,int x){
        if(l<=tr[p].l&&tr[p].r<=r){
            if((tr[p].mv+=x)==0){
                if(tr[p].l==tr[p].r){
                    vec.push_back(tr[p].l);
                    tr[p].mv=1e9;
                }
                else{
                    pushdown(p);
                    change(p<<1,l,r,0),change(p<<1|1,l,r,0);
                    pushup(p);
                }
            }
            return;
        }
        pushdown(p);
        if(l<=tr[p<<1].r)change(p<<1,l,r,x);
        if(r>=tr[p<<1|1].l)change(p<<1|1,l,r,x);
        pushup(p);
    }
}seg;
int calc(int X){
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(mx,a[i].first);
    if(X<mx)return 0;

    tot=0;
    int kk=1,nn=n;
    int c0=0,c1=0;
    if(X==mx){
        for(int i=1;i<=n;i++){
            if(a[i].first==mx){
                if(a[i].second==0){
                    c0++;
                }
                else{
                    c1++;
                }
                nn--;
            }
        }
        for(int i=1;i<=c1;i++)kk=(ll)kk*(n-i+1)%mod;
        for(int i=1;i<=c0;i++)kk=(ll)kk*i%mod;
    }
    if(!nn)return kk;
    for(int i=2;i<=nn;i++)
        if(a[i].first==a[i-1].first&&a[i-1].second==1){
            return 0;
        }
    for(int i=1;i<=nn;i++){
        if(tot&&a[i].first==a[i-1].first&&a[i].second==0){
            c[tot]++;
        }
        else{
            ++tot;
            c[tot]=1;
            if(a[i].second==0){
                int v=a[i].first+i-1;
                if(v<X)return 0;
                nd[tot]=v-X;
            }
            else{
                int v=a[i].first+(n-i);
                if(v>X)return 0;
                nd[tot]=X-v;
            }
        }
    }
    
    vec.clear();
    seg.build(1,1,tot);

    while(vec.size()){
        int x=vec.back();nn--;
        if(c[x]==1){
            vec.pop_back();
        }
        kk=(ll)kk*(c[x]--)%mod;
        if(x<tot){
            seg.change(1,x+1,tot,-1);
        }
    }
    if(nn)return 0;
    return kk;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first;
    for(int i=1;i<=n;i++)cin>>a[i].second;
    sort(a+1,a+1+n);

    set<int>st;
    for(int i=1;i<=n;i++)
        if(a[i].second==0){
            st.insert(a[i].first+i-1);
            break;
        }
    int mx=0;
    for(int i=n;i;i--){
        if(a[i].second==1){
            if(a[i].first==a[n].first){
                mx=max(mx,a[i].first);
            }
            else{
                mx=max(mx,a[i].first+(n-i));
            }
        }
    }
    st.insert(mx);

    memcpy(tmp,a,sizeof tmp);
    int ans=0;
    for(int i:st){
        memcpy(a,tmp,sizeof a);
        Add(ans,calc(i));
    }
    cout<<ans;

    return 0;
}