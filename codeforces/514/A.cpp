#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s; cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(!i and s[i] == '9') continue;
        int d = s[i] - '0';
        if(d > 4) d = 9 - d;
        s[i] = '0' + d;
    }
    cout << s << endl;
}