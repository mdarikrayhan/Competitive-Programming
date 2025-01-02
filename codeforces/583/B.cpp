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
    int arr[n];
    int poss=-1;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        if (arr[i]==0 and poss==-1)
            poss=i;
    }
    int tmp{0};
    bool dir{true};
    int ans{0};
    while (tmp!=n){
        if (dir) {
            for (int i = 0; i < n; ++i) {
                if (tmp >= arr[i] and arr[i] >= 0)
                    ++tmp, arr[i] = -1;
            }
        }else
            for (int i = 0; i < n; ++i) {
                i=n-i-1;
            if (tmp>=arr[i] and arr[i]>=0) {
                ++tmp, arr[i] = -1;
            }
                i = n - i - 1;
            }

            dir=!dir;
    ++ans;
    }


    cout<<ans-1<<endl;
///==================================================
}
signed main() {MOSTAFAOSMAN()

//    tloop
    solve();

    return 0;
}