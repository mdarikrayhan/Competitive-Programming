#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> hor,vert;
    set <int> :: iterator it;
    int n,x,y;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> x >> y;
        hor.insert(x);
        vert.insert(y);
    }

    if(hor.size()>vert.size()) cout << vert.size();
        else cout << hor.size();

}
