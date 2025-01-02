#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

signed main(){
    int a;
    cin >> a;
    while(a--){
        string b;
        cin >> b;
        int l = b.length();
        if(b[l-2]=='p'){
            cout << "FILIPINO"<< endl;
        }else if(b[l-4]=='m' || b[l-4]=='d'){
            cout << "JAPANESE"<<endl;
        }else{
            cout << "KOREAN"<<endl;
        }
    }
    
    return 0;
}
