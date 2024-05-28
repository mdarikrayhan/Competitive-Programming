#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string x; cin >> x;
    // {R, O, Y, G, B, V}
    vector<int> v(6, 0);
    for (char c: x) {
        if (c == 'R') v[0]++;
        else if (c == 'O') v[1]++;
        else if (c == 'Y') v[2]++;
        else if (c == 'G') v[3]++;
        else if (c == 'B') v[4]++;
        else if (c == 'V') v[5]++;
    }
    sort(v.begin(), v.end());
    string comp = "";
    for (int x: v) comp += to_string(x);
    if (comp == "000006") cout << "1";
    else if (comp == "000015") cout << "1";
    else if (comp == "000024") cout << "2";
    else if (comp == "000114") cout << "2";
    else if (comp == "000033") cout << "2";
    else if (comp == "000123") cout << "3";
    else if (comp == "001113") cout << "5";
    else if (comp == "000222") cout << "6";
    else if (comp == "001122") cout << "8";
    else if (comp == "011112") cout << "15";
    else if (comp == "111111") cout << "30";
}