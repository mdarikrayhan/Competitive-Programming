#include<bits/stdc++.h>

using namespace std;

int main(){
    string n,x,ans = "";cin >> n >> x;
    sort(n.begin(),n.end());
    if (n[0] != '0') {
        if (n == x)cout << "OK";
        else cout << "WRONG_ANSWER";
    }
    else {
        if (n == "0")ans = "0";
        else {
            int i = 0,j = 0;
            for (i = 0;i < n.size();i++)if (n[i] != '0')break;
            ans += n[i];
            for (j = 0;j < i;j++)ans += n[j];
            for (j = i+1;j < n.size();j++)ans += n[j];
        }
        if (ans == x)cout << "OK";
        else cout << "WRONG_ANSWER";
    }
    return 0;
}
