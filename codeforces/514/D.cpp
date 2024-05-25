#include <iostream>
#include <set>
#include <vector>
using namespace std;

int mat[100005][7];
vector < multiset < int > > v;
int n, m, k;
int sol[7];
int res[7];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    v.resize(m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int i = 0;
    int j = -1;
    int sum = 0;
    int siz = 0;
    int r = INT_MAX;

    while(j < n && i < n){
        if(sum <= k){
            j++;
            if(j >= n) break;
            sum = 0;

            for(int t = 0; t < m; t++){
                v[t].insert(mat[j][t]);
                sol[t] = *prev(end(v[t]));
                sum += *prev(end(v[t]));
            }
            
        }
        else{
            sum = 0;
            for(int t = 0; t < m; t++){
                v[t].erase(mat[i][t]);
                if(v[t].size() > 0){
                    sum += *prev(end(v[t]));
                    sol[t] = *prev(end(v[t]));
                }
                else sol[t] = 0;
            }
            i++;
        }
        
        // cout << i << ":" << j << "\n";
        // for(int i = 0; i < m; i++){
        //     cout << sol[i] << " ";
        // } cout << "\n";

        if(sum <= k && siz < j - i + 1){
            r = sum;
            siz = j - i + 1;
            for(int i = 0; i < m; i++){
                res[i] = sol[i];
            }
        }
    }

    for(int i = 0; i < m; i++){
        cout << res[i] << " ";
    } cout << "\n";

    return 0;
}


// 5 2 4
// 4 0
// 1 2
// 2 1
// 0 2
// 1 3


// 3 2 4
// 1 2
// 1 3
// 2 2
