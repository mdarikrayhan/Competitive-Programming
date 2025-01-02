#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
 
signed main(){
    int a,b,c,d,e,f,sum=0;
    cin >> a >> b >> c >> d >> e >> f;
    if(f>e){
        sum+=(f * ( min(b,min(c,d))));
        d-=min(b,min(c,d));
        sum+=(e*(min(a,d)));
    }else{
        sum+=(e*(min(a,d)));
        d-=(min(a,d));
        sum+=(f*(min(b,min(c,d))));
    }
    cout << sum;
    return 0;
}
