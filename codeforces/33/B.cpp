#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 1e9; 
const int ALPHABET_SIZE = 26;

void floydWarshall(vector<vector<int>>& graph) {
    for (int k = 0; k < ALPHABET_SIZE; ++k) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << -1 << endl;
        return 0;
    }

    int n;
    cin >> n;

    vector<vector<int>> graph(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE, INF));

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        graph[a - 'a'][b - 'a'] = min(graph[a - 'a'][b - 'a'], w);
    }

    floydWarshall(graph);

    int totalgraph = 0;
    string result = s;

    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            int mingraph = INF;
            char bestChar = s[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                int currentgraph = graph[s[i] - 'a'][c - 'a'] + graph[t[i] - 'a'][c - 'a'];
                if (currentgraph < mingraph) {
                    mingraph = currentgraph;
                    bestChar = c;
                }
            }
            if (mingraph == INF) {
                cout << -1 << endl;
                return 0;
            }
            totalgraph += mingraph;
            result[i] = bestChar;
        }
    }

    cout << totalgraph << endl;
    cout << result << endl;

    return 0;
}

  	  		   	  			 		 		     	 		