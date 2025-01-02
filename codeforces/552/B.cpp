#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,digits=0, aux, res;
    cin >>  n;
    aux = n;
    while (aux) {
        aux /= 10;
        digits++;
    }
   
    res = digits*(n+1);
    //cout << res << "\n";

    double sub = 1/10.0;
    //subtrair potencias de 10 com os expoentes de 0 até digits-1
    for (int i=0; i < digits; i++) {
        sub *= 10;
        //cout << sub << "\n";
        res -= sub;
    }

    cout << res << "\n";

    return 0;
}