#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    stringstream stream(input);
    string segment;
    vector<string> words;

    while (getline(stream, segment, ',')) {
        words.push_back(segment);
    }
    int curDepth = 0;
    vector<vector<string> > depths;
    int maxDepth = 0;
    stack<pair<int, int> > parent;
    for (int i = 0; i < words.size(); i++) {
        string comment = words[i];
        i++;
        long long children = stoll(words[i]);
        while(!parent.empty() && parent.top().second == 0){
            parent.pop();
        }
        if (parent.empty()) {
            curDepth = 0;
        } else {
            pair<int, int> topVal = parent.top();
            parent.pop();
            parent.push({topVal.first, topVal.second - 1});
            curDepth = topVal.first + 1;
            maxDepth = max(curDepth, maxDepth);
        }
        if (depths.size() <= curDepth) {
            depths.push_back({comment});
        } else {
            depths[curDepth].push_back(comment);
        }
        //cout << curDepth << " " << words[i-1] << endl;
        parent.push({curDepth, children});
    }
    cout << maxDepth+1 << endl;
    for (int i = 0; i <= maxDepth; i++) {
        if (depths[i].size()) {
            cout << depths[i][0];
            for (int j = 1; j < depths[i].size(); j++) {
                cout << " " << depths[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}