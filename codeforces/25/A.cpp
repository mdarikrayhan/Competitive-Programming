#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    fastio;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            count1++;
        } else {
            count2++;
        }
    }

    if(count2 > count1) {
        int i;
        for(i = 0; i < n; i++) {
            if(arr[i] % 2 == 0) {
                break;
            }
        }
        cout << i + 1 << endl;
    } else {
        int i;
        for(i = 0; i < n; i++) {
            if(arr[i] % 2 != 0) {
                break;
            }
        }
        cout << i + 1 << endl;
    }
    return 0;
}