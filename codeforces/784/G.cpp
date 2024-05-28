#include <bits/stdc++.h>

using namespace std;

signed main() {
    string in;
    cin >> in;

    int res = 0;
    int iter = 0;
    bool op = true;


    while (iter < in.size()){
        int current = 0;
        while (iter < in.size() && in[iter] != '+' && in[iter] != '-'){
            current *= 10;
            current += in[iter] - '0';
            iter ++;
        }
        res += current * (op ? 1 : -1);
        op = in[iter] == '+';
        iter ++;
    }

    string a = to_string(res);
    for (auto ele : a){
        for (int i = 0; i < ele-'0'+48; i ++){
            cout << "+";
        }
        cout << ".>" << endl;
    }
}