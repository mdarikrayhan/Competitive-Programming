#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    string result = "";
    cin >> word;

    for (char ch : word) {
        ch = toupper(ch);
        if (ch != 'A' && ch != 'O' && ch != 'Y' && ch != 'E' && ch != 'U' && ch != 'I') {
            ch = tolower(ch);
            result += '.';
            result += ch;
        }
    }

    cout << result << endl;

    return 0;
}
