    #include <iostream>
    #include <vector>
    #include <algorithm>
     
    using namespace std; typedef long long ll;
     
    int main()
    {
        int n, ans = 0; cin >> n; ll maxi;
        vector <pair<ll, ll>> A(n);
     
        for (int i = 0; i < n; i++) { cin >> A[i].first >> A[i].second; }
        sort(A.begin(), A.end());
     
        maxi = A[0].second;
        for (int i = 1; i < n; i++) {
            if (A[i].second < maxi) { ans++; }
            else { maxi = A[i].second; }
        }
     
        cout << ans;
    }