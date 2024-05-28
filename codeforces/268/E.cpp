#include "bits/stdc++.h"

using namespace std; 

int main(void) { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n; 
    cin >> n; 
    vector<int>p(n), l(n);
    double ret = 0;  
    for(int i = 0; i < n; i++) { 
        cin >> l[i] >> p[i];
        ret += l[i];  
    }
    vector<int>ord(n); 
    iota(ord.begin(), ord.end(), 0); 
    sort(ord.begin(), ord.end(), [&](int i, int j) { 
        return l[i] * p[i] * (100 - p[j]) > l[j] * p[j] * (100 - p[i]) ; 
    }); 
    double sum = 0; 
    for(auto &i : ord) {
        ret += sum * (1.0 - p[i] / 100.0); 
        sum += l[i] * p[i] / 100.0; 
    }
    cout << fixed << setprecision(10) << ret << '\n'; 
    return 0; 
}