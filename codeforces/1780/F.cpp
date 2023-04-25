#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n=300000;
int num[n+10];
ll sum[n+10];
int main(){
    int m;scanf("%d",&m);
    while(m--){
        int x;scanf("%d",&x);
        num[x]++;
    }
    for(int i=1;i<=n;i++)
    num[i]+=num[i-1];
    for(int i=n;i;i--){
        ll now=0,cnt=0;
        for(int j=i;j<=n;j+=i)if(num[j]-num[j-1]){
            sum[i]+=cnt*num[j]-cnt-now;
            now+=num[j];cnt++;
        }
        for(int j=2*i;j<=n;j+=i)sum[i]-=sum[j];
    }printf("%lld",sum[1]);
}