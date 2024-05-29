#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;


#define F		        first
#define S		        second
#define pb		        push_back
#define endl            '\n'
#define Mp              make_pair
#define all(x)          x.begin(), x.end()
#define debug(x)        cerr << #x << " = " << x << endl;
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io         freopen("tests.in" , "r" , stdin) ;

ll mod = 1e9+7 ;

const int N = 2e5+23;
const int INF=1e9+23;

struct Node{
    int Mn[2], sum;
    Node(){
        Mn[0]=Mn[1]=INF;
        sum=0;
    }
}seg[4*N], emt;
int lpz[4*N];
int n, q;
int a[N];

Node Merge(Node a, Node b, int l, int mid, int r){
    if(mid<=l) return b;
    if(mid>=r) return a;
    Node c;
    if((mid-l)&1){
        c.Mn[1]=min(a.Mn[1], b.Mn[0]+a.sum);
        c.Mn[0]=min(a.Mn[0], b.Mn[1]-a.sum);
    }
    else {
        c.Mn[1]=min(a.Mn[1], b.Mn[1]-a.sum);
        c.Mn[0]=min(a.Mn[0], b.Mn[0]+a.sum);
    }
    c.sum=b.sum;
    if((r-mid)&1) c.sum-=a.sum;
    else c.sum+=a.sum;
    return c;
}

void Shift(int l, int r, int ind){
    if(r-l==1) return;
    if(!lpz[ind]) return;
    int mid=(r+l)>>1;
    seg[2*ind+1].Mn[1]+= lpz[ind];
    lpz[2*ind+1]+=lpz[ind];
    if((mid-l)&1) seg[2*ind+1].sum+=lpz[ind];

    seg[2*ind+2].Mn[1]+= lpz[ind];
    lpz[2*ind+2]+=lpz[ind];
    if((r-mid)&1) seg[2*ind+2].sum+=lpz[ind];

    lpz[ind]=0;
}

void build(int l=0, int r=n, int ind=0){
    if(r-l==1){
        seg[ind].sum=seg[ind].Mn[1]=a[l];
        return;
    }
    int mid=(r+l)>>1;
    build(l, mid, 2*ind+1); build(mid, r, 2*ind+2);
    seg[ind]=Merge(seg[2*ind+1], seg[2*ind+2], l, mid, r);
}

void upd(int lx, int rx, int x, int l=0, int r=n, int ind=0){
    Shift(l, r, ind);
    if(lx>=r || rx<=l) return;
    if(lx<=l && rx>=r){
        seg[ind].Mn[1]+=x;
        lpz[ind]+=x;
        if((r-l)&1) seg[ind].sum+=x;
        return;
    }
    int mid=(r+l)>>1;
    upd(lx, rx, x, l, mid, 2*ind+1); upd(lx, rx, x, mid, r, 2*ind+2);
    seg[ind]=Merge(seg[2*ind+1], seg[2*ind+2], l, mid, r);
}

Node get(int lx, int rx, int l=0, int r=n, int ind=0){
    Shift(l, r, ind);
    if(lx>=r || rx<=l) return emt;
    if(lx<=l && rx>=r) return seg[ind];
    int mid=(r+l)>>1;
    Node r1=get(lx, rx, l, mid, 2*ind+1);
    Node r2=get(lx, rx, mid, r, 2*ind+2);
    return Merge(r1, r2, max(l, lx), mid, min(rx, r));
}

int main()
{
    fast_io
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    build();
    cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t==1){
            int l, r, x; cin>>l>>r>>x;
            r++;
            upd(l, r, x);
        }
        else{
            int l, r; cin>>l>>r; r++;
            Node temp=get(l, r);
            if(temp.Mn[1]>=1 && temp.Mn[0]>=0 && temp.sum==((r-l)&1)) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }

}
