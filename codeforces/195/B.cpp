#include <bits/stdc++.h>
#define MOSTAFAOSMAN() ios_base::sync_with_stdio(false);cout.tie(NULL),cin.tie(NULL);
#define ll long long
#define ld long double
#define outCondtion(a) cout<<((a)?"YES":"NO")<<"\n";
#define tloop int t;cin>>t;cin.ignore();while(t--)
#define endl "\n"
#define lcm(a,b) (((a)/gcd(a,b))*(b))
#define inf 0x3f3f3f3f3f3f3f3fLL
#define mSet(arr,value) memset((arr),(value),(sizeof (arr)))
#define int long long
using namespace std;

void solve(){
///==================================================
    int n,m;cin>>n>>m;
   priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    int dec{0};
    for (int i = 1; i <= m; ++i) {
        int tmp=abs(((m+1)/2)-i);
        if (m%2==0 and i==(m/2)+1) {
            tmp = 0, ++dec;
            pq.push({0, tmp, i});
        }else
            pq.push({0, tmp - dec, i});
    }
    while (n--){
        auto tp=pq.top();pq.pop();
        ++get<0>(tp);
        pq.push(tp);
        cout<<get<2>(tp)<<endl;
    }

///==================================================
}
signed main() {MOSTAFAOSMAN()

//    tloop
    solve();

    return 0;
}