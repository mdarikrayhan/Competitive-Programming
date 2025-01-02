#include<bits/stdc++.h>
using namespace std;
#define muslimfat ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() {
    muslimfat
    long long n;
    string s;
    cin >> n >> s;
    vector <long long> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'W') {
            continue;
        }
        int j = i;
        while (j < n && s[j] == 'B') {
            j++;
        }
        v.push_back(j - i);
        i = j - 1;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

