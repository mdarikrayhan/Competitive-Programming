#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> v(N);
        for(int i = 0; i < N; i++) cin >> v[i];

        if(N%2==0){
            cout << "YES\n";
        }else{
            bool ind = true;
            for(int i = 1; i < N; i++){
                if(v[i] <= v[i-1]){
                    ind = false;
                }
            }
            if(ind)cout << "NO\n";
            else cout << "YES\n";
        }
    }
}