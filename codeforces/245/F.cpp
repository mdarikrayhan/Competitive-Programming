#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200200];
long long f[] ={0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

long long convert(string a, string b) {
    int month = (a[5] - '0') * 10 + (a[6] - '0');
    int day = (a[8] - '0') * 10 + a[9] - '0';
    long long t = (((b[0] - '0') * 10 + b[1] - '0') * 60 + (b[3] - '0') * 10 + b[4] - '0');
    t *= 60;
    t += (b[6] - '0') * 10 + b[7] - '0';

    return t + (f[month-1] + day - 1) * 24 * 60 * 60;
}
int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> n >> m;
    deque<int> dq;
    string f = "2012-03-16 16:15:25";
    while(getline(cin, s)) {
        s += ' ';
        s[f.size()] = ' ';
        stringstream ss(s);
        string a, b;
        ss >> a >> b;
        long long t = convert(a, b);
        while (dq.size() > 0 && t - dq.front() >= n) {
            dq.pop_front();
        }
        dq.push_back(t);
        if(dq.size() >= m) {
            cout << a << " " << b << "\n";
            return 0;
        }
    }
    cout << -1;
}
