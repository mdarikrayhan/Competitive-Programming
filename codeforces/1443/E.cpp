#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;

ll sum=0;
ll n,q;
ll a[16],P[16],fac[16];
bool vis[16];

void get(ll sum){
    /*
  ll res=0;
  for(ll i=1;i<n;i++){
    res=(res+a[i])*(n-i);
  }*/
  for(int i=1;i<=15;i++){
    a[i]=sum/fac[15-i];
    sum%=fac[15-i];
  }
  memset(vis,0,sizeof vis);
  for(int i=1;i<=15;i++){
    int cnt=0;
    for(int j=1;j<=15;j++){
        if(!vis[j])cnt++;
        if(cnt==a[i]+1){
            P[i]=j;
            vis[j]=1;
            break;
        }
    }
  }
}


void slove(){

  cin>>n>>q;
  fac[0]=1;
  for(ll i=1;i<=15;i++){
    fac[i]=fac[i-1]*i;
  }
  while(q--){
    int opt;
    cin>>opt;
    if(opt==1){
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        get(sum);
        if(r>n-15){
            if(l>n-15){
                for(int i=l-n+15;i<=r-n+15;i++)ans+=P[i];
                ans+=(r-l+1)*(n-15);
            }
            else{
                ans+=(l+n-15)*(n-14-l)/2;
                for(int i=1;i<=r-n+15;i++)ans+=P[i];
                ans+=(r-n+15)*(n-15);
            }
        }
        else{
            ans=(l+r)*(r-l+1)/2;
        }
        cout<<ans<<'\n';
    }
    if(opt==2){
        ll x;
        cin>>x;
        sum+=x;
    }
  }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        slove();

    return 0;
}
