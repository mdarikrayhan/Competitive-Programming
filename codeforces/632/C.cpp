#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(string& a, string& b) {
    return ((a+b) < (b+a));
}

int main() {
    //freopen("IO/input.txt", "r", stdin);

    int n; cin >> n;
    vector< string > V(n);

    for(int i = 0; i<n; i++) cin >> V[i];

    sort(V.begin(),V.end(), cmp);

    for(auto& f: V) 
        cout << f;
    
    return 0;
}

