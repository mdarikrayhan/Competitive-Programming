#include <bits/stdc++.h>
using namespace std;

void formats(string &s) {
    int level = 0;
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '<') {
            bool isClosingTag = (i + 1 < s.length() && s[i + 1] == '/');
            
            if (isClosingTag) {
                level--;  
            }
            for (int j = 0; j < 2 * level; ++j) {
                cout << ' ';
            }
            
            while (i < s.length() && s[i] != '>') {
                cout << s[i++];
            }
            cout << '>' << endl;
            i++;  
            
            if (!isClosingTag) {
                level++;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;  
    formats(s);
    return 0;
}