#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int lefts, rights = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') {
            rights++;
        }
        else {
            lefts++;
        }
    }
    
    cout << abs(lefts) + rights + 1 << endl;

}