#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int num_elements, max_sum;
        cin >> num_elements >> max_sum;
        int sum = 0;
        for (int i = 0; i < num_elements; ++i) {
            int element;
            cin >> element;
            sum += element;
        }
        cout << min(max_sum, sum) << endl;
    }
    return 0;
}
