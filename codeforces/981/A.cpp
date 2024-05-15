#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool ans = true;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[s.size() - i - 1] != s[i]) {
            ans = false;
            break;
        }
    }
    if (ans) {
        s.erase(0, 1);
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[s.size() - i - 1] != s[i]) {
                ans = false;
                break;
            }

        }
        if (ans) {
            cout << 0 << endl;
        }
        else {
            cout << s.size() << endl;
        }
    }
    else {
            cout << s.size() << endl;

        }
    
}


