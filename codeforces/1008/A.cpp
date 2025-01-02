#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool flag = false;
    if (s.length() == 1){
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'n'){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i + 1 < s.length())
            {
                if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'n'))
                {
                    if (!(s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u'))
                    {
                        flag = true;
                        break;
                    }
                }
            }
            else{
                if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'n')){
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
// s input nibo. flag variable niye nibo. s er length 1 hole check dibo sheta vowel or n hole YES print korbo r na hole NO print korbo
// s er length 1 na hole akta loop chalabo s er length porjonto. i+1 s er length theke choto hole ith index n baade onno consonant hole check dibo i+1th index vowel na hole flag true kore break kore dibo
// i+1 s er length theke choto na hole check dibo ith index n baad e onno consonant hole flag true kore break kore dibo
// loop sesh e flag true hole NO print korbo r na hole YES print korbo 