#include <bits/stdc++.h>
#define ll long long int
#define lli long long int
using namespace std;


void Kamel(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    if(a == b)
        cout << a + b + c * 2;
    else
        cout << min(a, b) + 1 + min(a, b) + c * 2;
    return 0;
}