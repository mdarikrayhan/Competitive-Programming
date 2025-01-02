#include <bits/stdc++.h>             //                          الْحَمْدُ لِلَّهِ وَحْدَهُ
using namespace std;                 //           وَالصَّلاَةُ وَالسَّلاَمُ عَلَى مَنْ لاَ نَبِيَّ بَعْدَهُ
/// في سبيل الله
int32_t main(){
    cin.tie(0)->sync_with_stdio(false);

    int n, x; cin >> n >> x;
    vector<int> ar(x+1, 0);
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        ar[k]++;
    }
    for(int i = 1; i < x; i++){
        if(ar[i] % (i + 1) != 0) {cout << "No\n"; return 0;}
        ar[i+1] += ar[i] / (i + 1);
    }
    cout << "Yes\n";
}