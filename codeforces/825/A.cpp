
#include<bits/stdc++.h>

using namespace std;

int main(){

        int n ; cin >> n ;
        string s ; cin >> s ;
        int ones = 0 ;
        int zeros = 0 ;
        for(int i  = 0 ; i < n ; i++){
            if(s[i] == '1')ones++;
            else if (s[i] =='0'){
                cout << ones;
                ones = 0 ;
            }
        }
        cout << ones;
    return 0;
    }
        

