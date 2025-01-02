// LUOGU_RID: 160423112
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
const int N=1e5;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
long long n,k;
int cnt=0,tot=0;
long long p[MAXN];
void dfs(long long x,int dep){
    if(x==1||dep==k){
        tot++;
        printf("%lld ",x);
        if(tot==N){
            exit(0);
        }
        return ;
    }
    for(int i=1;i<=cnt&&p[i]<=x;i++)
    {
        if(x%p[i]==0){
            dfs(p[i],dep+1);
        }
    }
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i*i<=n;i++)
    {
        if(n%i==0){
            cnt++;
            p[cnt]=i;
            if(i*i!=n){
                cnt++;
                p[cnt]=n/i;
            }
        }
    }
    sort(p+1,p+1+cnt);
    dfs(n,0);
    return 0;
}