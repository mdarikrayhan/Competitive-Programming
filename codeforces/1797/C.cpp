#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int tc; cin>>tc;
    while(tc--){
        int n, m, a, b, c, x, y; cin>>n>>m;
        cout<<"? "<<1<<" "<<1<<endl; cin>>a;
        cout<<"? "<<1<<" "<<min(a+1, m)<<endl; cin>>b;
        cout<<"? "<<min(a+1, n)<<" "<<1<<endl; cin>>c;
        x = b+1; y = c+1;
        cout<<"! "<<x<<" "<<y<<endl;
    }
}