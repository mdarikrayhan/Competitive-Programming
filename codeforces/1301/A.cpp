#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        vector<string> pals(3);

        for(int i = 0 ; i < 3 ; i++){
            cin >> pals[i];
        }

        for(int i = 0 ; i < pals[0].size() ; i++){
            if(pals[0][i] == pals[2][i]){
                pals[1][i] = pals[2][i];
            }else if(pals[1][i] == pals[2][i]){
                pals[0][i] = pals[2][i];
            }else{
                pals[0][i] = pals[2][i];
                break;
            }
        }
        if(pals[0] == pals[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
