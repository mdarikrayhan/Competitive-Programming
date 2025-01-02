#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 505;

int num_vertices;
int adjacency[MAX_N][MAX_N];
long long total_ways[MAX_N][MAX_N]; 
long long direct_ways[MAX_N][MAX_N]; 

int main() {
    cin >> num_vertices;
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            cin >> adjacency[i][j];
        }
    }
    for (int i = 0; i < num_vertices; ++i) {
        total_ways[i][i] = direct_ways[i][i] = 1;
    }
    for (int i = 1; i < num_vertices; ++i) {
        for (int start = 0, end = i; start < num_vertices; ++start, end = (end + 1) % num_vertices) {
            if (adjacency[start][end]) {
                for (int k = start; k != end; k = (k + 1) % num_vertices) {
                    direct_ways[start][end] += total_ways[start][k] * total_ways[(k + 1) % num_vertices][end] % MOD;
                    direct_ways[start][end] %= MOD;
                }
            }
            for (int k = start; k != end; k = (k + 1) % num_vertices) {
                total_ways[start][end] += direct_ways[start][(k + 1) % num_vertices] * total_ways[(k + 1) % num_vertices][end] % MOD;
                total_ways[start][end] %= MOD;
            }
        }
    }
    cout << total_ways[0][num_vertices - 1] << endl;
    return 0;
}
 		 		  	 		 			  		 	    			 	