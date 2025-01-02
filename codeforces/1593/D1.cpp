#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a, a);
}


int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> v(N);
        for(int i = 0; i < N; i++) cin >> v[i];

        vector<int> aux;

        map<int,int> m;

        for(int i = 0; i < N; i++){
            if(m.count(v[i]) == 0){
                aux.push_back(v[i]);
                m[v[i]] = 1;
            }
        }

        if(aux.size() == 1){
            cout << -1 << "\n";
            continue;
        }

        sort(aux.begin(),aux.end());

        vector<int> d;

        for(int i = 1; i < aux.size(); i++){
            //cout << aux[i] - aux[0] << "\n";
            d.push_back(aux[i]-aux[0]);
        }

        int ans = d[0];
        for(int i = 1; i < d.size(); i++){
            ans = gcd(ans,d[i]);
        }

        cout << ans << "\n";
    }
}