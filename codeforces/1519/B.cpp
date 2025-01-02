// Source: https://usaco.guide/general/io

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include<map>
#include <cmath>
#include <tuple>
#include <numeric>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int x, y; cin >> x >> y;
        int tot = x-1+(y-1)*x;
        int k; cin >> k;
        if(tot == k){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}
