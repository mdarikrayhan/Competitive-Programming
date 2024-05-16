#include <bits/stdc++.h>
using namespace  std;
int main(){
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        if(n&1)
            cout<<-1<<endl;
        else {
            n = n/2;
            cout<<n<<" "<<1<<endl;
        }
    }

    return 0;
}
