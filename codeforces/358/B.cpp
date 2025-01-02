#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    string s;
    cin >> s;
    

    string hrt = "<3";
    for (const string& word : words) {
        hrt += word + "<3";
    }
    
    size_t j = 0;
    for (size_t i = 0; i < s.size() && j < hrt.size(); i++) {
        if (s[i] == hrt[j]) {
            j++;
        }
    }
    
    if (j == hrt.size()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
