#include <iostream>
const char nl = '\n';
void solve() {
int x,y,n;
std::cin>>x>>y>>n;
std::cout<<((n-y)/x)*x+y<<'\n';
}
int main() {
int T = 1;
std::cin >> T;
while(T--) {
solve();
}
return 0;
}
