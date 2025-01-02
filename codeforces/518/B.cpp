#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> freq_s;
    unordered_map<char, int> freq_t;
    for (char c : s) {
        freq_s[c]++;
    }
    for (char c : t) {
        freq_t[c]++;
    }
    int yay = 0, whoops = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        int match = min(freq_s[c], freq_t[c]);
        yay += match;
        freq_s[c] -= match;
        freq_t[c] -= match;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        int match = min(freq_s[c], freq_t[c]);
        yay += match;
        freq_s[c] -= match;
        freq_t[c] -= match;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        int match = min(freq_s[c], freq_t[tolower(c)]);
        whoops += match;
        freq_s[c] -= match;
        freq_t[tolower(c)] -= match;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        int match = min(freq_s[c], freq_t[toupper(c)]);
        whoops += match;
        freq_s[c] -= match;
        freq_t[toupper(c)] -= match;
    }
    cout << yay << " " << whoops << endl;
    return 0;
}