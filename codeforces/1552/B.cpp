#include<bits/stdc++.h>
using namespace std;
using li=long long;
#define maxn 500005
struct ath{
    int r[5];
    bool operator<(const ath&a)const{
        int cnt=0;
        for(int i=0;i<5;i++)cnt+=(r[i]>a.r[i]);
        return cnt>=3;
    }
}th[maxn];

inline void solve(){
    //经过一遍迭代，容易证明除剩下的这个运动员
    int n;cin>>n;
    for(int i=1;i<=n;i++)for(int j=0;j<5;j++)cin>>th[i].r[j];
    int gold=1;
    for(int i=2;i<=n;i++){
        if(th[gold]<th[i])gold=i;
    }
    for(int i=1;i<=n;i++){
        if(th[gold]<th[i]){
            cout<<-1<<'\n';return;
        }
    }
    cout<<gold<<'\n';
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}