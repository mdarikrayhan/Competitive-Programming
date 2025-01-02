// LUOGU_RID: 160153726
#include<bits/stdc++.h>
#define for1(i,a,b) for( int i=(a);i<=(b);i++)
#define for2(i,a,b) for( int i=(a);i<(b);i++)
#define for3(i,a,b) for( int i=(a);i>=(b);i--)
#define for4(i,a,b) for( int i=(a);i>(b);i--)
#define puba push_back
#define mem(a,b) memset((a),(b),sizof((a)))
#define int long long
using namespace std;
const int mod=51123987;
int n,p[4000015],mr,mid,ans,sum1[4000015],sum2[4000015],len;
char a[4000015];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for1(i,1,n){
        cin>>a[i*2];
        a[i*2-1]='#';
    }
    a[n*2+1]='#';
    a[0]='@';
    n=n*2+1;
    int summ=0;
    for1(i,1,n){
        int j=mid*2-i;
        if(i<mr) p[i]=min(mr-i,p[j]);
        else p[i]=1;
        while(a[i-p[i]]==a[i+p[i]]) p[i]++;
        if(i+p[i]>mr){
            mr=i+p[i];
            mid=i;
        }
        sum1[i-p[i]+1]++;
        sum1[i+1]--;//开头
        sum2[i]++;//结尾
        sum2[i+p[i]]--;
    }
    for1(i,1,n) summ=(summ+p[i]/2)%mod;
    ans=(summ*(summ-1)/2)%mod;
    //cout<<ans<<"\n";
    for1(i,1,n){
        sum1[i]=(sum1[i]+sum1[i-1])%mod;
        sum2[i]=(sum2[i]+sum2[i-1])%mod;
    }for(int i=2;i<=n;i+=2){
        sum2[i]=(sum2[i]+sum2[i-2])%mod;
    }
    for(int i=4;i<=n;i+=2){
        ans=((ans-sum2[i-2]*sum1[i])%mod+mod)%mod;
    }
    cout<<ans;
    
    return 0;
}