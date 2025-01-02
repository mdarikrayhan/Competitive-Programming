// LUOGU_RID: 158542175
#include<bits/stdc++.h>
#define F(i,j,k) for(auto i=j;i<=(decltype(j))(k);i++)
#define exec(...) [&](){__VA_ARGS__}()
#define view(x) begin(x),end(x)
#define pb push_back
#define lambda [&]
#define x first
#define y second
#define endl '\n'
#define os ostream
using namespace std;
using ll=long long;
template<typename T>void ckmin(T& a,T b){a=min(a,b);}
template<typename T>void ckmax(T& a,T b){a=max(a,b);}

#ifdef DEBUG
template<typename T1,typename T2>os& operator<<(os& out,pair<T1,T2> x);
template<typename T,typename=decltype(T().begin()),typename=enable_if_t<!is_same_v<decay_t<T>,string>>>os& operator<<(os& out,T x){out<<"{";auto n=0u;for(auto i:x) out<<i<<(++n==x.size()?"":",");return out<<"}";}
template<typename ...T>os& operator<<(os& out,tuple<T...> x){return apply(lambda(T... x){out<<"{";auto n=0u;((out<<x<<(++n==sizeof...(T)?"":",")),...);out<<"}";},x),out;}
template<typename T1,typename T2>os& operator<<(os& out,pair<T1,T2> x){return out<<tuple(x);}
#define debug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<" = "<<std::make_tuple(__VA_ARGS__)<<endl
#else
#define debug(...) (void)0
#endif

using Mat=array<array<unsigned long long,(1<<9)+1>,(1<<9)+1>;

int k,n;

Mat operator*(const Mat& a,const Mat& b){
    Mat ans{};
    F(i,0,n-1) F(j,0,n-1) if(a[i][j])
        F(ii,0,n-1) F(jj,0,n-1) if(b[ii][jj])
            ans[(i+ii)&(n-1)][(j+jj)&(n-1)]^=a[i][j]*b[ii][jj];
    return ans;
}

Mat a,b;

int p,q,w,t,ans;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>k,n=1<<k;
    F(i,0,n-1) F(j,0,n-1) cin>>a[i][j];
    cin>>t;
    while(t--) cin>>p>>q,b[p-1][q-1]=1;
    F(_,1,k) a=b*a,b=b*b;
    for(const auto& i:a) for(auto j:i) debug(j),ans+=bool(j);
    cout<<ans<<endl;
    return not "FST";
}
/////////////////////////////////////////////