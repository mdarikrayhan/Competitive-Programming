#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
ll t,n;
cin>>t;
while(t--){
    cin>>n;
   int a=1,x=1,i=1;
    while(n>=a+x){
        x=a+x;
        a=a+2;
        i=i+1;
    }
    int m=n-x+1;
    if(m<=i){
        cout << m << " " << i;
    }
    else{
        cout << i <<" "<< (i - (m - i));
    }
    cout<<"\n";
}
    }

