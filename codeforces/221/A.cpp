#include <iostream>
#include <cstring>

using namespace std;
#define repito(n) for (int i = 0;i < n; i++)

int main() {
    int n;
    cin >> n;
    cout << n << ' ';
    repito(n-1){
        cout << i+1 << ' ';
    }
    return 0;
}