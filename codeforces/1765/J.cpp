/**
 *    author:  gary
 *    created: 27.11.2022 22:57:14
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n;
int a[200000+20],b[200000+20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n){
        cin>>a[i];
    }
    rb(i,1,n){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    LL ans=0;
    rb(i,1,n){
        int l=lower_bound(b+1,b+1+n,a[i])-b;
        ans+=1ll*(l-1)*a[i]-1ll*(n-l+1)*a[i];
    }
    rb(i,1,n){
        int l=lower_bound(a+1,a+1+n,b[i]+1)-a;
        ans+=1ll*(l-1)*b[i]-1ll*(n-l+1)*b[i];
    }
    LL temp=0;
    rb(i,1,n) temp+=abs(a[i]-b[i]);
    cout<<ans-temp*(n-1)<<endl;
    return 0;
}