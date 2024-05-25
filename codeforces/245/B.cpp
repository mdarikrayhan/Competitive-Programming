#include <iostream>

using namespace std;

int main()
{
    string s, res;
    cin >> s;
    int curr = 0;
    if (s[0] == 'h') {
        res = "http://";
        curr = 4;
    }
    else {
        res = "ftp://";
        curr = 3;
    }
    int end = curr + 1;
    while (s.substr(end, 2) != "ru")
        end++;
    res += s.substr(curr, end - curr) + ".ru";
    if (end + 2 != s.size())
        res += '/' + s.substr(end + 2, s.size() - end - 2);
    cout << res;
    return 0;
}