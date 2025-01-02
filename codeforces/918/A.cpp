#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> generateFibonacciSequence(int n) {
    vector<int> fib(n);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

string generateName(int n) {
    vector<int> fibSequence = generateFibonacciSequence(n);
    string name;
    for (int i = 1; i <= n; ++i) {
        if (find(fibSequence.begin(), fibSequence.end(), i) != fibSequence.end() || n==1 || n==2 || n==3) {
            name += 'O';
        }
        else {
            name += 'o';
        }
    }
    return name;
}

int main() {
    int n;
    cin >> n;
    cout << generateName(n) << endl;
    return 0;
}