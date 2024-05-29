#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define cir(i,a,b) for(int i=a;i<b;++i)
using namespace std;
static constexpr auto maxw=(int)(1e5+7);
static constexpr auto _inf=(int)(1e9+7);
struct qry{int l,r,k,id;};
struct upd{int p,w;};
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(auto&i:a) cin>>i;
    vector<qry> qx;
    vector<upd> ux(q,{-1,-1});
    cir(i,0,q){
        int op;cin>>op;
        if(op==1){
            int l,r,k;cin>>l>>r>>k;
            qx.push_back({l-1,r-1,k,i});
        }else{
            int p,w;cin>>p>>w;
            ux[i]={p-1,w};
        }
    }
    const auto sqr=(int)(ceil(q/pow(q,1.0l/4)));
    sort(qx.begin(),qx.end(),[&](qry&a,qry&b){
        return a.l/sqr==b.l/sqr?(
            a.r/sqr==b.r/sqr?a.id<b.id:a.r<b.r
        ):a.l<b.l;
    });
    map<int,int> ans;
    unordered_multiset<int> aprs;
    const auto sqrx=(int)(sqrt(n));
    vector<int> cnt(maxw),cnti(maxw);
    auto l=0,r=-1,tl=-1;
    auto ins=[&](int p){
        if(cnt[a[p]]) --cnti[cnt[a[p]]];
        ++cnti[++cnt[a[p]]];
        if(cnt[a[p]]-1==sqrx) aprs.insert(a[p]);
    };
    auto rmv=[&](int p){
        --cnti[cnt[a[p]]];
        if(--cnt[a[p]]) ++cnti[cnt[a[p]]];
        if(cnt[a[p]]==sqrx) aprs.extract(a[p]);
    };
    auto updp=[&](int x){
        if(ux[x].p<0) return;
        const auto p=ux[x].p;
        if(l-1<p&&p-1<r) rmv(p);
        swap(a[p],ux[x].w);
        if(l-1<p&&p-1<r) ins(p);
    };
    for(auto&[ql,qr,k,id]:qx){
        while(r<qr) ins(++r);
        while(l>ql) ins(--l);
        while(l<ql) rmv(l++);
        while(r>qr) rmv(r--);
        while(tl<id) updp(++tl);
        while(tl>id) updp(tl--);
        vector<pair<int,int>> qi;
        unordered_set<int> st;
        for(auto&i:aprs) st.insert(cnt[i]);
        for(auto&x:st) qi.push_back({x,cnti[x]});
        cir(i,0,sqrx+1) if(cnti[i]) qi.push_back({i,cnti[i]});
        sort(qi.begin(),qi.end());
        auto cntw=0,p=-1,ansi=_inf;
        cir(i,0,(int)(qi.size())){
            if(i) cntw-=qi[i-1].second;
            while(p+1<(int)(qi.size())&&cntw<k){
                cntw+=qi[++p].second;
            }
            if(cntw>k-1) ansi=min(ansi,qi[p].first-qi[i].first);
        }
        ans[id]=(ansi==_inf?-1:ansi);
    }
    for(auto&[a,b]:ans) cout<<b<<'\n';
    return 0;
}
