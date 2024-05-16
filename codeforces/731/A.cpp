#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string str;
    cin>>str;
    char initialPos = 'a';

    int sum = 0;
    for(int i=0; i<str.size(); i++){
        sum+=min(abs(initialPos - str[i]), 26 - (abs(str[i] - initialPos)));
        initialPos = str[i];
    }
    cout << sum << endl;
    return 0;
}