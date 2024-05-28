#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k, n, m, q, u;
    string x, l;
    cin >> k >> n >> m >> q;
    map <string, int> a;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x] = i;
    }
    map <string, vector <int> > art;
    string s, name;
    getline(cin, s);
    for (int i = 0; i < m; i++){
        vector <int> b(n);
        getline(cin, s);
        u = s.find(" ");
        name = s.substr(0, u - 1);
        s.erase(0, u + 1);
        while (s.size() > 0){
            u = s.find(" ");
            x = s.substr(0, u);
            s.erase(0, u + 1);
            u = s.find(" ");
            if (u == string::npos){
                l = s;
                s = "";
            }
            else{
                l = s.substr(0, u);
                s.erase(0, u + 1);
                l.erase(l.size() - 1);
            }
            b[a[x]] = stoi(l);
        }
        art[name] = b;
    }
    vector <vector <int> > c(k, vector <int> (n, 0));
    vector <map <string, int> > f(k);
    for (int i = 0; i < q; i++){
        cin >> u >> x;
        u--;
        c[u][a[x]]++;
        for (auto& item : art){
            int g = 0;
            for (int j = 0; j < n; j++){
                if (item.second[j] > c[u][j]){
                    g = 1;
                    break;
                }
            }
            if (g == 0){
                for (int j = 0; j < n; j++){
                    c[u][j] -= item.second[j];
                }
                f[u][item.first]++;
                break;
            }
        }
    }
    vector <pair <string, int> > ans;
    for (int i = 0; i < k; i++){
        ans.clear();
        for (auto& item : f[i]){
            ans.push_back(item);
        }
        for (auto& item : a){
            if (c[i][item.second] > 0){
                ans.push_back(make_pair(item.first, c[i][item.second]));
            }
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (auto j : ans){
            cout << j.first << " " << j.second << endl;
        }
    }
}