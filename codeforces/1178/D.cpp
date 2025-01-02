#include <iostream>

using namespace std;

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) return false;
    }
    return true;
}


int main(int argc, char ** argv){
	int n; cin >> n;
    int m = n;
    while (!prime(m)) ++m;
    cout << m << "\n1 " << n << '\n';
    for (int i = 0; i < n-1; ++i) {
        cout << i+1 << ' ' << i+2 << '\n';
    }

    for (int i = 0; i < m-n; ++i) {
        cout << i+1 << ' ' << i+1+n/2 << '\n';
    }
}