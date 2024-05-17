#include <bits/stdc++.h>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

i64 Gauss(i64 n){
    return (n * (n + 1)) / 2;
}

int bs(i64 ini, i64 fin, i64 busca){
    if(ini == fin)
        return ini - 1;
    i64 mid = (ini + fin) / 2;
    if(Gauss(mid - 1) <= busca)
        return bs(mid + 1, fin, busca);
    return bs(ini, mid, busca);
}

int main(){
    opti_io;

    i64 n, m;
    cin >> n >> m;

    i64 mini, maxi;

    if(m == 0){
        cout << n << " " << n << '\n';
        return 0;
    }

    mini = max((i64)0, n - 2 * m);

    i64 complete = bs(0, n + 1, m);
    maxi = ((m - Gauss(complete - 1) == 0) ? n - complete : n - complete - 1);

    cout << mini << " " << maxi << '\n';
    return 0;
}