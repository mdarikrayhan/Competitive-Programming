#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mezclarLetras(string& s1, string& s2, int& res, vector<int>& swapS1, vector<int>& swapS2) {
    vector<int> ab;
    vector<int> ba;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == 'a') {
                ab.push_back(i+1);
            } else {
                ba.push_back(i+1);
            }
        }
    }
    if ((ab.size() + ba.size()) % 2 != 0) {
        res = -1;
    } else {
        if (ab.size() % 2 == 1) {
            res = ab.size() / 2 + ba.size() / 2 + 2;
            swapS1.push_back(ab[0]);
            swapS2.push_back(ab[0]);
            swapS1.push_back(ab[0]);
            swapS2.push_back(ba[0]);
            for (int i = 1; i < ab.size(); i = i + 2) {
                swapS1.push_back(ab[i]);
                swapS2.push_back(ab[i+1]);
            }
            for (int i = 1; i < ba.size(); i = i + 2) {
                swapS1.push_back(ba[i]);
                swapS2.push_back(ba[i+1]);
            }
        } else {
            res = (ab.size() + ba.size())/2;
            for (int i = 0; i < ab.size(); i = i + 2) {
                swapS1.push_back(ab[i]);
                swapS2.push_back(ab[i+1]);
            }
            for (int i = 0; i < ba.size(); i = i + 2) {
                swapS1.push_back(ba[i]);
                swapS2.push_back(ba[i+1]);
            }
        }
    }
}

int main() {
    int n;
    string s1;
    string s2;
    cin >> n;
    cin >> s1;
    cin >> s2;
    int res = 0;
    vector<int> swapS1;
    vector<int> swapS2;
    mezclarLetras(s1, s2, res, swapS1, swapS2);
    if (res == -1) {
        cout << res << endl;
    } else {
        cout << res << endl;
        for (int i = 0; i < swapS1.size(); i++) {
            cout << swapS1[i] << " " << swapS2[i] << endl;
        }
    }
}
 				  						   		 	 							 		