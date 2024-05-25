#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void ny(bool ola){
    std::cout<<(ola ? "YES\n" : "NO\n");
}

void solve(){
    int n;
    std::cin>>n;
    
    if(n == 2){
        std::cout<<"1 1 \n 1 2 \n";
        return;
    }else if(n == 3){
        std::cout<<"2 1 \n 2 3 \n 3 1 \n";
        return;
    }else if(n == 4){
        std::cout<<"1 1 \n 1 3 \n 4 3 \n 4 4\n";
        return;
    }
    for(int i=1;i<=n - 2;++i){
        std::cout<<1<<" "<<i<<"\n";
    }
    std::cout<<n<<" "<<n<<"\n";
    std::cout<<n-2<<" "<<n-1<<"\n";
    std::cout<<"\n";
    
}
int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
}
