#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
int n,m,x,y;
pii a[100010],b[100010];
vector<pii> aws;
void solve(){
    cin>>n>>m>>x>>y;
    rep(i,1,n){
        cin>>a[i].first;
        a[i].second=i;
    }
    rep(i,1,m){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int l=1;
    rep(i,1,n){
        for(;l<=m;){
            if(a[i].first+y<b[l].first){
                break;
            }
            else if(a[i].first-x>b[l].first){
                l++;
            }
            else{
                aws.push_back({a[i].second,b[l].second});
                l++;
                break;
            }

        }

    }
    cout<<aws.size()<<endl;
    for(int i=0;i<aws.size();i++){
        cout<<aws[i].first<<" "<<aws[i].second<<endl;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
