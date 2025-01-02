#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=8e5+7;
int a[N],tot;
ll b[N],c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum=0,inf=1e9;
    for(int i=1;i<=n;i++){
        int opt;
        cin>>a[i];
        if(a[i]!=3)cin>>b[i];
        if(a[i]==2)sum+=b[i];
        sum=min(sum,inf);
        if(a[i]==3)b[i]=sum,sum=2*sum;//double;
        sum=min(sum,inf);
    }
    sum=0;ll res=1,ans=0;
    for(int i=n;i>=1;i--){//倒序处理后缀存活,每个后缀伤害可由预处理的前缀得到
        if(a[i]==2){
            sum+=b[i];
        }else if(a[i]==3){
            if(b[i]==inf)continue;
            if(b[i]==0){//特判
                res=(res*2)%mod;
                continue;
            }
            c[++tot]=b[i];
        }else{
            ll cnt=0,now=b[i]-sum;
            if(now<=0)continue;
            for(int j=1;j<=tot;j++){//tot很小,因为存在伤害不断倍增logx
                if(now>c[j]){//倒着计算,即截止伤害,找分界线
                    cnt=(cnt+(1ll<<(tot-j)))%mod;//位运算优先级很低,尽量括起来
                    now-=c[j];
                }
            }
            cnt=(cnt+1)%mod;//补上末尾
            ans=(ans+cnt*res)%mod;
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}