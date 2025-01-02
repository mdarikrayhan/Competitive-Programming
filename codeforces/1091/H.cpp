// LUOGU_RID: 159739406
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5,M=1000;
int a[N+2];
bitset<N> pr,s[M+2];
struct Prime{
    int flag[N+2],p[N+2];
    int cnt[N+2];
    int tot;
    Prime(){
        tot=0;
        memset(flag,0,sizeof flag);
        for(int i=2;i<=N;i++){
            if(!flag[i]){
                p[++tot]=i;
                cnt[i]=1;
            }
            for(int j=1;j<=tot&&i*p[j]<=N;j++){
                flag[i*p[j]]=1;
                cnt[i*p[j]]=cnt[i]+1;
                if(i%p[j]==0){
                    break;
                }
            }
        }
        for(int i=2;i<=N;i++){
            if(cnt[i]<=2){
                pr[i]=1;
            }
        }
    }
};
struct solution{
    int sg[N+2];
    int n;
    solution(int n,int f):n(n){
        pr[f]=0;
    }
    void prework(){
        for(int i=0;i<=N;i++){
            sg[i]=-1;
            for(int j=0;j<=M;j++) if(!s[j][i]){
                sg[i]=j;
                break;
            }
            if(sg[i]==-1){
                cout<<"No\n";
                return;
            }
            s[sg[i]]|=pr<<i;
        }
    }
    int solve(){
        int ans=0;
        for(int i=1;i<=2*n;i++){
            ans^=sg[a[i]];
        }
        return ans;
    }
};
int main(){
    // freopen("data.in","r",stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n,f;
    cin>>n>>f;
    for(int i=1;i<=n;i++){
        int b,w,r;
        cin>>b>>w>>r;
        a[i*2-1]=w-b-1;
        a[i*2]=r-w-1;
    }
    Prime Pr;
    solution sol(n,f);
    sol.prework();
    if(sol.solve()){
        cout<<"Alice\nBob\n";
    }
    else{
        cout<<"Bob\nAlice\n";
    }
    return 0;
}