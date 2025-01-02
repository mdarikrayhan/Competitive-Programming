#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int c=0,d=0;
        for(int i=0;i<s.size();i++){
            if((s[i]=='0')) {
               c++;
            } else {
               d++;
            }
        }
        int e=min(c,d);
        if(e%2){
            cout <<"DA" << endl;
        } else {
            cout << "NET" << endl;
        }
    }
    return 0;
}