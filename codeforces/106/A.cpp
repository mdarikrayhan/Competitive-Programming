#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char rank[] = {'6', '7', '8', '9', 'T','J', 'Q', 'K' ,'A'};
    int len = sizeof(rank) / sizeof(rank[0]);

    char c;cin>>c;
    string s1,s2;cin>>s1>>s2;

    if(s1[1] == c && s2[1] != c) {
        cout<<"YES"<<endl;
    }
    else if(s1[1] != c && s2[1] == c) {
        cout<<"NO"<<endl;
    }

    else if(s1[1] == s2[1]) {
        int x=0,y=0;
        for(int i =0;i< len; i++) {
            if(s1[0] == rank[i]) {
                x = i;
            }
            if(s2[0] == rank[i]) {
                y = i;
            }
        }
        if(x>=y) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}