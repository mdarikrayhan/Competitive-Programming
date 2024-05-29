// LUOGU_RID: 160596238
#include<iostream>
#include<map>
#define int long long
using namespace std;
const int mod=1e9+7;
int l[1001],r[2001];
double p[1001],dp[1001][1001];
int get(int x){
    int res=0;
    if(x==0)return 0;
    for(int i=1;;i*=10){
        int num=x/i;
        if(num<2){
            res+=x-i+1;
            break;
        }
        else if(num>=2){
            res+=i;
            if(num<=9)break;
        }
    }
    return res;
}
signed main(){
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    cin>>k;
    for(int i=1;i<=n;i++){
        int sum=get(r[i])-get(l[i]-1);
        p[i]=sum*1.0/(r[i]-l[i]+1);
    }
    dp[1][0]=(1.0-p[1]),dp[1][1]=p[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]+=dp[i-1][j]*(1-p[i]);
            if(j)dp[i][j]+=dp[i-1][j-1]*p[i];
        }
    }
    int num=n*k/100;
    if((n*k)%100!=0)num++;
    double ans=0;
    for(int i=num;i<=n;i++){
        ans+=dp[n][i];
    }
    printf("%.15lf",ans);
}