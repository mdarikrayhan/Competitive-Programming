#include <bits/stdc++.h>

using namespace std;

void USACOIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool set_bit_checker(int num, int n){
    int x = 1;
    x = x << n;
    return ((num & x) == x);
}

int main() {
    //USACOIO("name");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    m++;

    vector<int> players(m);

    for(int i=0;i<m;i++) cin >> players[i];

    int Fedor = players[m-1];
    int friend_counter = 0;

    for(int i=0;i<m-1;i++){
        int and_bit = Fedor & players[i];
        int or_bit = Fedor | players[i];

        int and_bit_counter = 0;
        int or_bit_counter = 0;

        for(int j = 0; j < 20;j++){
            if(set_bit_checker(and_bit,j)) and_bit_counter++;
            if(set_bit_checker(or_bit,j)) or_bit_counter++;
        }

        if(or_bit_counter-and_bit_counter<=k) friend_counter++;
    }

    cout << friend_counter;

}
