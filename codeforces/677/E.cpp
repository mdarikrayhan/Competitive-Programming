#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ldb long double
#define pii pair<int,int>
#define mkp make_pair
#define mkt make_tuple
#define fr first
#define se second
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue
#define all(_box) _box.begin(),_box.end()
#define ppc __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define lbd lower_bound
#define ubd upper_bound
#define deb(x) cerr<<#x<<'='<<(x)<<' '
using namespace std;
const int N=1004;
const int L=N*4;
const int mod=1e9+7;
int n;
int pw2[L],pw3[L];
int a[N][N];
struct Num{
    int zero,c2,c3;

    Num()=default;
    Num(int zero,int c2,int c3):
        zero(zero),c2(c2),c3(c3){}
    Num(int x){
        zero=c2=c3=0;
        if(x==0)zero=1;
        else if(x==2)c2=1;
        else if(x==3)c3=1;
    }
    int val(){
        if(zero)return 0;
        return 1ll*pw2[c2]*pw3[c3]%mod;
    }
    friend Num operator*(const Num &u,const Num &v){
        return {u.zero+v.zero,u.c2+v.c2,u.c3+v.c3};
    }
    friend Num operator/(const Num &u,const Num &v){
        return {u.zero-v.zero,u.c2-v.c2,u.c3-v.c3};
    }
    friend bool operator>(const Num &u,const Num &v){
        if(u.zero)return 0;
        if(v.zero)return 1;
        return log(2)*(u.c2-v.c2)+log(3)*(u.c3-v.c3)>0;
    }
};
Num ans(0);
Num s1[N][N],s2[N][N];//行，列
Num s3[N][N],s4[N][N];//主对角，次对角

void init(){
    pw2[0]=pw3[0]=1;
    for(int i=1;i<L;i++){
        pw2[i]=2ll*pw2[i-1]%mod;
        pw3[i]=3ll*pw3[i-1]%mod;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            a[i][j]=c&15;
            s1[i][j]=s1[i][j-1]*Num(a[i][j]);
            s2[i][j]=s2[i-1][j]*Num(a[i][j]);
            s3[i][j]=s3[i-1][j-1]*Num(a[i][j]);
            s4[i][j]=s4[i-1][j+1]*Num(a[i][j]);
        }
}
void chkmax(Num &u,const Num &v){
    if(v>u)u=v;
}
void work1(int x,int y){
    int l=0,r=n,res;
    while(l<=r){
        int d=(l+r)>>1;
        auto check=[&]()->bool {
            if(x-d<=0||x+d>n||y-d<=0||y+d>n)return 0;
            if((s1[x][y+d]/s1[x][y-d-1]).zero)return 0;
            if((s2[x+d][y]/s2[x-d-1][y]).zero)return 0;
            return 1;
        };
        if(check())res=d,l=d+1;
        else r=d-1;
    }
    chkmax(ans,
        (s1[x][y+res]/s1[x][y-res-1])*
        (s2[x+res][y]/s2[x-res-1][y])/
        Num(a[x][y])
    );
}
void work2(int x,int y){
    int l=0,r=n,res;
    while(l<=r){
        int d=(l+r)>>1;
        auto check=[&]()->bool {
            if(x-d<=0||x+d>n||y-d<=0||y+d>n)return 0;
            if((s3[x+d][y+d]/s3[x-d-1][y-d-1]).zero)return 0;
            if((s4[x+d][y-d]/s4[x-d-1][y+d+1]).zero)return 0;
            return 1;
        };
        if(check())res=d,l=d+1;
        else r=d-1;
    }
    chkmax(ans,
        (s3[x+res][y+res]/s3[x-res-1][y-res-1])*
        (s4[x+res][y-res]/s4[x-res-1][y+res+1])/
        Num(a[x][y])
    );
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    init();
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)if(a[i][j]){
            work1(i,j),work2(i,j);
        }
    cout<<ans.val();
}