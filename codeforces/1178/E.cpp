/*
Problem: 1178E
Date: 25-05-2024 03:39 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s, t, rt;
int cnt[3], cnt2[3];

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    int i = 0;
    int j = n - 1;
    while(i <= j) {
        if(j - i >= 3) {
            cnt[0] = cnt[1] = cnt[2] = cnt2[0] = cnt2[1] = cnt2[2] = 0;
            cnt[s[i] - 'a']++;
            cnt[s[i + 1] - 'a']++;
            cnt2[s[j] - 'a']++;
            cnt2[s[j - 1] - 'a']++;
            for(int k = 0; k < 3; k++) {
                if(cnt[k] > 0 && cnt2[k] > 0) {
                    t.push_back('a' + k);
                    rt.push_back('a' + k);
                    break;
                }
            }
            i += 2;
            j -= 2;
        }else {
            t.push_back(s[i]);
            break;
        }
    }
    cout << t;
    for(int i = rt.length() - 1; i >= 0; i--) {
        cout << rt[i];
    }
    cout << endl;
}