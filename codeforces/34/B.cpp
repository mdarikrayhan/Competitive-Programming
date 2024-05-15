#include<bits/stdc++.h>
using i64 = long long;

const int N = 100010;



void solve() {
    
    int n , m;
    std::cin >> n >> m;
    std::vector<int> a(n) , b;
    for(int i = 0 ; i < n ; i ++){
        std::cin >> a[i];
        if(a[i] < 0){
            b.push_back(a[i]);
        }
    }


    std::sort(b.begin() , b.end() );


    int t = 0;
    for(int i = 0 ; i < m && i < b.size()  ; i ++){
        t += - b[i];
    }

    std::cout << t << '\n';


}

int main(){
    std::ios:: sync_with_stdio(false);std::cin.tie(nullptr); 

    int T = 1;
    while(T--) 
        solve();

    return 0;
}
