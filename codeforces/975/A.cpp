#include <iostream>
#include <vector>
# include <algorithm>
#include<set>
using namespace std;
int main() {
    int s;
    cin >> s;
    set<string>sh;
    while (s--) {
        string h;
        cin >> h;
        sort(h.begin(), h.end());
        h.erase(unique(h.begin(), h.end()), h.end());
        sh.insert(h);
    }
    cout << sh.size();
    return 0;
}