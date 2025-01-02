#include <bits/stdc++.h>
#define show(n) cout<<n<<"\n";
#define int long long
using namespace std;
const int m2=998244353;
int binexp(int a,int b,int m=1000000000000000000){
    a%=m;
    int res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        a%=m;
        res%=m;
        b>>=1;
    }
    return res;
}
int calc(int a,int b){
    return (a+b-1)/b;
}
void solve(){
    int n,e;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>e;
        a.push_back(e);
    }
    deque<pair<int,int>> queries;
    int freq=0,temp,ops=0,ans=0,sz;
    pair<int,int> it;
    for(int i=n-1;i>=0;i--){
        e=a[i];
        temp=0;
        // show(lims.size())
        sz=queries.size();
        // show(sz)
        // for(auto it:queries){
        //     show(it.first<<' '<<it.second)
        // }
        // show(e)
        while(sz && queries.front().first<e){
            it=queries.front();
            queries.pop_front();
            if(!queries.empty() && queries.back().first==e/calc(e,it.first)){
                queries.back().second+=it.second;
            }else queries.push_back({e/calc(e,it.first),it.second});
            // show(e<<' '<<it.first<<' '<<calc(e,it.first)<<' '<<it.second)
            ops+=it.second*(calc(e,it.first)-1);
            ops%=m2;
            temp+=it.second;
            sz--;
        }while(!queries.empty() && queries.front().first>=e) queries.pop_front();
        // if(!queries.empty() && queries.back().first)
        queries.push_back({e,freq-temp+1});
        // show(e<<' '<<freq-temp+1)
        freq++;
        ans+=ops;
        ans%=m2;
        // show(queries.size())
        // show(ans<<' '<<ops)
    }
    show(ans)
    return;
}

signed main(){
    int test=1;
    cin>>test;
    while(test--){
        solve();
    }
}