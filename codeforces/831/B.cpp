#include <iostream>
#include<algorithm>
using namespace std;

int findindex(char ch,string str){
    for(int i=0;i<str.size();i++){
        if(str[i] == ch){
            //cout << str[i] << " " << i << " " << ch << endl;
            return i;
        }
    }
    return -1;
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            cout << s2[findindex(s[i],s1)];
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){  
            cout << char(s2[findindex(char(s[i]+32),s1)] - 32);
        }
        else{
            cout << s[i];
        }
    }

    return 0;
}