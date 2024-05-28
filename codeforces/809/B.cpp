//
//  main.cpp
//  IntensiveCamp 2 2024
//
//  Created by Ali AlSalman on 17/05/2024.
//

#include "bits/stdc++.h"

using namespace std;

void confirm(int x, int y) {
    cout<<"2 "<<x<<" "<<y<<endl;
    exit(0);
}

bool query(int i, int j) {
    string res;
    cout<<"1 "<<i<<" "<<j<<endl;
    cin>>res;
    return res == "TAK";
}

int binSearch(int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (query(mid, mid + 1)) {
            
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, k;
    cin>>n>>k;
    
    int x = binSearch(1, n), y;
    if (x != n) {
        y = binSearch(x + 1, n);
        if (query(y, x)) confirm(x, y);
    }
    
    y = binSearch(1, x - 1);
    confirm(x, y);
}
