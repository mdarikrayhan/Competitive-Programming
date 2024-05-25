#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <bool> wasstr(n, false);
    vector <bool> wasstb(n, false);
    vector <int> strans(n, 0);
    vector <int> stbans(n, 0);
    for (int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j){
			if (s[j] == '.'){
				wasstr[i] = true;
				wasstb[j] = true;
				strans[i] = j;
				stbans[j] = i;
			}
		}
    }
    bool caninstr = true, caninstb = true;
    for (int i = 0; i < n; ++i){
		if (wasstr[i] == false){
			caninstr = false;
		}
		if (wasstb[i] == false){
			caninstb = false;
		}
    }
    if (caninstr == false && caninstb == false){
		cout << -1;
    }
    else if (caninstr == true){
		for (int i = 0; i < n; ++i){
			cout << i + 1 << " " << strans[i] + 1 << '\n';
		}
    }
    else{
		for (int i = 0; i < n; ++i){
			cout << stbans[i] + 1 << " " << i + 1 << '\n';
		}
    }
    return 0;
}