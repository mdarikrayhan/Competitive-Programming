#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin >> s;
int n = s.size();
for(int i=0;i<n;i++){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'
    || s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'
    ||s[i]=='U'||s[i]=='Y'){
        
    }
    else{
        int x= s[i];
        cout <<"." << (char)tolower(x);
    }
}
return 0;
}