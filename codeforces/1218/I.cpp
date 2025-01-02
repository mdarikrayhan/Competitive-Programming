#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>
#include <iomanip>
#include <stack>
#include <cmath>
#include <queue>
#include <assert.h>
#include <climits>
#include <functional>
#include <string>
#include <utility>
#include <unordered_set>
#include <numeric>
#include <random>
#include <complex>

using namespace std;



typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef long double ld;
typedef complex<double> C;
typedef vector<double> vd;

int N;
string grid[2000];
string des[2000];
vector<vector<int> > poss;
string B;

int par[8002];
int rk[8002];
int find(int a){
    if(a == par[a]) return a;
    return (par[a] = find(par[a]));
}
bool p = true;
void merge(int a, int b){
    //if(p)cout << a << " " << b << endl;
    a = find(a);
    b = find(b);
    if(a == b) return;
    par[b] = a;
}

int main(){
    iota(par, par+8002, 0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
    }
    for(int i = 0; i < N; i++){
        cin >> des[i];
        for(int e = 0; e < N; e++){
            grid[i][e] = (grid[i][e] != des[i][e]);
        }
    }
    /*
    for(int i = 0; i < N; i++){
        for(int e = 0; e < N; e++) cerr << (int)grid[i][e];
        cerr << endl;
    }*/
    cin >> B;
    for(int i = 0; i < N; i++){
        for(int e = 0; e < N; e++){
            if(grid[i][e] == 0){
                if(B[i] == '0' && B[e] == '0'){
                    ;
                }
                else if(B[i] == '1' && B[e] == '0'){
                    //cout << i << " " << e << endl;
                    merge(e+2000, 8001);
                    merge(e+6000, 8000);
                }
                else if(B[i] == '0' && B[e] == '1'){
                    merge(i, 8001);
                    merge(i+4000, 8000);
                }
                else{
                    merge(i, e+2000);
                    merge(i+4000, e+6000);
                }
            }
            else{
                if(B[i] == '0' && B[e] == '0'){
                    cout << -1 << endl;
                    return 0;
                }
                else if(B[i] == '1' && B[e] == '0'){
                    merge(e+2000, 8000);
                    merge(e+6000, 8001);
                }
                else if(B[i] == '0' && B[e] == '1'){
                    merge(i+0000, 8000);
                    merge(i+4000, 8001);
                }
                else {
                    merge(i, e+6000);
                    merge(i+4000, e+2000);
                }
            }
        }
    }
    p = false;
    for(int i = 0; i < N; i++){
        if(find(i) != find(8000) && find(i) != find(8001)){
            merge(i, 8000);
            merge(i+4000, 8001);
        }
    }
    if(find(8000) == find(8001)){
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    for(int i = 0; i < N; i++){
        if(find(i) == find(i+4000)){
            cout << -1 << endl;
            return 0;
        }
        if(find(i) == find(8000)){
            v.push_back(i);
        }
    }
    for(int i = 2000; i < N+2000; i++){
        if(find(i) == find(i+4000)){
            cout << -1 << endl;
            return 0;
        }
        if(find(i) == find(8000)){
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for(int i : v){
        if(i < 2000){
            printf("row %d\n", i);
        }
        else{
            printf("col %d\n", i-2000);
        }
    }


    return 0;
}
