#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n;
    int arr[2000];

    cin >> t;
    while (t--) {
        int x;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[2*i];
            cin>>arr[2*i + 1];
        }
        sort(arr, arr+2*n, greater<int>());

        int flag = 1;
        int hi[2000];
        for (int i = 1; i < 2*n; i++) {

        multiset<int> st;
        
            for (int j = 1; j < 2*n; j++) {
                if (j != i)
                st.insert(arr[j]);
            }
            hi[0] = arr[i];
            hi[1] = arr[0];
            x = arr[0];

            for (int k = 1; k < n; k++) {
                auto it = st.find(x - *st.rbegin());
                if (it == st.end() || it ==--st.end()) {
                    flag = 0;
                    break;
                }
                else {
                    
                    hi[2*k] = *it;
                    st.erase(it);
                    x = *st.rbegin();
                    hi[2*k+1] = x;
                    it = st.end();
                    it--;
                    st.erase(it);
                }
                flag = 1;
            }
            if (flag) break;
        }
        if (flag) {
            cout << "YES" << endl;
            cout << hi[0] + hi[1] << endl;
            for (int i = 0; i < n; i++) {
                cout << hi[2*i] << ' ' << hi[2*i+1] << endl;
            }
        } else {
            cout << "NO" << endl;
        }
        
    }
    
    
    return 0;
}
