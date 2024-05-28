#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], pos[N][2];
ll suma[N], sumb[N];
bool has[N];

void work(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        sumb[i] = sumb[i - 1] + b[i];
    }

    bool isSwap = false;
    if(suma[n] > sumb[n]){
        isSwap = true;
        for(int i = 1; i <= n; i++){
            swap(a[i], b[i]);
            swap(suma[i], sumb[i]);
        }
    }

    int j = 0, l1, l2, r1, r2;
    for(int i = 0; i <= n; i++){
        while(suma[i] >= sumb[j] && j <= n) j++;
        j--;

        if(has[suma[i] - sumb[j]]){
            l1 = pos[suma[i] - sumb[j]][0] + 1;
            r1 = i;
            l2 = pos[suma[i] - sumb[j]][1] + 1;
            r2 = j;
            break;
        }

        has[suma[i] - sumb[j]] = true;
        pos[suma[i] - sumb[j]][0] = i;
        pos[suma[i] - sumb[j]][1] = j;
    }

    if(isSwap){
        swap(l1, l2);
        swap(r1, r2);
    }

    cout << r1 - l1 + 1 << '\n';
    for(int i = l1; i <= r1; i++) cout << i << " \n"[i == r1];
    cout << r2 - l2 + 1 << '\n';
    for(int i = l2; i <= r2; i++) cout << i << " \n"[i == r2];
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}