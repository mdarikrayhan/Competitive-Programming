#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long y,k,n;
    cin>>y>>k>>n;
    bool b= true;
    long long  x=k;

    while (x<=n){

        if ((x-y)>0) {
            b= false;
            cout << (x - y) << " ";
        }
        x+=k;
    }
    if (b)cout<<-1;
    return 0;
}