#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> v(N);

        for(int i = 0; i < N; i++) cin >> v[i];

        map<int,vector<int>> m;

        for(int i = 0; i < N; i++){
            if(m.count(v[i]) == 0){
                vector<int> aux = {i};
                m[v[i]] = aux;
            }else{
                m[v[i]].push_back(i);
            }
        }

        if(m.size() == N){
            cout << -1 << "\n";
            continue;
        }

        int ans = 0;

        for(auto x : m){
            for(int i = 0; i < x.second.size()-1; i++){
                ans = max(ans,x.second[i]+N-x.second[i+1]);
            }
        }

        cout << ans << "\n";

    }
}