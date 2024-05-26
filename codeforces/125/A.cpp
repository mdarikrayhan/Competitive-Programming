#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
 
signed main(){
    int a;
    cin >> a;
    if(a%3==1){
        a--;
    }else if(a%3==2){
        a++;
    }
    cout << a/36 << " ";
    cout << (a-((a/36)*36))/3;
    return 0;
}