#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    while(T--){
        int N,K; 
        cin >> N >> K;

        int val = 1, pas = 0;

        while(val < N){
            if(val <= K){
                val *= 2;
            }else{
                break;
                //val += K;
            }
            pas++;
        }

        if(val < N){
            pas += 1 + ((N-val-1)/K);
        }

        cout << pas << "\n";
    }
}