#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    string s;
    vector<char> v;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'd'&&s[i+2]=='r')
        {
            i=i+2;
            v.push_back('@');
            continue;
        }
        if (s[i] == 'q' && s[i + 1] == 'u'&&s[i+2]=='e')
        {
            i=i+2;
            v.push_back('?');
            continue;
        }
        if (s[i] == 'e' && s[i + 1] == 'x')
        {
            i++;
            v.push_back('!');
            continue;
        }
        if (s[i] == 's' && s[i + 1] == 'p')
        {
            i++;
            v.push_back(' ');
            continue;
        }
        if (s[i] == 'f' && s[i + 1] == 's')
        {
            i++;
            v.push_back('.');
            continue;
        }
        if (s[i] == 'c' && s[i + 1] == 'm')
        {
            i++;
            v.push_back(',');
            continue;
        }
        if (s[i] == 'c')
        {
            int num = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
        
            if(num>=27)
            {
                num=s[i+1]-'0';
            }
            if (num < 10)
            {
                i++;
            }
            else
            {
                i += 2;
            }
            num = num + 64;
            char ch = (char)num;
            v.push_back(ch);
            continue;
        }
        if (s[i] == 's')
        {
            int num = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
            if(num>=53)
            {
                num=s[i+1]-'0';
            }
            if (num < 10)
            {
                i++;
            }
            else
            {
                i += 2;
            }
            num = num + 70;
            char ch = (char)num;
            v.push_back(ch);
            continue;
        }
        if(s[i]=='n'&&s[i+1]=='1'){
            int num = stoi(s.substr(i + 2, 2));
            i+=3;
            string str = to_string(num);
            for(int j=0;j<str.size();j++){
                v.push_back(str[j]);
            }
            continue;
        }

    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}