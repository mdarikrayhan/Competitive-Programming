#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x,y;
    cin>>n>>x>>y;
    int z=n/2;
    if((x==z and y==z) or (x==z and y==z+1) or (x==z+1 and y==z) or (x==z+1 and y==z+1)){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}