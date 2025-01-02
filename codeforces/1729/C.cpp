#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin >> s;
        int n = s.size();

        vector<pair<char, int>> o;

        char m = min(s[0], s[n - 1]);
        char x = max(s[0], s[n - 1]);

        for (int i = 0; i < n; i++){
            if ((s[i] >= m && s[i] <= x)){
                o.push_back({s[i], i});
            }
        }

        sort(o.begin(), o.end(), [&](pair<char, int> a, pair<char, int> b)
             { return a.second < b.second; });
        if (o.size() > 2){
            sort(o.begin() + 1, o.end() - 1, [&](pair<char, int> a, pair<char, int> b)
                 {
                if(s[0] > s[n-1]){
                    return a.first > b.first;
                }
                return a.first < b.first; });
        }

        vector<int> se;
        ll m1 = 0;
        se.push_back(1);

        for (int i = 1; i < o.size(); i++){
            m1 += abs(o[i - 1].first - o[i].first);
            se.push_back(o[i].second + 1);
        }

        cout << m1 << " " << se.size() << endl;

        for (auto v : se){
            cout << v << " ";
        }
        cout << endl;
    }
}

	  	 			     	 	 				  			    	