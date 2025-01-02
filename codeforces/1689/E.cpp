#include <bits/stdc++.h>
#define int long long

#define WR WinterRain
using namespace std;
const int WR=5010,mod=1e9+7;
int t;

int n,ans,a[WR];
int bit[WR/50][WR];
bool flag[WR/50];
int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-48;
        ch=getchar();
    }
    return s*w;
}
void tag(int u){
    if(flag[u]) return;
    flag[u]=true;
    for(int i=1;i<=bit[u][0];i++){
        tag(bit[u][i]);
    }
}
bool judge(){
    int s=0;
    memset(flag,false,sizeof(flag));
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++){
        if(!a[i]) return false;
        s|=a[i];
    }
    for(int i=1;i<=n;i++){
        int pre=-1;
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j)){
                if(pre!=-1){
                    bit[pre][0]++,bit[j][0]++;
                    bit[pre][bit[pre][0]]=j,bit[j][bit[j][0]]=pre;
                }
                pre=j;
            }
        }
    }
    for(int i=0;i<=30;i++){
        if(s&(1<<i)){
            tag(i);
            break;
        }
    }
    for(int i=0;i<=30;i++){
        if((s&(1<<i))&&!flag[i]) return false;
    }
    return true;
}
int lowbit(int x){
    return x&(-x);
}
signed main(){
    t=read();
    while(t--){
        n=read();
        bool tag=false;
        for(int i=1;i<=n;i++) a[i]=read();
        ans=0;
        for(int i=1;i<=n;i++){
            if(!a[i]) ans++,a[i]++;
        }
        if(judge()){
            printf("%lld\n",ans);
            for(int i=1;i<=n;i++){
                printf("%lld ",a[i]);
            }
            printf("\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            a[i]--;
            if(judge()){
                printf("%lld\n",ans+1);
                for(int j=1;j<=n;j++){
                    printf("%lld ",a[j]);
                }
                printf("\n");
                tag=true;
                break;
            }
            a[i]++;
        }
        if(tag) continue;
        for(int i=1;i<=n;i++){
            a[i]++;
            if(judge()){
                printf("%lld\n",ans+1);
                for(int j=1;j<=n;j++){
                    printf("%lld ",a[j]);
                }
                printf("\n");
                tag=true;
                break;
            }
            a[i]--;
        }
        if(tag) continue;
        int low=0;
        for(int i=1;i<=n;i++) low=max(low,lowbit(a[i]));
        for(int i=1;i<=n;i++){
            if(lowbit(a[i])==low){
                a[i]--;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(lowbit(a[i])==low){
                a[i]++;
                break;
            }
        }
        printf("%lld\n",ans+2);
        for(int i=1;i<=n;i++){
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}