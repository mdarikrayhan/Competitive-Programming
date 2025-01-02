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
    int n;cin>>n;
    if (n==1){
        outCondtion(true)
        return;
    }
    vector<set<int>>vc(n);
    for (int i = 0; i < n; ++i) {
        int m;cin>>m;
        for (int j = 0; j <m ; ++j) {
            int tmp;cin>>tmp;
            vc.at(i).insert(tmp);
        }
    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <n ; ++j) {
            if (i==j)continue;
            if (vc.at(i)==vc.at(j)){
                outCondtion(false);
                goto label;
            }else{
                bool tmp{false};
                if (vc.at(i).size()<vc.at(j).size()){
                    continue;
                }

                for (auto& x:vc.at(j)) {
                    if (not vc.at(i).count(x)){
                        tmp=true;
                        break;
                    }
                }

                if (!tmp){
                    outCondtion(false);
                    goto label;
                }
            }
        }
        outCondtion(true);
        label:
    }

///==================================================
}
signed main() {MOSTAFAOSMAN()

//    tloop
    solve();

    return 0;
}