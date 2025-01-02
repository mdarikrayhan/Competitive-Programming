#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
   ll s,x;cin>>s>>x;
   bool c=true;
   if((s-x)%2!=0){
        c=false;
   }
    ll andd = (s-x)>>1;
    ll ans=0;
    bitset<64> xorr(x),an(andd);
    int cnt=0;
    for(int i=0;i<64;i++){
        if(xorr[i]==1){
            if(an[i]==0){
                cnt++;
            }else{
                c=false;
                break;
            }
        }
    }
    ans+=cnt;
    int req=0;
    if(s==x){
        req=2;
    }
   if(!c){
    cout<<0<<"\n";
   }
    else if(cnt==0){
        cout<<1<<"\n";
    }else{
        cout<<(ll)pow(2,cnt)-req<<"\n";
    }


return 0;
}