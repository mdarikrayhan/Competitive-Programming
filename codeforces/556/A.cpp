#include<bits/stdc++.h>
using i64 = long long;

const int N = 100010;



void solve() {
    
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int z = 0 , o = 0 ;
    for(int i = 0 ; i < n; i ++){
        if(s[i] == '0'){
            z++;
        }else{
            o ++;
        }
    }

    if(z && o){
        int k = std::min(z , o);
        std::cout << n - 2 * k << '\n';
    }else{
        std::cout << n << '\n';
    }

}

int main(){
    std::ios:: sync_with_stdio(false);std::cin.tie(nullptr); 

    int T = 1;
    while(T--) 
        solve();

    return 0;
}
