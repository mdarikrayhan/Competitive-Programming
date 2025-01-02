// -o|o-
// -----

#include <bits/stdc++.h>
#define all(x)      (x).begin(),(x).end()
#define forr(i,a)     for(auto&i:a)
#define Sort(x)      sort(all((x)))
#define Binary(a,b)  binary_search(all((a)),b)
#define Reverse(a)   reverse(all((a)))
#define pb           push_back
#define sep          " "
#define s            second
#define f            first
#define endl         '\n'
#define FileIO       freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FastIO       	ios::sync_with_stdio(false);cin.tie(nullptr);
#define in           insert
#define for0(n)      for(int i=0;i<n;i++)
#define for1(n)       for(int i=1;i<=n;i++)
using namespace std;
typedef long long        ll;
typedef long double      ld;
const int Mod=1e9+7;
ll pw(ll a,ll b,ll md=Mod){ll res=1;while(b){if(b&1){res=(a*res)%Mod;}a=(a*a)%Mod;b>>=1;}return(res);}
const int Max=2e6+5;
int c[Max],cc[Max],a[Max],b[Max],n,m;
bool chek(int x){
    for0(33)cc[i]=c[i];
    for(int i=x;i>=1;i--){
        if(cc[b[i]])cc[b[i]]--;
        else{
            for(int j=b[i];j<=32;j++){
                if(cc[j]){
                    cc[j]--;
                    break;
                }
                cc[j]=1;
                if(j==32)return 0;
            }
        }
    }
    return 1;
}
void Main(){
    cin>>n>>m;
    for1(n){
        cin>>a[i];
        for(int j=0;(1<<j)<=a[i];j++){
            if(a[i]&(1<<j)){
                c[j]++;
                a[i]-=(1<<j);
            }
        }
    }
    for1(m)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int l=0,r=m+1;
    while(r-l>1){
        int mid=(l+r)/2;
        (chek(mid)?l=mid:r=mid);
    }
    cout<<l;
}
int main() {
    FastIO
    int Test;
    //cin>>Test;
    Test=1;
    while(Test--){
        Main();
    }
    return 0;
}
