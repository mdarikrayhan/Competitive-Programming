#include<bits/stdc++.h>
using namespace std;
#define muslimfat ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() {
    muslimfat
    long long n;
    cin >> n;
    string s = "";
    for(int i = 0; i < 1000; i++) {
        s += to_string(i);
    }
    cout << s[n];
}
