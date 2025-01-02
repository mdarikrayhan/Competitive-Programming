#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mkpr make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T>
void ckmn(T& a,T b){
    a=min(a,b);
}
template<class T>
void ckmx(T& a,T b){
    a=max(a,b);
}
const int maxn=3005;
int n,k;
int p[maxn];
int dp[maxn][maxn];// fir = i,sec = j 的最小 k 值
int stlg[maxn];
struct Sparse_table{
    int stmx[13][maxn];
    void init(){
        FOR(i,1,n){
            stmx[0][i]=p[i];
        }
        FOR(j,1,12){
            FOR(i,1,n-(1<<j)+1){
                stmx[j][i]=max(stmx[j-1][i],stmx[j-1][i+(1<<j-1)]);
            }
        }
    }
    int qmx(int l,int r){
        int _=stlg[r-l+1];
        return max(stmx[_][l],stmx[_][r-(1<<_)+1]);
    }
}st;
int main()
{
    scanf("%d%d",&n,&k);
    FOR(i,1,n){
        scanf("%d",&p[i]);
    }
    FOR(i,2,n){
        stlg[i]=stlg[i>>1]+1;
    }
    if(n==1){
        puts("1");
        return 0;
    }
    st.init(); 
    memset(dp,0x3f,sizeof dp);
    dp[1][2]=0;
/*
考虑，每次只有 1,2 位置可能被删
dp[i][j] 代表 i 位置为 1，j 位置为 2 的方案数。
转移：
case1：第一个被删除，第二个不删，当且仅当 （2~len 位置存在位置概率 >0，1 位置概率不是 100）
case2：第一个被删，第二个都被删，当且仅当（2~len 存在位置 >0，1 位置 >0）
case3：第一个不删，第二个删，当且仅当（2 ~ len 位置不存在概率 100，1 位置概率 >0）
*/
    FOR(fir,1,n-1){
        FOR(sec,fir+1,n){
       //     printf("now = %d %d qmx = %d\n",fir,sec,st.qmx(sec,n));
            if((p[fir]!=100)&&((st.qmx(sec,n)>0))){
            //    printf("%d %d --> %d %d\n",fir,sec,sec,sec+1);
                ckmn(dp[sec][sec+1],dp[fir][sec]+1);
            }
            if((p[fir]>0)&&(st.qmx(sec,n)>0)){
                ckmn(dp[sec+1][sec+2],dp[fir][sec]+1);
            }
            if((p[fir]>0)&&(st.qmx(sec,n)!=100)){
                ckmn(dp[fir][sec+1],dp[fir][sec]+1);
           //     printf("(%d,%d) -- (%d,%d) qmn(%d,%d) = %d\n",fir,sec,fir,sec+1,sec,n,st.qmn(sec,n));
            }
        }
    }
    int ans=0;
    // 大于 n 的位置，代表这个东西不存在
    FOR(fir,1,n+1){
        FOR(sec,fir+1,n+2){
         //   printf("dp[%d][%d]  =%d\n",fir,sec,dp[fir][sec]);
            if(dp[fir][sec]<=k){
                ans++;
            }
        }
    }
    printf("%d",ans);
	return 0;
}