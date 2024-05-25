#include<bits/stdc++.h>

using namespace std;

char buf[1000043];

string normalize(const string& v)
{
    int cnt = 0;
    while(cnt < v.size() && v[cnt] == '0') cnt++;
    if(cnt == v.size()) return "0";
    return v.substr(cnt, int(v.size()) - cnt);
}

string operator |(const string& a, const string& b)
{
    int sz = max(a.size(), b.size());
    string ans(sz, '0');
    for(int i = 0; i < a.size(); i++)
        if(a[i] == '1') ans[i + sz - int(a.size())] = '1';
    for(int i = 0; i < b.size(); i++)
        if(b[i] == '1') ans[i + sz - int(b.size())] = '1';    
    return normalize(ans);
}

bool better(const string& a, const string& b)
{
    if(a.size() != b.size()) return a.size() > b.size();
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    string s;
    scanf("%s", buf);
    s = buf;
    string ans = s | s;
    int pos1 = s.find("1");
    if(pos1 != string::npos)
    {
        int pos2 = s.find("0", pos1);
        if(pos2 != string::npos)
        {
            int cur = pos1;
            int not_needed = 0;
            while(true)
            {                
                if(cur == n || (s[cur] == '1' && cur > pos2)) break;
                string nw = s | s.substr(pos1, n - pos1 - not_needed);
                if(better(nw, ans)) ans = nw;
                cur++;
                not_needed++;
            }
        }
    }
    puts(ans.c_str());
}