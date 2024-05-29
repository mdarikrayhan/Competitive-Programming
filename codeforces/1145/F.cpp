// LUOGU_RID: 157214370
#include<bits/stdc++.h>
using namespace std;
bool biao[26]={1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1};
int main(){
    string s;cin >> s;
    int cnt = 0;
    for (int i=0;i<s.length();i++)cnt += biao[s[i] - 'A'];
    if (cnt == 0 || cnt == s.length())cout <<"YES";
    else cout <<"NO";
    return 0;
}