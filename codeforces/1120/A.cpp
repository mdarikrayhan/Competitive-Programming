#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, nw, nb;
    cin >> n >> k >> nw >> nb;
    int a[n];
    for(int i=0; i<n; i++) cin >> i[a];
    vector<int> ck(500001), cb(500001);
    int q, mis=0, h=0, p = -1;
    while(nb--){
        cin >> q;
        if(!cb[q]) mis++;
        cb[q]++;
    }
    for(int j=0; j < nw; j++){
        for(;h - j*k < n+k - k*nw; h++){
            ck[a[h]]++;
            if(ck[a[h]] == cb[a[h]]) mis--;
        }
        if(!mis) p = j*k;
        for(int i = j*k; i < (j+1)*k; i++){
            if(ck[a[i]] == cb[a[i]]) mis++;
            ck[a[i]]--;
        }
    }
    if(p<0){
        cout << -1;
        return 0;
    }
    vector<int> bombs;
    ck.assign(500000, 0);
    int td = n - k*nw;
    for(int i=p; i < p+n+k - k*nw; i++){
        ck[a[i]]++;
        if(ck[a[i]] > cb[a[i]] && td){
            td--;
            bombs.push_back(i+1);
        }
    }
    cout << bombs.size() << '\n';
    for(int bomb : bombs) cout << bomb << ' ';
    return 0;
}
