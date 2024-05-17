#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;
    int n,m;
    cin>>n>>c>>m;
    n%=12;
    double b=m*6;
    cout<<double(n*30+m*0.5)<<' '<<b;

    return 0;
}