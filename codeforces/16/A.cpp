#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m;
    string s;
    char check = '_';
    cin >> m >> n;
    while (m--) {
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0] != s[n - 1] || s[0] == check) {
            cout << "NO";
            return 0;
        }
        check = s[0];
    }
    cout << "YES";
}