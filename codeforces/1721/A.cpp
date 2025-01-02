#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        set<char> st;
        st.insert(a[0]);
        st.insert(a[1]);
        st.insert(b[0]);
        st.insert(b[1]);
        cout << st.size() - 1 << endl;
    }
}